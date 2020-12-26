#include "stabla.h"

void greska()
{
    fprintf(stderr,"-1\n");
    exit(EXIT_FAILURE);
}


Cvor * napravi_cvor(int broj)
{
    Cvor * novi = malloc(sizeof(Cvor));
    if(novi == NULL)
        greska();
    
    novi->vrednost = broj;
    novi->levo = NULL;
    novi->desno = NULL;
    
    
    return novi;
}

void dodaj_u_stablo(Cvor** koren, int broj)
{
    if(*koren == NULL) {
        Cvor * novi = napravi_cvor(broj);
        *koren = novi;
        return;
    }
    
    if((*koren)->vrednost > broj)
        dodaj_u_stablo(&(*koren)->levo,broj);
    else dodaj_u_stablo(&(*koren)->desno, broj);
    
}

void ucitaj_stablo(Cvor** koren, FILE* f )
{
    *koren = NULL;
    int broj;
    while(fscanf(f,"%d",&broj) != EOF) {
        dodaj_u_stablo(koren,broj);
    }
    
    
}


void ispisi_stablo_infiksno(Cvor* koren)
{
    if(koren == NULL)
        return;
    
    
    ispisi_stablo_infiksno(koren->levo);
    printf("%d ",koren->vrednost);
    ispisi_stablo_infiksno(koren->desno);
    
    
}

void ispisi_stablo_prefiksno(Cvor* koren)
{
    if(koren == NULL)
        return;
    
    printf("%d ",koren->vrednost);
    ispisi_stablo_infiksno(koren->levo);
    
    ispisi_stablo_infiksno(koren->desno);
    
    
}

void ispisi_stablo_postfiksno(Cvor* koren)
{
    if(koren == NULL)
        return;
    
   
    ispisi_stablo_infiksno(koren->levo);
    ispisi_stablo_infiksno(koren->desno);
    
     printf("%d ",koren->vrednost);
    
}


void ispisi(Cvor* koren, FILE* f )
{
    if(koren == NULL)
        return;
    
    
    ispisi(koren->levo,f);
    fprintf(f,"%d ",koren->vrednost);
    ispisi(koren->desno,f);
    
    
    
}

 void oslobodi(Cvor* koren)
 {
     if(koren == NULL)
         return;
     
     oslobodi(koren->levo);
     oslobodi(koren->desno);
     free(koren);
}










