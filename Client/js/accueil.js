function main(){
    document.addEventListener("DOMContentLoaded", function(event) {                         //Effectue cette fonction lorsque le DOM est chargé
        appendMovie();

        const tableauBoutonRecherche = document.querySelectorAll(".recherche-boutton");        
        
        tableauBoutonRecherche.forEach(function(boutonRecherche){               //Pour chaque élément du tableauBoutonRecherche on fait :
            boutonRecherche.addEventListener("click", function(event){          //A la détection d'un clic on fait :
                resetFilters();                                                 
                event.currentTarget.classList.toggle("active");                 //On active la classe CSS sur ce bouton
            });  
        });
    })
}

function resetFilters() {               //Cette fonction sert à réinisialiter le style des boutons "recherche réalisateur/durée" s'ils sont actifs
    document.querySelectorAll(".recherche-boutton.active").forEach(function(b){
        b.classList.remove("active");
    });
}

function search(){
    const filters = []
    const filterReal = document.querySelector("#recherche_real.active");
    const filterDuree = document.querySelector("#recherche_duree.active");

    if(filterReal){                     //Si recherche_real est active
        filters.push("realisateur");    //On le met dans notre tableau
    }   
    if(filterDuree){                    //Si recherche_duree est active
        filters.push("duree")           //On le met dans notre tableau
    }

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
    return readFileByName("../../support_files_2023/BD_small.txt");
}

function csvToArray(data) {     //Fonction prenant "data", une chaine de caractere en CSV
    const lines = data.split('\n');                         //Crée un tableau à chaque ligne
    const keys = ['realisateur', 'titre', 'duree', 'genre'];        //Avec les clés réalisateur,titre,durée et genre
  
    return lines.map(line => {                                      //On parcourt chaque ligne du tableau
      const values = line.split(';');                               //On sépare chaque élément à ";"
      return values.reduce((obj, value, index) => {
        obj[keys[index]] = value;           //Chaque petit tableau de notre gros tableau est modifié (on ajoute nom du film etc)
        return obj;             //On return notre petit tableau
      }, {});
    });
  }

  function appendMovie() {
    const movies = csvToArray(readFile());      //On récupere notre BDD sous forme de tableau

    const gridMovie = document.querySelector(".grid");      

    for (let i = 0; i < movies.length-1; i++) {                 //Parcourt tous les éléments du tableau -1
        const movie = movies[i];
      
        const movieElement = document.createElement("div");     //On crée une balise <div>
        movieElement.classList.add("film");                     //A laquelle on ajoute la class "film"
      
        const movieTitle = document.createElement("h4");        //On crée une balise <h4>
        movieTitle.innerText = movie.titre;                     //A laquelle on ajoute le titre tu film (grâce a la clé titre)
      
        const movieReal = document.createElement("p");          //On crée une balise <p>
        movieReal.innerText = movie.realisateur;                //A laquelle on ajoute le nom du réalisateur
      
        const movieDuree = document.createElement("p");                                     //On crée une balise <p>
        movieDuree.innerText = Math.floor(movie.duree / 60) + "h" + movie.duree % 60;       //A laquelle on ajoute la durée du film (en heure)
      
        const movieGenre = document.createElement("p");         //On crée une balise <p>
        movieGenre.innerText = movie.genre;                     //A laquelle on ajoute le genre du film
      
        movieElement.appendChild(movieTitle);                   //On ajoute titre, réalisateur, durée et genre à notre div movieElement
        movieElement.appendChild(movieReal);
        movieElement.appendChild(movieDuree);
        movieElement.appendChild(movieGenre);
    
        gridMovie.appendChild(movieElement);                    //On append notre div movieElement à notre grid
    
      }
  }

main();