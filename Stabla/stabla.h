#ifndef _STABLA_H_
#define _STABLA_H_

#include <stdio.h>
#include <stdlib.h>


void greska();


typedef struct stablo
{
    int vrednost;
    struct stablo * levo;
    struct stablo * desno;
} Cvor;

Cvor * napravi_cvor(int broj);
void dodaj_u_stablo(Cvor** koren, int broj);
void ucitaj_stablo(Cvor** koren, FILE* f );
void ispisi_stablo_infiksno(Cvor* koren);
void ispisi_stablo_prefiksno(Cvor* koren);
void ispisi_stablo_postfiksno(Cvor* koren);

void ispisi(Cvor* koren, FILE* f );
void oslobodi(Cvor* koren);



#endif
