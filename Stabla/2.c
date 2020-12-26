#include "stabla.h"

int identitet(Cvor* koren1, Cvor* koren2)
{
    if(koren1 == NULL && koren2 == NULL)
        return 1;
    
    if(koren1 == NULL || koren2 == NULL || koren1->vrednost != koren2->vrednost)
        return 0;
    
    return identitet(koren1->levo, koren2->levo) && identitet(koren1->desno, koren2->desno);
}
int main()
{
    
    Cvor * koren1 = NULL;
    Cvor * koren2 = NULL;
    
    ucitaj_stablo(&koren1, stdin);
    ucitaj_stablo(&koren2, stdin);
    
    if(identitet(koren1,koren2))
        printf("Isti su\n");
    else 
        printf("Nisu isti\n");
    
    
    
    return 0;
}
