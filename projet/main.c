#include <stdio.h>
#include <windows.h>
#pragma execution_character_set("utf-8")
int main() {
    SetConsoleOutputCP(65001);
    int choix;
    printf(" \n1.Commence jouer\n2.Affiche d'aide\n3.par rapport le jeu\nvotre choix:\n");
    scanf("%d",&choix);

while(choix!=1&&choix!=2&&choix!=3){
    printf("entrez les chiffre entre 1 et 3:\n");
    scanf("%d",&choix);

}
if(choix==3){
    printf("C'est un jou simple pour il faut attaquer les ennmies et puis survivre ");

}
else if (choix==2){
    printf("comment jouer ?\n il faut regarder sur la grilles et savoir votre postistion et la position de votre énnmie aussi puis bouuuf attaquer");

}
else{
    printf("on est gooo !");

}
    return 0;
}