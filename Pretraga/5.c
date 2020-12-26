#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define DUZINA 11

void greska()
{
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

float vrednost(float * niz, float tacka)
{
    float vred = 0;
    int i;
    
    for(i=DUZINA -1 ; i>= 0; i--)
        vred = vred*tacka + niz[i];
    
    return vred;
}

float nadji_nulu(float * niz, float levo, float desno)
{
    if(levo > desno)
        greska();
    
    float srednji = (levo + desno)/2;
    float vred = vrednost(niz,srednji);
    
    if(fabs(vred) < 0.0001)
        return srednji;
    
    float f_levo = vrednost(niz,levo);
    
    if((f_levo * vred) < 0)
        return nadji_nulu(niz, levo, srednji);
    else 
        return nadji_nulu(niz,srednji,desno);
    
    
}
int main(int argc, char ** argv) 
{
    float a;
    float b;
    float niz[DUZINA];
    float nula;
    int i;
    
    if(argc != 3)
        greska();
    
    a = atof(argv[1]);
    b = atof(argv[2]);
    
    if(a > b)
        greska();
    
    for(i=0; i<DUZINA; i++)
        scanf("%f", &niz[i]);
    
    nula = nadji_nulu(niz,a,b);
    
    printf("%.2f\n", nula);
    
    
    
}
