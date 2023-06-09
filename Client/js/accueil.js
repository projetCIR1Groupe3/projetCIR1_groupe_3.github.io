function main(){
    
}

let counter=0
let counter_Surbrillance=0
let counter_Real=0

function resetSurbrillance(){
    document.getElementById("recherche_1").style.backgroundColor = "#2A2A2A"
    document.getElementById("recherche_1").style.fontWeight = "normal"

    document.getElementById("recherche_2").style.backgroundColor = "#2A2A2A"
    document.getElementById("recherche_2").style.fontWeight = "normal"

    counter = 0
}

function surbrillanceReal(){
    if(counter_Surbrillance%2==0){
        document.getElementById("recherche_1").style.backgroundColor = "#40393D"
        document.getElementById("recherche_1").style.fontWeight = "bold"

        document.getElementById("recherche_2").style.backgroundColor = "#2A2A2A"
        document.getElementById("recherche_2").style.fontWeight = "normal"
        counter = 1
    }
    else{
        document.getElementById("recherche_1").style.backgroundColor = "#2A2A2A"
        document.getElementById("recherche_1").style.fontWeight = "normal"

        document.getElementById("recherche_2").style.backgroundColor = "#2A2A2A"
        document.getElementById("recherche_2").style.fontWeight = "normal"
        counter=0
    }
    counter_Surbrillance+=1
}

function surbrillanceDuree(){
    if(counter_Real%2==0){
        document.getElementById("recherche_1").style.backgroundColor = "#2A2A2A"
        document.getElementById("recherche_1").style.fontWeight = "normal"

        document.getElementById("recherche_2").style.backgroundColor = "#40393D"
        document.getElementById("recherche_2").style.fontWeight = "bold"
        counter = 2
    }
    else{
        document.getElementById("recherche_1").style.backgroundColor = "#2A2A2A"
        document.getElementById("recherche_1").style.fontWeight = "normal"

        document.getElementById("recherche_2").style.backgroundColor = "#2A2A2A"
        document.getElementById("recherche_2").style.fontWeight = "normal"
        counter=0
    }

    counter_Real+=1
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