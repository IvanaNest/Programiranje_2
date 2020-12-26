#include "liste.h"

void greska()
{
    fprintf(stderr,"-1\n");
    exit(EXIT_FAILURE);
}
Cvor* napravi_cvor(int broj)
{
    Cvor * novi = malloc (sizeof(Cvor));
    if(novi == NULL)
        greska();
    
    novi->vrednost = broj;
    novi->sledeci = NULL;
    
    return novi;
}

Cvor* dodaj_na_pocetak(Cvor* glava, int br)
{
    Cvor * novi = napravi_cvor(br);
    
    novi->sledeci = glava;
    return novi;
}


void dodaj_na_pocetak2(Cvor** glava, int* broj)
{
    Cvor * novi = napravi_cvor(*broj);
    novi->sledeci = *glava;
    *glava = novi;
}

void ispisi_listu(Cvor* lista, FILE* f)
{   
    fprintf(f,"[");
    
    while(lista != NULL) {
        if(lista->sledeci == NULL)
            fprintf(f,"%d]", lista->vrednost);
        else 
        fprintf(f,"%d,", lista->vrednost);
        
        lista = lista->sledeci;
    }
    
}

Cvor * dodaj_na_kraj(Cvor * glava, int broj)
{
    Cvor * novi = napravi_cvor(broj);
    
    if(glava == NULL)
        return novi;
    
    else {
        Cvor * pomocna_glava = glava;
    
        while(pomocna_glava->sledeci != NULL)
            pomocna_glava = pomocna_glava->sledeci;
    
        pomocna_glava->sledeci = novi;
    
    
        return glava;
    }
}

void dodaj_na_kraj2(Cvor** glava, int broj)
{
    Cvor * novi = napravi_cvor(broj);
    
    if(*glava == NULL)
        *glava = novi;
    
    else {
        Cvor * pomocna_glava = *glava;
    
        while(pomocna_glava->sledeci != NULL)
            pomocna_glava = pomocna_glava->sledeci;
    
        pomocna_glava->sledeci = novi;
    }
    
}

Cvor * dodaj_na_kraj_rekurzivno(Cvor * glava, int broj)
{
    if(glava == NULL)
        return napravi_cvor(broj);
    
    else {
        glava->sledeci = dodaj_na_kraj_rekurzivno(glava->sledeci,broj);
        return glava;
    }
        
}

void ucitaj_listu(Cvor** glava, FILE* f)
{
    int broj;
    *glava = NULL;
    while(fscanf(f,"%d", &broj) != EOF)
        dodaj_na_kraj2(glava,broj);
        
}

void oslobodi_listu(Cvor* glava)
{
    while(glava != NULL) {
        Cvor * pomocna_glava = glava;
        glava = glava->sledeci;
        free(pomocna_glava);
    }
}






