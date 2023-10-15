# Création d'un mini shell

Insipiré de mon cours de programmation système, j'ai développé un mini shell

## Compilation
```
gcc main.c includes/*.h src/*.c cmd/*.c -o ./main.o
./main.o
```

## Tutoriel

Après avoir lancé l'exécutable vous arrivez dans le shell. Voici la liste des commandes:
- !: ouvrir un sous-shell
- cd: parcourir vos fichiers
- ls: afficher les fichiers/dossiers du répertoire
- kisuisje: un whoami en français
- clear: effacer le terminal
- exit: sortir du shell et des sous-shell


## Includes

Dans cette partie, je document les différents fichiers d'en-tête.

| en-tête            | description          |
| :------:           |:-------:             | 
| shell.h            |header principal qui contient le shell   |  
| colors.h           |header spécial où je stock uniquement des couleurs/typos pour l'aspect esthétique|  
| StringVector.h     |header de la gestion des commandes/tokens |    