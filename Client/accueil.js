function main(){
    
}

let counter=0

function resetSurbrillance(){
    document.getElementById("recherche_1").style.backgroundColor = "#2A2A2A"
    document.getElementById("recherche_1").style.fontWeight = "normal"

    document.getElementById("recherche_2").style.backgroundColor = "#2A2A2A"
    document.getElementById("recherche_2").style.fontWeight = "normal"

    counter = 0
}

function surbrillanceReal(){
    document.getElementById("recherche_2").style.backgroundColor = "#2A2A2A"
    document.getElementById("recherche_2").style.fontWeight = "normal"

    document.getElementById("recherche_1").style.backgroundColor = "#40393D"
    document.getElementById("recherche_1").style.fontWeight = "bold"

    counter = 1
}

function surbrillanceDuree(){
    document.getElementById("recherche_1").style.backgroundColor = "#2A2A2A"
    document.getElementById("recherche_1").style.fontWeight = "normal"

    document.getElementById("recherche_2").style.backgroundColor = "#40393D"
    document.getElementById("recherche_2").style.fontWeight = "bold"

    counter = 2
}

function search(){
    if(counter==0){
        console.log("pas de filtre")
    }
    else if(counter==1){
        console.log("réalisateur")
    }
    else if(counter==2){
        console.log("durée")
    }
}

main;