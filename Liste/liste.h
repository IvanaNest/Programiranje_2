#ifndef _LISTE_H_
#define _LISTE_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct cvor_
{
    int vrednost;
    struct cvor_ * sledeci;
} Cvor;

void greska();

Cvor* napravi_cvor(int broj);


Cvor* dodaj_na_pocetak(Cvor* glava, int br); 

void dodaj_na_pocetak2(Cvor** lista, int * broj);

void ispisi_listu(Cvor* lista, FILE* f);

Cvor * dodaj_na_kraj(Cvor * glava, int broj);

void dodaj_na_kraj2(Cvor** lista, int broj);

Cvor * dodaj_na_kraj_rekurzivno(Cvor * glava, int broj);

void ucitaj_listu(Cvor** lista, FILE* f);

void oslobodi_listu(Cvor* lista);


#endif
