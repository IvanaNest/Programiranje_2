#ifndef _DVOSTRUKO_POVEZANE_LISTE_
#define _DVOSTRUKO_POVEZANE_LISTE_

#include <stdio.h>
#include <stdlib.h>

typedef struct cvor_
{
    int vrednost;
    struct cvor_ * sledeci;
    struct cvor_ * prethodni;
} Cvor;

void greska();

Cvor* napravi_cvor(int broj);


Cvor* dodaj_na_pocetak(Cvor* glava, int br); 


void ispisi_listu(Cvor* lista, FILE* f);


Cvor * dodaj_na_kraj(Cvor * glava, int broj);


void ucitaj_listu(Cvor** lista, FILE* f);


void oslobodi_listu(Cvor* lista);

void ispisi_unazad(Cvor * lista,FILE * f);

Cvor * ubaci_na_poziciju(Cvor * lista, int pozicija, int broj);





#endif
