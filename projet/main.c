/*Prénom:marwan
 * nom:alhelo
 * date:08.03.2018
 * titre:bataille navale
 *
 */
#include <stdio.h>
#include <windows.h>

#define STLC 218 // ┌, Single Top Left Corner
#define STRC 191 // ┐, Single Top Right Corner
#define SBLC 192 // └, Single Bottom Left Corner
#define SBRC 217 // ┘, Single Bottom Right Corner
#define SVSB 179 // │, Single Vertical Simple Border
#define SVRB 180 // ┤, Single Vertical Right Border
#define SVLB 195 // ├, Single Vertical Left Border
#define SHSB 196 // ─, Single Horizontal Simple Border
#define SHBB 193 // ┴, Single Horizontal Bottom Border
#define SHTB 194 // ┬, Single Horizontal Top Border
#define SC   197 // ┼, Single Center

#pragma execution_character_set("utf-8")

 void grillevid() {
     printf("voilà la grille!\n");
     printf ("Une grille basée sur les lignes simples:\n");
     SetConsoleOutputCP(437); // For semi-graphic characters
     for(int i=0; i<=10; i++){
         printf ("%c%c%c%c%c%c%c%c%c\n",STLC,SHSB,SHSB,SHSB,SHTB,SHSB,SHSB,SHSB,STRC);
         printf ("%c   %c   %c\n",SVSB,SVSB,SVSB);
         printf ("%c%c%c%c%c%c%c%c%c\n",SVLB,SHSB,SHSB,SHSB,SC,SHSB,SHSB,SHSB,SVRB);
         printf ("%c   %c   %c\n",SVSB,SVSB,SVSB);
         printf ("%c%c%c%c%c%c%c%c%c\n",SBLC,SHSB,SHSB,SHSB,SHBB,SHSB,SHSB,SHSB,SBRC);
     }

 }
int main() {
    SetConsoleOutputCP(65001);
    int choix=1;

    while (choix != 0) {
        printf(" \n1.Commence jouer\n2.Affiche d'aide\n3.par rapport le jeu\n0. Quitter \nvotre choix:\n");
        scanf("%d", &choix);

        if (choix == 3) {

            printf("C'est un jou simple pour il faut attaquer les ennmies et puis survivre ");

        } else if(choix==1){
          grillevid();
        }
        else if (choix == 2) {
            printf("comment jouer ?\n il faut regarder sur la grilles et savoir votre postistion et la position de votre énnmie aussi puis bouuuf attaquer");

        } else {
            printf("on est gooo !");

        }
    }

    return 0;

}