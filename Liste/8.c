#include "liste.h"

/*Cvor * izbaci(Cvor * lista, int k)
{
    
    if(lista == NULL)
        return NULL;
    
    if((lista->sledeci->vrednost + lista->vrednost) == k) {
        Cvor * pomocni1 = lista->sledeci;
        free(lista);
        return izbaci(pomocni,k);
    } else {
        
        izbaci(lista->sledeci,k);
        return lista;
    }
    
    
} */



int main() {
    
    Cvor * lista1 = NULL;
    Cvor * lista2 = NULL;
    ucitaj_listu(&lista1,stdin);
    
    int k;
    scanf("%d", &k);
    
    lista2 = izbaci(lista1,k);
    
    ispisi_listu(lista2,stdout);
    oslobodi_listu(lista2);
    
    
    
    
 return 0;   
}
