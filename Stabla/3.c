#include "stabla.h"
#include <limits.h>

int broj_cvorova(Cvor * koren)
{
    if(koren == NULL)
        return 0;
    else 
        return 1 + broj_cvorova(koren->levo) + broj_cvorova(koren->desno);
}

int broj_listova(Cvor * koren) 
{
    if(koren == NULL)
        return 0;
    else if(koren->levo == NULL && koren->desno == NULL)
        return 1 + broj_listova(koren->levo) + broj_listova(koren->desno);
    else return broj_listova(koren->levo) + broj_listova(koren->desno);
}

int zbir(Cvor * koren)
{
    if(koren == NULL)
        return 0;
    
    return koren->vrednost + zbir(koren->levo) + zbir(koren->desno);
}

void ispisi_pozitivne(Cvor * koren)
{
    if(koren == NULL)
        return ;
    
    if(koren->vrednost > 0)
        printf("%d " , koren->vrednost);
    
    ispisi_pozitivne(koren->levo);
    ispisi_pozitivne(koren->desno);
    
    
}

int broj_cvorova_na_nivou(Cvor * koren, int i)
{
    if(koren == NULL)
        return 0;
    
    if(i == 0)
        return 1;
    
    return broj_cvorova_na_nivou(koren->levo,i-1) + broj_cvorova_na_nivou(koren->desno,i-1);
}

int dubina_stabla(Cvor * koren)
{
    if(koren == NULL)
        return 0;
    
    int dubina_levo = dubina_stabla(koren->levo);
    int dubina_desno = dubina_stabla(koren->desno);
    
    if(dubina_levo > dubina_desno)
        return 1 + dubina_levo;
    else
        return 1 + dubina_desno;
}

void ispisi_na_nivou(Cvor * koren,int i)
{
    if(koren == NULL)
        return;
    
    if(i == 0)
        printf("%d ",koren->vrednost);
    
    ispisi_na_nivou(koren->levo,i-1);
    ispisi_na_nivou(koren->desno,i-1);
}

int maks_na_nivou(Cvor * koren, int i)
{
    if(koren == NULL)
        return INT_MIN;
    
    if(i == 0 )
        return koren->vrednost;
    
    int maks_levo = maks_na_nivou(koren->levo, i-1);
    int maks_desno = maks_na_nivou(koren->desno,i-1);
    
    if(maks_levo > maks_desno)
        return maks_levo;
    else return maks_desno;
    
    
}

int zbir_na_nivou(Cvor * koren, int i)
{
    if(koren == NULL)
        return 0;
    
    if(i == 0) {
        return koren->vrednost;
    }
    
    return zbir_na_nivou(koren->levo,i-1) + zbir_na_nivou(koren->desno,i-1); 
    
}

int manje_jednako_x(Cvor * koren, int x)
{
    if(koren == NULL)
        return 0;
    
    if(koren->vrednost <= x)
        return koren->vrednost + manje_jednako_x(koren->levo,x) + manje_jednako_x(koren->desno,x);
    
    return manje_jednako_x(koren->levo,x);
}
int main()
{
    
    Cvor * koren = NULL;
    
    ucitaj_stablo(&koren, stdin);
    
    printf("Broj cvorova: %d\n", broj_cvorova(koren));
    printf("Broj listova: %d\n", broj_listova(koren));
    printf("Zbir: %d\n", zbir(koren));
    printf("Pozitivni: ");
    ispisi_pozitivne(koren);
    printf("\n");
    printf("Dubina stabla: %d\n", dubina_stabla(koren));
    int i;
    scanf("%d",&i);
    printf("Broj cvorova na %d. nivou: %d\n", i,broj_cvorova_na_nivou(koren,i));
    printf("Ispisi elemente na %d. nivou:",i);
    ispisi_na_nivou(koren,i);
    printf("\n");
    printf("Maksimum na %d. nivou: %d\n", i,maks_na_nivou(koren,i));
    printf("Zbir na %d. nivou: %d\n", i,zbir_na_nivou(koren,i));
    int x;
    scanf("%d", &x);
    printf("Manji ili jednaki od %d: %d\n", x,manje_jednako_x(koren,x));
    
    oslobodi(koren);
    return 0;
}
