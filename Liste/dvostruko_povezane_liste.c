#include "dvostruko_povezane_liste.h"

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
    novi->prethodni = NULL;
    novi->sledeci = NULL;
    
    return novi;
}

Cvor* dodaj_na_pocetak(Cvor* glava, int x)
{
    if(glava == NULL)
        return napravi_cvor(x);
    
    Cvor * novi = napravi_cvor(x);
    
    novi->sledeci = glava;
    glava->prethodni = novi;
    
    return novi;
    
}


void ispisi_listu(Cvor* lista, FILE* f)
{
    int brojac = 0;
    while(lista != NULL) {
        if(brojac == 0) {
        fprintf(f,"[%d", lista->vrednost);
        brojac ++;
        } else {
            fprintf(f,",%d", lista->vrednost);
        }
        
        lista = lista->sledeci;
    }
    
    fprintf(f,"]");
    
}
// 1 <-> 5 <-> 7 <-> 8->
Cvor * dodaj_na_kraj(Cvor * glava, int broj)
{
    if(glava == NULL) {
        return napravi_cvor(broj);
    }
    
    Cvor * pomocna = glava;
    Cvor * novi = napravi_cvor(broj);
    
    while(glava->sledeci != NULL) {
        glava = glava->sledeci;
    }
    
    novi->prethodni = glava;
    glava->sledeci = novi;
    
    
    
    
    return pomocna;
}
// 5
void ucitaj_listu(Cvor** lista, FILE* f) 
{
    int broj;
    *lista = NULL;
    
    while(fscanf(f,"%d",&broj) != EOF) {
           *lista = dodaj_na_kraj(*lista,broj);
    }
    
            
    
}
// 1 <-> 2 <-> 5 ...
void oslobodi_listu(Cvor* lista)
{
        Cvor * pomocna = NULL;
        
    while(lista != NULL) {
        pomocna = lista;
        lista->sledeci->prethodni = NULL;
        lista = lista->sledeci;
        free(pomocna);
    }
        
        
}

void ispisi_unazad(Cvor * lista,FILE * f)
{
    if(lista == NULL)
        return;
    
    while(lista ->sledeci != NULL) {
        lista = lista->sledeci;
    }
    
    fprintf(f,"[");
    
    while(lista != NULL) {
        if(lista->prethodni == NULL) {
            fprintf(f,"%d]",lista->vrednost);
        } else {\
            fprintf(f,"%d,", lista->vrednost);
        }
        
        lista = lista->prethodni;
    }
}

//1 2 3<-> 4 6 8
Cvor * ubaci_na_poziciju(Cvor * lista, int pozicija, int broj)
{
    if(pozicija == 0)
        return dodaj_na_pocetak(lista,broj);
    
    int i;
    Cvor * pomocna1 = lista;
    
    for(i=0; i<pozicija-1; i++) {
        if(lista==NULL)
            greska();
        lista = lista->sledeci;
    }
    
    //dodajemo iza
    
    Cvor * novi = napravi_cvor(broj);
    Cvor * pomocni = lista->sledeci;
    lista->sledeci = novi;
    if(pomocni != NULL)
        novi->sledeci = pomocni;
    novi->prethodni = lista;
    pomocni->prethodni = novi;
    
    
    return pomocna1;
    
}










