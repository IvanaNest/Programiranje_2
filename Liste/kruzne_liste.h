#ifndef _KRUZNE_LISTE_
#define _KRUZNE_LISTE_

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


void ispisi_listu(Cvor* lista, FILE* f);


Cvor * dodaj_na_kraj(Cvor * glava, int broj);


void ucitaj_listu(Cvor** lista, FILE* f);


void oslobodi_listu(Cvor* lista);







#endif
