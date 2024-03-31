# Création d'un mini shell

Inspiré de mon cours de programmation système, j'ai développé un mini shell.
Pour ce premier shell, mon obejectif premier est d'implémenter quelques commandes de bases pour rendre le shell utilisable. <br/>
J'aimerais ensuite apporter un aspect esthétique avec des couleurs agréables à l'oeil et un rendu lisible. <br/> <br/>
En prenant exemple d'un shell que j'utilise (starship.sh) je voudrais aussi rajouter des emojis en fonction des langages de programmation utilisés dans le répertoire. Je réfléchis aussi à des emojis accoler au nom d'un fichier (ex: un fichier python).
Je vais améliorer la gestion des paramètres de commandes et généraliser chaque action par des fonctions pour rendre le programme plus claire. 

## Compilation
Entrez la commande **make**
Cela générera un exécutable qui s'appelle **myshell**.

## Tutoriel

Après avoir lancé l'exécutable vous arrivez dans le shell. Voici la liste des commandes:
- !: ouvrir un sous-shell
- cd: parcourir vos fichiers
- ls: afficher les fichiers/dossiers du répertoire
- cat: prend en paramètre un fichier et l'affiche
- kisuisje: un whoami en français
- clear: effacer le terminal
- exit: sortir du shell et des sous-shell


## Includes

Documentation de mes fichiers d'en-tête.

| en-tête            | description          |
| :------:           |:-------:             | 
| shell.h            |header principal qui contient le shell    |  
| cmd.h              |implémentation des commandes              |  
| colors.h           |header spécial où je stock uniquement des couleurs/typos pour l'aspect esthétique|  
| StringVector.h     |header de la gestion des commandes/tokens |    
