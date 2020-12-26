#include <stdio.h>
#include <stdlib.h>

void greska() 
{
    fprintf(stderr,"-1\n");
    exit(EXIT_FAILURE);
}

int linearna_pretraga(int * a, int n, int x)
{
    int i;
    for(i=0; i<n; i++) {
        if(a[i] == x)
            return i;
    }
    
    return -1;
}

int binarna_pretraga1(int * a, int n,int x)
{ 
    int l = 0;                                              //4 5 6 7 9 12 15 17   19
    int d = n - 1;                                          //0 1 2 3 4 5  6  7  
                                                        
    int s;
    
    while(l <= d) {
        int s = l + (d - l)/2;
        if(a[s] == x)
            return s;
        
        if(a[s] > x) {
            d = s - 1;
            continue;
        }
        
        if(a[s] < x) 
            l = s + 1;
    }
    
    return -1;
            
}

int binarna_pretraga2(int *a, int l, int d, int x)
{
    if(l > d)
        return -1;
    
    int s= l + (d - l)/2;
    
    if(a[s] == x)
        return s;
    
    if(a[s] < x)
        return binarna_pretraga2(a, s+1, d,x);
    
    if(a[s] > x)
        return binarna_pretraga2(a,l,s-1,x);
    
    
}

int poredi (const void * a, const void * b)
{
    int a1 = *(int *)a;
    int b1 = *(int *)b;
    
    return a1 - b1;
}
int main ()
{  
    int n,x;
    int i;
    int * a;
    int k;
    int *p;
    
    printf("Unesi broj elemenata niza:\n");
    scanf("%d", &n);
    if(n < 1)
        greska();
    
    a = malloc (n * sizeof(int));
    if(a == NULL) 
        greska();
    
    /* void *bsearch(const void *key, const void *base,
                     size_t nmemb, size_t size,
                     int (*compar)(const void *, const void *)); */

    printf("Unesi elemenate sortirane rastuce:\n");
    for(i=0; i<n; i++) 
        scanf("%d", &a[i]);
    
    printf("Unesi trazeni broj:\n");
    scanf("%d", &x);
    
    
    p = (int *) bsearch(&x, a, n, sizeof(int), &poredi);
    
    if(p == NULL)
         printf("Nema tog elementa\n");
    else printf("Pozicija elemenata: %ld\n", p - a);
    
    /*k = binarna_pretraga2(a,0,n-1,x);
    
    if(k == -1)
        printf("Nema tog elementa\n");
    else 
        printf("Pozicija elemenata: %d\n", p); */
    
    
    free(a);
    
    return 0;
}
