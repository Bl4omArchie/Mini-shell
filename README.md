# Création d'un mini shell

Insipiré de mon cours de programmation système, j'ai développé un mini shell

## Compilation
```
gcc main.c src/*.h src/*.c -o ./main.o
./main.o
```

## Tutoriel

Après avoir lancé l'exécutable vous arrivez dans le shell. Voici la liste des commandes:
- !: ouvrir un sous-shell
- cd: parcourir vos fichiers
- ls: afficher les fichiers/dossiers du répertoire
- clear: effacer le terminal
- exit: sortir du shell et des sous-shell