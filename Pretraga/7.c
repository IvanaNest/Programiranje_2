#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void greska ()
{
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}
                                                 // 1000 800 720 600  105 102 100 99 13
                          
int provera (int * niz, int indeks, int g1, int g2)      // g1 = 100     g2 =1000
{
    if(indeks == 0 && niz[indeks] >= g1 && niz[indeks] < g2)
        return 1;
    
    if(niz[indeks] >= g1 && niz[indeks] < g2 && niz[indeks - 1] >= g2)
        return 1;
    
    return 0;
}            

int nadji_broj(int * niz, int levo, int desno, int granica1, int granica2)
{                                                  //10         //100
    while (levo <= desno) {
        int srednji = (levo + desno)/2;
        
        if(provera(niz,srednji,granica1,granica2))
            return srednji;
        
        if(niz[srednji] >= granica2)
            levo = srednji + 1;
        else desno = srednji - 1;
    }
    
    return -1;
    
}
int main ()
{
    int k,n,i;
    int broj1;
    int broj2;
    int p;
    int * niz;
    
    scanf("%d%d", &n,&k);
    if(k < 1 || n < 0)
        greska();
    
    broj1 = pow(10,k-1);
    broj2 = pow(10,k);
    
    niz = malloc(n * sizeof(int));
    if(niz == NULL)
        greska();
    
    for(i=0; i<n; i++)
        scanf("%d", &niz[i]);
    
    
    
    p = nadji_broj (niz, 0, n-1, broj1, broj2);
    
    if(p == -1)
        printf("Nema\n");
    else printf("%d\n", niz[p]);
    
    
    free(niz);
    return 0;
}
