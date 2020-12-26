#include "stabla.h"

Cvor* pretrazi_stablo (Cvor* koren, int broj)
{
    if(koren == NULL) 
        return NULL;
    
    if(koren->vrednost == broj)
        return koren;
    
    if(koren->vrednost > broj)
        pretrazi_stablo(koren->levo,broj);
    else 
        pretrazi_stablo(koren->desno,broj);
}

Cvor* pronadji_najmanji(Cvor* koren)
{
    if(koren->levo == NULL) 
        return koren;
    
    pronadji_najmanji(koren->levo);
}

Cvor * pronadji_najveci(Cvor* koren)
{
    if(koren->desno == NULL)
        return koren;
    
    pronadji_najveci(koren->desno);
    
}
int main()
{
    Cvor * koren = NULL;
    
    ucitaj_stablo(&koren,stdin);
    ispisi_stablo_infiksno(koren);
    
    int broj;
    Cvor * a;
    scanf("%d", &broj);
    
    a=pretrazi_stablo(koren,broj);
    if(a == NULL)
        printf("Broj nije prondjen!\n");
    else 
        printf("%d\n", a->vrednost);
    
    
    a = pronadji_najmanji(koren);
    printf("%d\n", a->vrednost);
    
    a = pronadji_najveci(koren);
    printf("%d\n", a->vrednost);
    
    
    
    return 0;
}
