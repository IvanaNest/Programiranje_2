#include "liste.h"
//1 2 3 0 3 5 
/*void dodaj_minus1(int k, Cvor * lista)
{  
    
    if(lista == NULL)
        return;
    
    while(lista->sledeci != NULL) {
        if((lista->vrednost + lista->sledeci->vrednost) == k || abs(lista->vrednost - lista->sledeci->vrednost) == k ) {
            Cvor *novi = napravi_cvor(-1);
            Cvor * pomocni = lista->sledeci;
            lista->sledeci = novi;
            novi = pomocni;
            
            lista = lista->sledeci->sledeci;
        }
        
        else {
        lista = lista->sledeci;
        }
    }
    
    
    
} */

Cvor* umetni(Cvor* lista, int k)
{
    if (lista == NULL)
        return NULL;

    if (lista->sledeci == NULL)
        return lista;

    if (lista->vrednost + lista->sledeci->vrednost == k ||
        abs(lista->vrednost - lista->sledeci->vrednost) == k)
    {
        //treba umetnuti -1
        Cvor *novi = napravi_cvor(-1);
        novi->sledeci = lista->sledeci;
        lista->sledeci = novi;
        
        novi->sledeci = umetni(novi->sledeci, k);
        
        return lista;
    }
    else
    {
        // Nista se ne umece.
        lista->sledeci = umetni(lista->sledeci, k);
        return lista;
    }
}


int main() {
    
    Cvor * lista1 = NULL;
    Cvor * lista2 = NULL;
    ucitaj_listu(&lista1,stdin);
    
    int k;
    scanf("%d", &k);
    
    lista2 = umetni(lista1,k);
    
    ispisi_listu(lista2,stdout);
    oslobodi_listu(lista2);
    
    
    
    
 return 0;   
}
