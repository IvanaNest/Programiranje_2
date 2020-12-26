#include "liste.h"

//1-> 7-> 10- >12-> 14
//5-> 6-> 7-> 15 
Cvor * spoji(Cvor * lista1, Cvor * lista2)
{
    if(lista1 == NULL)
            return lista2;
    
    if(lista2 == NULL)
            return lista1;
    
    if(lista1->vrednost <= lista2->vrednost) {
        lista1->sledeci = spoji(lista1->sledeci,lista2);
        return lista1;
    }
    
    else {
        lista2->sledeci = spoji(lista1,lista2->sledeci);
        return lista2;
    }
    
    return lista1;
}
Cvor * naizmenicno(Cvor * lista1, Cvor * lista2)
{
    if(lista1 == NULL) 
        return lista2;
    
    if(lista2 == NULL)
        return lista1;

    lista1->sledeci = naizmenicno(lista2,lista1->sledeci);
    
    return lista1;
}

int main()
{
    
    Cvor * glava1 = NULL;
    ucitaj_listu(&glava1, stdin);
    
    Cvor * glava2 = NULL;
    ucitaj_listu(&glava2, stdin);
    
    Cvor * glava = NULL;
    glava = spoji(glava1,glava2);
    
    ispisi_listu(glava,stdout);
    oslobodi_listu(glava);
    
    return 0;
}
