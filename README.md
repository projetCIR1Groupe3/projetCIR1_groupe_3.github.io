Welcome to the CIR1 project  by the group 3
=============================================================

Operating instructions :
------------------------------------------

#### Step 1 : 
Before the launch of the web page with Live-Serveur, you have to compile all of the .c files. After that, execute the file made by compiling with, as parameter, the location of the Data Base wanted. 
##### Exemple :
```
$ gcc main.c createFilmotheque.c director.c list.c movie.c nodeTrie.c request.c search.c netflux.c -o filmotheque

$ ./filmotheque "../support_files_2023/BD_medium.txt"
```

#### Step 2 : 
After the start of the C program, launch the web page with Live-Serveur.
But... Before enjoying this beautiful movie library, you must configure where the browser install the downloads files.
##### Exemple :
In firefox, go to parameters, go to the "Files and applications" part in the "General" page and change the path in "Downloads" for :
```
/mnt/c/Users/[YourUser]/[PathToTheProject]/projetCIR1_groupe_3.github.io/Serveur
```
Now... Just... ENJOY !!!!!

Sources :
-----------------

#### https://projetcir1groupe3.github.io/projetCIR1_groupe_3.github.io/

#### https://trello.com/invite/b/4CddTPKr/ATTI1bdf38dec6455abfd3b1c199faa82ee217C20232/projet-algo-groupe-3
