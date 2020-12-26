#include <stdio.h>
#include <stdlib.h>

void greska(const char * s) 
{
    fprintf(stderr, "%s\n", s);
    exit(EXIT_FAILURE);
}

int uvecaj(int x) 
{
    return x + 1;
}

int kvadrat(int x)
{
    return x * x;
}

int suprotan(int x) 
{
    return x*(-1);
}

void unesi_niz(int * a, int n) 
{
    int i;
    for(i = 0; i<n; i++) {
        scanf("%d", &a[i]);
    }
}

void ispisi_niz(int *a, int n)
{
    int i;
    for(i=0; i<n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void modifikuj (int * a, int n, int(*f)(int) )
{
 int i;
 for(i=0; i<n; i++) {
     a[i] = (*f)(a[i]);
 }
 
 ispisi_niz(a,n);
}
    
int main ()
{ 
    int n;
    int *s;
    
    scanf("%d", &n);
    
    s = (int *) malloc(n * sizeof(int));
    if (s == NULL)
        greska("Malloc...");

    unesi_niz(s, n);
    
    modifikuj(s, n, &kvadrat);

    
    
return 0;    
}
