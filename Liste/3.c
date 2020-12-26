#include "liste.h"

//1 5 9 8 7
Cvor* dodaj_element( Cvor * glava, int broj) 
{
    
    Cvor * pomocna;
    Cvor * prethodni;
    Cvor * novi = NULL;
    novi = napravi_cvor(broj);
    
    if(glava->vrednost > broj) {
        return dodaj_na_pocetak(glava,broj);
    }
    
    prethodni = glava;
    pomocna = glava->sledeci;
    
    
    while(pomocna->sledeci != NULL) {
        if(prethodni->vrednost < broj && pomocna->vrednost > broj) {
            novi->sledeci = pomocna;
            prethodni->sledeci = novi;
            return glava;
        }
        
        prethodni = pomocna;
        pomocna = prethodni->sledeci;
    }
    
    return dodaj_na_kraj(glava,broj);
        
        
}

int main(int argc, char ** argv)
{
    if(argc != 2)
        greska();
    
    int x;
    scanf("%d", &x);
    
    FILE * ulaz;
    
    ulaz = fopen(argv[1],"r");
    if(ulaz == NULL)
        greska();
    
    Cvor * glava = NULL;
    ucitaj_listu(&glava, ulaz);
    
    glava = dodaj_element(glava,x);
    ispisi_listu(glava,stdout);
    oslobodi_listu(glava);
    fclose(ulaz);
    return 0;
}
