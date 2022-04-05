Installer la librairie SOIL avant:
sudo apt-get install libsoil-dev

Commande pour compiler le jeu:
gcc main.c controlplayer.c controldisplay.c  readimage.c -o jumpb -lglut -lGL -lSOIL
