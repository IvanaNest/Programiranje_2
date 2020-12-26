#include "stabla.h"

int dubina_stabla(Cvor * koren)
{
    if(koren == NULL)
        return 0;
    
    int dubina_levo = dubina_stabla(koren->levo);
    int dubina_desno = dubina_stabla(koren->desno);
    
    if(dubina_levo > dubina_desno)
        return 1 + dubina_levo;
    else return 1 + dubina_desno;
}

int main()
{
    FILE * ulaz;
    
    ulaz = fopen("stablo.txt","r");
    if(ulaz == NULL)
        greska();
    
    Cvor * koren = NULL;
    
    ucitaj_stablo(&koren,ulaz);
    
    if(koren == NULL) {
        printf("0\n");
        return 0;
    }
    
    int dubina = dubina_stabla(koren);
    printf("%d\n", dubina);
    
    
    fclose(ulaz);
    return 0;
}
