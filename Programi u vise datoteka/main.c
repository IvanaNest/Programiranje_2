#include <stdio.h>
#include "polinom.h"

int main() {
    int stepen1, stepen2;
    int *koeficijenti1, *koeficijenti2;
    int **zbir_polinoma;
    int stepen_zbira;
    
    koeficijenti1 = unos(&stepen1);
    koeficijenti2 = unos(&stepen2);
    
    stepen_zbira = suma_polinoma(koeficijenti1, stepen1, koeficijenti2, stepen2, zbir_polinoma);
    
    ispis_polinoma(*zbir_polinoma, stepen_zbira);
    
    
    
    //ispis_polinoma(koeficijenti, stepen);
    
return 0; }
    
    
    
