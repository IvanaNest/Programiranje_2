#include <stdio.h>
#include <stdlib.h>

typedef struct Razlomak {
    int imenilac;
    int brojilac;
} RAZLOMAK;

void greska() 
{
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
    
}

RAZLOMAK ucitaj_razlomak(RAZLOMAK* a) {
    scanf("%d", &a->brojilac);
    scanf("%d", &a->imenilac);
    
    return *a;
}

int main() 
{
    int n;
    scanf("%d", &n);
    RAZLOMAK *niz;

    niz = (RAZLOMAK *)malloc(n*sizeof(RAZLOMAK));
    if(niz == NULL) 
        greska();
    
    int i;
    
    for(i=0; i<n; i++) {
        ucitaj_razlomak(&niz[i]);
        printf("%d\n", niz[i].imenilac);
    }
        
    
    free(niz);
    
return 0; }
