# GIF3004-laboratoire5
Pour etablir la connexion client-serveur TCP nous avons créer serveur.c(Raspberry Pi) et client.c(Machine virtuelle) ----
1-Tout d'abord nous avons copier le contenu du fichier serveur.c dans le tp1.c qui se trouve dans le laboratoire 1. ----
2-Ensuite nous l'avons compiler(F7) puis déboguer avec (F5). ----
3-Ensuite nous avons ouvert deux terminaux un pour le Raspberry Pi(ssh) et un pour la machine virtuelle(client). ----
4-Nous avons compiler client.c avec la commande suivante : gcc -o client client.c ---
5-On execute le serveur dans ssh (cd projet/laboratoire1) -> ./SETR_TP1   ------
6-Dans la deuxième fenètre on execute client.c avec : ./client.c       -----
7-Nous appuyons sur des touches au hasard puis nous l'envoyons vers le serveur en appuyant sur la touche entrée
