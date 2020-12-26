#include <stdio.h>
#include <stdlib.h>
#define BROJ 100

void greska ()
{
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

int provera (int * niz, int indeks) {
    if(niz[indeks] > BROJ && indeks == 0)
        return 1;
    
    if(niz[indeks] > BROJ && niz[indeks - 1] < 100)
        return 1;
    
    return 0;
}

int nadji_veci(int * niz, int levo, int desno)
{
    while(levo <= desno) {
        int srednji = (levo + desno)/2;
        
        if(provera(niz,srednji))                                 // 1  5 90 101 102 200
            return srednji;
        
        if(niz[srednji]  < BROJ)
            levo = srednji + 1;
        else desno = srednji - 1;
        
    }
    
    return -1;

}

int main ()
{
    int n;
    int *niz;
    int p;
    int i;
    
    scanf("%d", &n);
    if( n < 0 )
        greska();
    
    niz = malloc (n * sizeof(int));
    if (niz == NULL)
        greska();
    
    for(i=0; i<n; i++)
        scanf("%d", &niz[i]);
    
    p = nadji_veci(niz,0,n-1);
    if (p == -1)
        printf("-\n");
    else 
        printf("%d\n", niz[p]);
    
    
    free(niz);
    return 0;
}
