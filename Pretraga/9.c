#include <stdio.h>
#include <stdlib.h>

void greska()
{
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

                                          // 5 7 8 9 10 11   0 
                                          // 9 10 11 5 7 8   3 trazimo indeks broja koji je izmedju 2 broja veca od njega
                                          // 11 5 7 8 9 10   1    
                                          // 8 9 10 11 5 7   4        ako je srednji br veci od prvog idemo na desno
                                          // 7 8 9 10 11 5   5        u tacki n-1, proveravamo n-2>n-1
      
     
int provera(int * niz, int n, int s) {
    if(s == n - 1) {
        if(niz[s] < niz[s-1])
            return 1;
        else return 0;
    }
    if(s == 0) 
        return 0;
    
    if(niz[s] < niz[s-1] && niz[s] < niz[s+1])
        return 1;
    else return 0;
}
      
int nadji_pomeranje(int * niz, int n)
{
    int levo = 0;
    int desno = n - 1;
    
    while(levo <= desno){
        int srednji = (levo + desno)/2;
        if(provera(niz,n,srednji))
            return srednji;
        
        if(niz[srednji] >= niz[0])
            levo = srednji +1;
        else desno = srednji - 1;
    }
    
    return 0;
}
int main ()
{
    int n;
    int * niz;
    int k,i;
    
    scanf("%d", &n);
    if(n < 1)
        greska();
    
    niz = malloc (n * sizeof(int));
    if(niz == NULL)
        greska();
    
    for(i=0; i<n; i++)
        scanf("%d", &niz[i]);
    
    k = nadji_pomeranje(niz,n);
    printf("%d\n", k);
    
    
    free(niz);
    return 0;
}
