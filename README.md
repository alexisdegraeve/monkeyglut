# 1819_IHDCB132_Degraeve_Alexis

Installer la librairie SOIL avant:
sudo apt-get install libsoil-dev

Compiler avec Makefile:
> make
pour recompilier utiliser 
> make clean
> make

Commande pour compiler le jeu:
gcc main.c controlplayer.c controldisplay.c  readimage.c -o jumpb -lglut -lGL -lSOIL

<b>Pour jouer au jeu</b><br/>
q : déplacement gauche<br/>
d : déplacement droit<br/>
barre d'espace: sauter<br/>
a: tirer une boule<br/>
