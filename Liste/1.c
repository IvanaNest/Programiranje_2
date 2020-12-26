#include "liste.h"

int main ()
{
    Cvor * glava = NULL;
    /*int n;
    
    scanf("%d", &n);
    if(n<0)
        greska();
    
    int i;
    
    for(i=0; i<n; i++) {
        int broj;
        scanf("%d", &broj);
        glava = dodaj_na_kraj_rekurzivno(glava,broj);
    } */
    
    ucitaj_listu(&glava,stdin);
    ispisi_listu(glava,stdout);
    oslobodi_listu(glava);
    return 0;
}
