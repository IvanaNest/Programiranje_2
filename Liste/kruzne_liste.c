#include "kruzne_liste.h"

void greska()
{
    fprintf(stderr,"-1\n");
    exit(EXIT_FAILURE);
}

Cvor * napravi_cvor(int x) 
{
    Cvor * novi = malloc(sizeof(Cvor));
    if(novi == NULL)
        greska();
    
    novi->vrednost = x;
    novi->sledeci = NULL;
    
    return novi;
}

Cvor* dodaj_na_pocetak(Cvor * glava, int br)
{
    if(glava == NULL) {
        Cvor * novi = napravi_cvor(br);
        novi->sledeci = novi;
        return novi;
    }
    
    Cvor * novi = napravi_cvor(br);
    novi->sledeci = glava;
    
    while(glava->sledeci != NULL) {
        glava = glava->sledeci;
    }
    
    glava->sledeci = novi;
    
    return novi;
}

void ispisi_listu(Cvor* lista, FILE* f) 
{
    if(lista == NULL) 
        return;
    
    Cvor * pomocna = lista;
    
    fprintf(f,"[");
    while(lista) {
        
        fprintf(f,",%d", lista->vrednost);
        
        lista = lista->sledeci;
        if(lista == pomocna) 
            break;
    }
    
    fprintf(f,"]\n");
    
}

Cvor * dodaj_na_kraj(Cvor * glava, int broj)
{
    if(glava == NULL) 
        return dodaj_na_pocetak(glava,broj);
    
    Cvor * pomocna = glava;
    
    while(pomocna->sledeci != glava) {
        pomocna = pomocna->sledeci;
    }
    
    Cvor * novi = NULL;
    pomocna->sledeci = novi;
    novi->sledeci = glava;
    
    
    return glava;
    
    
    
}

void ucitaj_listu(Cvor** lista, FILE* f)
{
    int broj;
    *lista = NULL;
    while(fscanf(f,"%d", &broj) != EOF) {
        *lista = dodaj_na_kraj(*lista, broj);
    }
    
    return lista;
}

// 1 2 5 4 7
void oslobodi_listu(Cvor* lista)
{
    Cvor * glava = lista;
    Cvor * pomocni;
    lista = lista->sledeci;    
    while(lista != glava) {
        pomocni = lista->sledeci;
        free(lista);
        lista = pomocni;
        
    }
    
    free(glava);
    
    
        
        
}






