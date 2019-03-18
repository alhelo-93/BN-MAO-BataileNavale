/*Prénom:marwan
 * nom:alhelo
 * date:08.03.2018
 * titre:bataille navale
 *
 */
#include <stdio.h>
#include <windows.h>
// graphique pour le grille
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
//
#define size 8
#pragma execution_character_set("utf-8")

// fonction de dessin
 void topborder(int width) { //function pour premier ┌─────┬─────┐
     SetConsoleOutputCP(437); // For semi-graphic characters
     printf("%c%c%c",STLC,SHSB,SHSB);//┌──

     for(int i=0; i<=width; i++){
         printf ("%c%c%c%c%c",SHSB,SHSB,SHTB,SHSB,SHSB);// ───┬───
     }
     printf("%c%c%c\n",SHSB,SHSB,STRC);//──┐
 }
 void centerborder(int width){
     printf("%c   ",SVSB); //│
     for(int i=0; i<=width; i++){ //│   │    │
         printf (" %c   ",SVSB);
     }
     printf(" %c\n",SVSB);//│
 }
 void crossborder(int width){
    printf("%c%c%c",SVLB,SHSB,SHSB);//├──

    for(int i=0; i<=width; i++){
        printf ("%c%c%c%c%c",SHSB,SHSB,SC,SHSB,SHSB);// ───┼───
    }
    printf("%c%c%c\n",SHSB,SHSB,SVRB);//──┤
}
 void bottom(int width){
     printf("%c%c%c",SBLC,SHSB,SHSB);//└──

     for(int i=0; i<=width; i++){
         printf ("%c%c%c%c%c",SHSB,SHSB,SHBB,SHSB,SHSB);// ───┴───
     }
     printf("%c%c%c\n",SHSB,SHSB,SBRC);//──┘

 }
// fonction de grille complet
void gillevid(){
     for(int row=0; row < size; row++){
         if(row==0)
         {
             topborder(size);
             centerborder(size);
         }
         else{
             centerborder(size);
         }
         crossborder(size);
     }
     centerborder(size);
     bottom(size);
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
          gillevid(size);
        }
        else if (choix == 2) {
            printf("comment jouer ?\n il faut regarder sur la grilles et savoir votre postistion et la position de votre énnmie aussi puis bouuuf attaquer");

        } else {
            printf("on est gooo !");

        }
    }

    return 0;

}