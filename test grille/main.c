#include <stdio.h>
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
void topborder(int width){
    printf("%c",STLC );
    for (int i = 0; i <= width; i++) {
        printf("%c%c%c%c", SHSB, SHSB, SHSB, SHTB);
    }
    printf("%c%c%c%c\n",SHSB, SHSB, SHSB,STRC );

}
void speace(int width){
    for(int i =0; i <= width; i++) {
        printf("%c   ", SVSB);
    }
    printf("%c\n",SVSB);
}
void centerborder(int width){

    printf("%c",SVLB );
    for (int i = 0; i <= width; i++) {
        printf("%c%c%c",SHSB ,SHSB,SHSB,SC);
    }
    printf("%c\n", SVRB);

}
int main() {



    topborder(5);

    speace(6);
        centerborder(3);

}