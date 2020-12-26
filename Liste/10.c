#include "kruzne_liste.h"


int main()
{
    Cvor * lista = NULL;
        
    //cvor1 = dodaj_na_kraj(cvor1, 5);
    //cvor1 = dodaj_na_kraj(cvor1, 6);
    ucitaj_listu(&lista,stdin);
    ispisi_listu(lista,stdout);
    oslobodi_listu(lista);

    return 0;
    
    
}


