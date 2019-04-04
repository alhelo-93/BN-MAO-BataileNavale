/*Prénom:marwan
 * nom  :alhelo
 * date :08.03.2018
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
#define size 10
#pragma execution_character_set("utf-8")
#define CUBE 219
#define CARRE 176

int grillemodele[10][10] = {
        {3, 0, 0,  0,  0, 0, 0,  0,  0, 0},
        {3, 0, 0,  0,  0, 0, 1,  0,  0, 0},
        {3, 0, 0,  -1, 0, 0, 1,  0,  0, 0},
        {0, 0, 0,  0,  0, 0, 0,  0,  0, 0},
        {0, 0, 0,  0,  4, 4, 4,  14, 0, 0},
        {0, 0, 0,  0,  0, 0, 0,  0,  0, 0},
        {0, 0, 0,  0,  0, 0, 0,  0,  0, 0},
        {0, 0, 0,  0,  0, 0, 0,  0,  0, 0},
        {0, 0, 22, 22, 0, 0, -1, 0,  0, 0},
        {0, 0, 0,  0,  0, 0, 0,  0,  0, 0}};


// fonction de dessin
// ┌─────┬─────┐
void topborder(int width) {
    SetConsoleOutputCP(437); // For semi-graphic characters$
    printf("    ");
    for (int j = 0; j < width; j++) {
        printf(" %c   ", j + 'A');
    }
    printf("\n");
    printf("   ");
    printf("%c%c%c", STLC, SHSB, SHSB);//┌──

    for (int i = 0; i < width - 1; i++) {
        printf("%c%c%c%c%c", SHSB, SHSB, SHTB, SHSB, SHSB);// ───┬───
    }
    printf("%c%c%c\n", SHSB, SHSB, STRC);//──┐
}

//│   │    │
void centerborder(int Num, int width) {


    printf("%3d", Num + 1);

    printf("%c", SVSB); //│


    for (int i = 0; i < width; i++) { //│   │    │

        char display = '~';

        if (grillemodele[Num][i] < 0) {
            display = '.';
        } else if (grillemodele[Num][i] <= 20 && grillemodele[Num][i] > 10) {
            display = CUBE;

        } else if (grillemodele[Num][i] > 20) {
            display = CARRE;
        }
        printf("  %c %c", display, SVSB);
    }

    printf("\n");//│
}


//├─────┼─────┤
void crossborder(int width) {
    printf("   ");
    printf("%c%c%c", SVLB, SHSB, SHSB);//├──

    for (int i = 0; i < width - 1; i++) {
        printf("%c%c%c%c%c", SHSB, SHSB, SC, SHSB, SHSB);// ───┼───
    }
    printf("%c%c%c\n", SHSB, SHSB, SVRB);//──┤
}

//└─────┴─────┘
void bottom(int width) {
    printf("   ");
    printf("%c%c%c", SBLC, SHSB, SHSB);

    for (int i = 0; i < width - 1; i++) {
        printf("%c%c%c%c%c", SHSB, SHSB, SHBB, SHSB, SHSB);//
    }
    printf("%c%c%c\n", SHSB, SHSB, SBRC);//

}

// fonction de grille complet
// ┌─────┬─────┐
// │     │     │
// ├─────┼─────┤
// │     │     │
// └─────┴─────┘
void grille() {
    for (int row = 0; row < size; row++) {
        if (row == 0) {
            topborder(size);
        } else {
            crossborder(size);
        }
        centerborder(row, size);
    }

    bottom(size);
}

void jouer() {
    SetConsoleOutputCP(65001);
    int nbbateau = 3;
    int nbbateaucoule = 0;
    char tire[10];
    int x;
    int y;
    // tant que le nombres du bateaux coulé plus petit que trois
    while (nbbateaucoule < nbbateau) {


        //     afficher la grille
        grille();
        //     demander ou veut tire
        printf("Quelle case voulez-vous tirer ?\n");
        scanf("%s", tire);
        x = tire[1] - 49;
        y = tire[0] - 65;
        SetConsoleOutputCP(65001);
        //     vérfier la donnée
        if (grillemodele[x][y] == 0) {
            printf("A l'eau\n");
            grillemodele[x][y] = -1;
        } else if (grillemodele[x][y] > 0 && grillemodele[x][y] < 10) {
            printf("vous avez touché \n");
            grillemodele[x][y] = grillemodele[x][y] + 10;
        } else {
            printf("toushé 2 fois\n\n");
        }
        //     regarder le reusltat de tire et changer le modéle
        //

    }


}

int main() {
    int choix = 1;
    int menu2 = 1;
    while (choix != 0) {
        SetConsoleOutputCP(65001);
        //system("cls");
        printf(" \n1.Affiche l'aide \n2.placer les bateaux  \n3.Jouer\n0.Quitter \n");
        printf("Quel est votre choix ?\n");
        scanf("%d", &choix);

        switch (choix) {

            case 0:
                break;
            case 1:
                printf("Comment jouer ?\nIl faut regarder sur la grilles et savoir votre postistion \nEt la position de votre énnmie aussi puis bouuuf attaquer.\n\n");
                break;
            case 2:

                while (menu2 != 0) {
                    SetConsoleOutputCP(65001);
                    //system("cls");
                    printf("\n1.Grille fixe \n2.Choix d'une grille existant \n3.placement aléatoir\n0.Retour arrière");

                    printf("\nQuel est votre choix ?\n");
                    scanf("%d", &menu2);
                    switch (menu2) {
                        case 0:
                            break;
                        case 1:
                            grille();
                            break;
                        case 2:
                            printf("en tin de développer !");
                            break;
                        case 3:
                            printf("en tin de développer!!");
                            break;
                        default:
                            printf("Choisissez de la list s'il vous plaît\n");
                            break;
                    }
                }

                break;
            case 3:

                jouer();
                break;
            default:
                printf("Choisissez de la list s'il vous plaît\n");
                break;
        }

    }
    return 0;

}