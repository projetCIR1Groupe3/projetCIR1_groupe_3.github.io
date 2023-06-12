var currentPage = 1;

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
    return readFileByName("../../support_files_2023/BD_medium.txt");
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

    let i = 50*currentPage;

    for (i; i < 50 + 50*currentPage; i++) {                 //Parcourt tous les éléments du tableau -1
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

function writeFile(id_form,func) {

    var element = document.createElement('a');

    let text1 = document.getElementById(id_form);
    let count = text1.elements.length;
    let textToSave = func;
    for(let i = 0;i<count-1;i++){
        textToSave += ";" + text1[i].value;
    }   

    element.setAttribute('href', 'data:text/plain;charset=utf-8,' + encodeURIComponent(textToSave));
    element.setAttribute('download', 'request.txt');

    element.style.display = 'none';
    document.body.appendChild(element);
    element.click();
    document.body.removeChild(element);

   text1.submit();
}

function requestFilter(){
    const filterReal = document.querySelector("#recherche_real.active");
    const filterDuree = document.querySelector("#recherche_duree.active");
    if(filterReal){;
        writeFile("div-recherche", "realisateur");
    }
    else {
        if(filterDuree){
            writeFile("div-recherche", "duree");
        }
        else{
            alert("Veuillez choisir un filtre")
        }
    }
}

function nextPage(){
    delMoviePage();
    if(currentPage >= 999){
        alert("Vous ne pouvez pas allez plus loin")
    }
    else{
        currentPage+=1;
    }
}

function lastPage(){
    delMoviePage();
    currentPage=999;
}

function previousPage(){
    delMoviePage();
    if(currentPage <= 0){
        alert("Vous ne pouvez pas allez plus loin")
    }
    else{
        currentPage-=1;
    }
}

function firstPage(){
    delMoviePage();
    currentPage=0;
}

function delMoviePage(){
    document.querySelector(".grid").innerHTML = "";
}

function stylePagination(){
    
    document.getElementById("actualPage").innerHTML = currentPage;

    if(currentPage==0){
        document.getElementById("actualPage").innerHTML = currentPage;
        document.getElementById("firstPage").classList.toggle("paginationActive");
        document.getElementById("lastPage").classList.remove("paginationActive");
    }
    else if(currentPage==999){
        document.getElementById("lastPage").classList.toggle("paginationActive");
        document.getElementById("firstPage").classList.remove("paginationActive");
    }
    else{
        document.getElementById("firstPage").classList.remove("paginationActive");
        document.getElementById("lastPage").classList.remove("paginationActive");
    }
    
}

main();