#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 21

void greska()
{
    fprintf(stderr,"-1\n");
    exit(EXIT_FAILURE);    
}
int nadji_rec(char ** niz, int l, int d, char rec[MAX] )
{
    if( l > d )
        return -1;
    
    int s = (l + d)/2;
    int poredjenje = strcmp(niz[s], rec );
    
    if(poredjenje == 0)      // aa bb kk    kk
        return s;
    
    if(poredjenje < 0) 
        return nadji_rec(niz, s+1, d,rec);
    else return nadji_rec(niz, l, s-1,rec);
    
}

int poredjenje(const void * a, const void * b)
{
    char * a1 = (char *)a;
    char * b1 = *(char **)b;
    
    return strcmp(a1,b1);
}
int main()
{
    int n;
    int i;
    char **reci = NULL;
    char rec[MAX];
    int p;
    char **pk;
    
    printf("Unesi broj reci:\n");
    scanf("%d", &n);
    if(n < 1)
        greska();
    
    reci = malloc (n*sizeof( char *));
    if(reci == NULL)
        greska();
    
    printf("Unesi reci sortirane leksikografski:\n");
    for(i=0; i<n; i++) {
        reci[i] = malloc (MAX * sizeof(char));
            if(reci[i] == NULL)
                greska();
        
        scanf("%s", reci[i]);
    }
    
    printf("Unesi rec\n");
    scanf("%s", rec);
    
    pk = (char **) bsearch(rec, reci, n, sizeof(char *), &poredjenje);
    
    if(pk == NULL)
        printf("Nema reci\n");
    else printf("Pozicija reci %s: %ld\n", rec,pk-reci);
    /*p = nadji_rec(reci,0, n-1, rec);
    
    if(p == -1) 
        printf("Nema te reci\n");
    
    else 
        printf("Pozicija reci %s: %d\n", rec,p); */
    
    for(i = 0; i<n; i++)
        free(reci[i]);
    free(reci);
    return 0;
}
