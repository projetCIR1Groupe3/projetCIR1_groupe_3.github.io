function main(){
    document.addEventListener("DOMContentLoaded", function(event) {
        appendMovie();

        const tableauBoutonRecherche = document.querySelectorAll(".recherche-boutton");        
        
        tableauBoutonRecherche.forEach(function(boutonRecherche){
            boutonRecherche.addEventListener("click", function(event){
                resetFilters();
                event.currentTarget.classList.toggle("active");
            });  
        });
    })
}

function resetFilters() {
    document.querySelectorAll(".recherche-boutton.active").forEach(function(b){
        b.classList.remove("active");
    });
}

function search(){
    const filters = []
    const filterReal = document.querySelector("#recherche_real.active");
    const filterDuree = document.querySelector("#recherche_duree.active");

    if(filterReal) filters.push("realisateur");
    if(filterDuree) filters.push("duree");

    console.log(filters)
}

function readFileByName(fileName){

    let xhr = new XMLHttpRequest();

    try {                                                   // Remettre version du prof (enlever try, catch) lorsque le C aura été adapté
        xhr.open("GET", fileName, false);
        xhr.send(null);
    } catch (error) {
        console.log(error)
    }

    return xhr.responseText;
}

function readFile(){
    return readFileByName("/support_files_2023/BD_small.txt");
}

function csvToArray(data) {
    const lines = data.split('\n');
    const keys = ['realisateur', 'titre', 'duree', 'genre'];
  
    return lines.map(line => {
      const values = line.split(';');
      return values.reduce((obj, value, index) => {
        obj[keys[index]] = value;
        return obj;
      }, {});
    });
  }

  function appendMovie() {
    const movies = csvToArray(readFile());

    const gridMovie = document.querySelector(".grid");

    movies.forEach(movie => {
        const movieElement = document.createElement("div");
        movieElement.classList.add("film");

        const movieTitle = document.createElement("h4");
        movieTitle.innerText = movie.titre;

        const movieReal = document.createElement("p");
        movieReal.innerText = movie.realisateur;

        const movieDuree = document.createElement("p");
        movieDuree.innerText = Math.floor(movie.duree/60) + "h" + movie.duree%60;

        const movieGenre = document.createElement("p");
        movieGenre.innerText = movie.genre;

        movieElement.appendChild(movieTitle);
        movieElement.appendChild(movieReal);
        movieElement.appendChild(movieDuree);
        movieElement.appendChild(movieGenre);

        gridMovie.appendChild(movieElement);
    });
  }
  


main();