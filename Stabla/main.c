#include "stabla.h"

int main ()
{
    Cvor * glava = NULL;
    
    ucitaj_stablo(&glava,stdin);
    
    ispisi_stablo_infiksno(glava);
    printf("\n");
    
    ispisi(glava,stdout);
    //ispisi_stablo_prefiksno(glava);
    //printf("\n");
    //ispisi_stablo_postfiksno(glava);
    
    oslobodi(glava);
    
    return 0;
    
}
