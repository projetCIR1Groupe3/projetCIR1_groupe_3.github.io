var currentPage = 0;
var nb_movies;
var nb_page;

var RequestCurrentPage = 0;
var RequestNb_Movies;
var RequestNb_Page;

function main(){
    document.addEventListener("DOMContentLoaded", function(event) {
        
        const tableauBoutonRecherche = document.querySelectorAll(".recherche-boutton");        
        
        tableauBoutonRecherche.forEach(function(boutonRecherche){               //Pour chaque élément du tableauBoutonRecherche on fait :
            boutonRecherche.addEventListener("click", function(event){          //A la détection d'un clic on fait :
                resetFilters();                                                 
                event.currentTarget.classList.toggle("active");                 //On active la classe CSS sur ce bouton
            });  
        });
        
        
        myResults = readFile();                        //Effectue cette fonction lorsque le DOM est chargé

        
        if(myResults == 404){ 
            allMovie('all','AllMovies');
        }
        
        else{
            RequestresizeBDD();
            appendResult();
        }
        
        stylePagination();
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
    do {                                                  
        xhr.open("GET", fileName, false);
        xhr.send(null);
    } while (xhr.status === 404) {
        
    }
    return xhr.responseText;
}

function csvToArray(data) {     //Fonction prenant "data", une chaine de caractere en CSV
    const lines = data.split('\n');
    if(lines[1] == "NULL"){
        return "NULL";
    }                         //Crée un tableau à chaque ligne
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

    myResults = readFile();

    if(myResults != 404){

        const movies = csvToArray(readFile());      //On récupere notre BDD sous forme de tableau
        const gridMovie = document.querySelector(".grid");  

        let i = 50*currentPage;
        if(movies == "NULL"){
            gridMovie.innerHTML = "<h3>Votre recherche n'a mené à rien</h3>";
            return ;
        }
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

function allMovie(id_form,func) {
    writeFile(id_form, func);
    resetFilters();
}

function searchFilter(){

    let size = document.querySelector(".searchbar").value.length;
    let txt = document.querySelector(".searchbar").value

    if(document.querySelector("#recherche_real.active")){
        for(let i=0;i<size;i++){
            if(txt[i] != "a" && txt[i] != "b" && txt[i] != "c" && txt[i] != "d" && txt[i] != "e" && txt[i] != "f" && txt[i] != "g" && txt[i] != "h" && txt[i] != "i" && txt[i] != "j" 
            && txt[i] != "k" && txt[i] != "l" && txt[i] != "m" && txt[i] != "n" && txt[i] != "o" && txt[i] != "p" && txt[i] != "q" && txt[i] != "r" && txt[i] != "s" && txt[i] != "t" 
            && txt[i] != "u" && txt[i] != "v" && txt[i] != "w" && txt[i] != "x" && txt[i] != "y" && txt[i] != "z" && txt[i] != "-" && txt[i] != "'" && txt[i] != "A" && txt[i] != "B" 
            && txt[i] != "C" && txt[i] != "D" && txt[i] != "E" && txt[i] != "F" && txt[i] != "G" && txt[i] != "H" && txt[i] != "I" && txt[i] != "J" && txt[i] != "K" && txt[i] != "L" 
            && txt[i] != "M" && txt[i] != "N" && txt[i] != "O" && txt[i] != "P" && txt[i] != "Q" && txt[i] != "R" && txt[i] != "S" && txt[i] != "T" && txt[i] != "U" && txt[i] != "V" 
            && txt[i] != "W" && txt[i] != "X" && txt[i] != "Y" && txt[i] != "Z"){   //Vérifie si le filtre réalisateur est respecté
                alert("Veuillez faire une recherche cohérente avec votre filtre")   //Si non alert demandant de respecter le filtre
                return;
            }
            else{
                writeFile("div-recherche", "realisateur");                  //Si oui, on écrit le fichier
                return;
            }
        }
    }
    else if(document.querySelector("#recherche_duree.active")){     //Pareil pour durée
        for(let i=0;i<size;i++){
            if(txt[i] != "1" && txt[i] != "2" && txt[i] != "3" && txt[i] != "4" && txt[i] != "5" && txt[i] != "6" && txt[i] != "7" && txt[i] != "8" && txt[i] != "9"){
                alert("Veuillez faire une recherche cohérente avec votre filtre")
                return;
            }
            else{
                writeFile("div-recherche", "duree");
                return;
            }
        }
    }
    else{
        alert("Veuillez selectionner un filtre");
    }

}

function nextPage(){

        myResults = readFile();

        if(myResults == 404){
    
            delMoviePage();
            if(currentPage >= nb_page-1){
                alert("Vous ne pouvez pas allez plus loin")
            }
            else{
                currentPage+=1;
            }
    
        }
    
        else{
            
            delMoviePage();
            if(RequestCurrentPage >= RequestNb_Page-1){
                alert("Vous ne pouvez pas allez plus loin") //On met une alerte si l'utilisateur est déjà à la dernière page
            }
            else{
                RequestCurrentPage+=1;  //Sinon, il incrémente CurrentPage
            }
    
        }

}

function lastPage(){            //Envoie l'utilisateur à la dernière page

    myResults = readFile();

    delMoviePage();
    if(myResults == 404){
        currentPage=nb_page-1;
    }
    else{
        RequestCurrentPage=RequestNb_Page-1;
    }

}

function previousPage(){

    myResults = readFile();

    if(myResults == 404){

        delMoviePage();
        if(currentPage <= 0){
            alert("Vous ne pouvez pas allez plus loin") 
        }
        else{
            currentPage-=1;             
        }

    }

    else{
        
        delMoviePage();
        if(RequestCurrentPage <= 0){
            alert("Vous ne pouvez pas allez plus loin") //On met une alert si l'utilisateur est déjà à la première page
        }
        else{
            RequestCurrentPage-=1;      //Sinon, on décremente currentPage
        }

    }

    
}

function firstPage(){           //Envoie l'utilisateur à la première page

    myResults = readFile();

    delMoviePage();
    if(myResults == 404){
        currentPage=0;
    }
    else{
        RequestCurrentPage=0;
    }
}

function delMoviePage(){
    document.querySelector(".grid").innerHTML = "";     //Supprime tous les films
}

function stylePagination(){     

    myResults = readFile();

    if(myResults == 404){

        document.getElementById("actualPage").innerHTML = currentPage+1;

        if(currentPage==0){
            document.getElementById("actualPage").innerHTML = currentPage+1;
            document.getElementById("firstPage").classList.toggle("paginationActive");
            document.getElementById("lastPage").classList.remove("paginationActive");
        }
        else if(currentPage==nb_page-1){
            document.getElementById("lastPage").classList.toggle("paginationActive");
            document.getElementById("firstPage").classList.remove("paginationActive");
        }
        else{
            document.getElementById("firstPage").classList.remove("paginationActive");
            document.getElementById("lastPage").classList.remove("paginationActive");
        }

    }

    else{

        document.getElementById("actualPage").innerHTML = RequestCurrentPage+1;     //Modifie afin d'afficher la page actuelle

        if(RequestCurrentPage==0){
            document.getElementById("actualPage").innerHTML = RequestCurrentPage+1;
            document.getElementById("firstPage").classList.toggle("paginationActive");  //Active la classe paginationActive à l'id firstPage
            document.getElementById("lastPage").classList.remove("paginationActive");   //Désactive la classe paginationActive à lastPage
        }
        else if(RequestCurrentPage==RequestNb_Page){
            document.getElementById("lastPage").classList.toggle("paginationActive");   //Active la classe paginationActive à l'id lastPage
            document.getElementById("firstPage").classList.remove("paginationActive");  //Désactive la classe paginationActive à firstPage
        }
        else{
            document.getElementById("firstPage").classList.remove("paginationActive");  //Désactive la classe paginationActive à firstPage
            document.getElementById("lastPage").classList.remove("paginationActive");   //Et à firstPage
        }

    }

}

function resizeBDD(){
    const movies = csvToArray(readFile());

    nb_movies = 0;

    movies.forEach(movie => {                       //Calcule le nombre de films
        nb_movies+=1;
    })

    nb_page = Math.round(nb_movies / 50)            //Déduit le nombre de page nécessaire

    document.getElementById("lastPage").innerHTML = nb_page;            //Modifie lastPage en fonction du nb de page nécessaire

}

function appendResult(){
    myResults = readFile();

    if(myResults != 404){

        const movies = RequestcsvToArray(readFile());      //On récupere notre BDD sous forme de tableau

        document.getElementById("showTime").innerHTML = execTime;
        
        const gridMovie = document.querySelector(".grid");  

        let i = 50*RequestCurrentPage;
        
        for (i; i < 50 + 50*RequestCurrentPage; i++) {                 //Parcourt tous les éléments du tableau -1

            const movie = movies[i];
            const movieElement = document.createElement("div");     //On crée une balise <div>
            movieElement.classList.add("film");                     //A laquelle on ajoute la class "film"
        
            const movieTitle = document.createElement("h4");        //On crée une balise <h4>
            movieTitle.innerText = movie.titre;                     //A laquelle on ajoute le titre tu film (grâce a la clé titre)
        
            const movieReal = document.createElement("p");          //On crée une balise <p>
            movieReal.innerText = movie.realisateur;                //A laquelle on ajoute le nom du réalisateur
        
            const movieDuree = document.createElement("p");         //On crée une balise <p>
            if(movie.duree % 60 <10){
                movieDuree.innerText = Math.floor(movie.duree / 60) + "h" + "0" + movie.duree % 60; 
            }                                    
            else{
                movieDuree.innerText = Math.floor(movie.duree / 60) + "h" + movie.duree % 60;       //A laquelle on ajoute la durée du film (en heure)
            }
        
            const movieGenre = document.createElement("p");         //On crée une balise <p>
            movieGenre.innerText = movie.genre;                     //A laquelle on ajoute le genre du film
        
            movieElement.appendChild(movieTitle);                   //On ajoute titre, réalisateur, durée et genre à notre div movieElement
            movieElement.appendChild(movieReal);
            movieElement.appendChild(movieDuree);
            movieElement.appendChild(movieGenre);
        
            gridMovie.appendChild(movieElement);                    //On append notre div movieElement à notre grid

        }
    }

}

function RequestcsvToArray(data) {     //Fonction prenant "data", une chaine de caractere en CSV
    const lines = data.split('\n');                         //Crée un tableau à chaque ligne

    execTime = lines[0]

    lines.shift();
    const keys = ['realisateur', 'titre', 'duree', 'genre'];        //Avec les clés réalisateur,titre,durée et genre

    return lines.map(line => {     
        if(line != ""){
            const values = line.split(';');                               //On sépare chaque élément à ";"
            return values.reduce((obj, value, index) => {
            obj[keys[index]] = value;           //Chaque petit tableau de notre gros tableau est modifié (on ajoute nom du film etc)
            return obj;             //On return notre petit tableau
        }, {});
        }                                 //On parcourt chaque ligne du tableau
        

    });

    

}



function readFile(){
    readFileByName("ready.txt")
    return readFileByName("resultat.txt");
}

function RequestresizeBDD(){
    const movies = RequestcsvToArray(readFile());

    RequestNb_Movies = 0;

    movies.forEach(movie => {
        RequestNb_Movies+=1;            //Calcule le nombre de films
    })

    console.log(RequestNb_Movies)

    RequestNb_Page = Math.ceil(RequestNb_Movies / 50)           //Déduit le nombre de page nécessaire
    console.log(RequestNb_Page)

    document.getElementById("lastPage").innerHTML = RequestNb_Page;         //Modifie lastPage en fonction du nb de page nécessaire

}

function showBiggestReal(){

    myResults = readFile();                        

        if(myResults == 404){ 
            showBiggestReal();
        }
        else{
            const lines = myResults.split('\n');          //On split les deux lignes

            execTime = lines[0];                          //Le temps d'exécution est égal à la première ligne
            document.getElementById("showTime").innerHTML = execTime;     //On modifie pour afficher le temps d'exécution

            const txt = lines[1].split(';');        //On split la deuxième ligne au ;
            let directeur = txt[0];                 //Le directeur est égal à l'élément 0 de la deuxième ligne
            let nb_film = txt[1];                   //Le nb de film est égal à l'élément 1 de la deuxième ligne

            alert("Le plus gros réalisateur est " + directeur + ", il a réalisé " + nb_film + " films.");   //On fait une alert qui affiche nos résultats
        }

}

main();