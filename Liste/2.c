#include "liste.h"

int veci_od(Cvor * glava, int broj,int suma) {
    if(glava == NULL)
        return suma;
    
    if(glava->vrednost > broj)
        suma++;
    
    veci_od(glava->sledeci,broj,suma);
    
}

int main(int argc, char ** argv)
{
    if(argc != 2)
        greska();
    
    int x;
    scanf("%d", &x);
    
    FILE * ulaz;
    
    ulaz = fopen(argv[1],"r");
    if(ulaz == NULL)
        greska();
    
    Cvor * glava = NULL;
    ucitaj_listu(&glava, ulaz);
    
    printf("%d\n", veci_od(glava,x,0));
    
    oslobodi_listu(glava);
    fclose(ulaz);
    return 0;
}
