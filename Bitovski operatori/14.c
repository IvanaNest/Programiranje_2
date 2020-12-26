#include <stdlib.h>
#include <stdio.h>

#define VELICINA (sizeof(int) * 8 -1)
void greska()
{
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

void print_bits(int x) {              //1.c
    
    unsigned int maska = 1;
    maska = maska << (8 * sizeof(int) - 1);
    
    while(maska) {
        if(maska & x)
            printf("1");
        else printf("0");
        
        maska = maska >> 1 ;
    }
    
    printf("\n");
}
// 1001 1011 1111 1010 1110 1000 0010 0011
// 1111  
void ispisi_heksadekadni(unsigned x)
{
    int maska1 = 1 << VELICINA;
    
    maska1 >>=3;
    
    unsigned maska2 = 0;
    maska2 = maska2 | maska1;
    unsigned maska3;
    
    int i = 7;
    
    while(maska2) {
        maska3 = 0;
        
        maska3 = x & maska2;
        maska3 = maska3 >> (sizeof(int)*i);
        
        if(maska3 < 10) {
            printf("%u", maska3);
        }
        
        
        if(maska3 > 9) {
            printf("%c", 'A' + maska3 - 10);
        }
        i--;
        maska2 = maska2 >> (sizeof(int));
    }
    
    printf("\n");
}

unsigned napravi(unsigned * niz, int n) 
{
    int i;
    
    unsigned maska = 1;
    unsigned x = 0;
    
    for(i=0; i<n; i++) {
        x = x | (niz[i] & maska);
        maska <<= 1;
    }
    
    return x;
    
}
// 1001 1011 1111 1010 1110 1000 0010 0011
// 1001 1011 1111 1010 1110 1000 0010 0011
unsigned poredi(unsigned * niz, int n, unsigned x)
{
    int i;
    unsigned maska = 1;
    unsigned broj1, broj2;
    unsigned y = 0;
    
    for(i=0; i<n; i++) {
       broj1 = maska & niz[i];
       broj2 = maska & x;
       
       if( (broj1 ^ broj2) == 0 )
           y = y | maska;
       
       maska <<= 1;
      
    }
    
    while(maska) {
        broj1 = 0;
        broj2 = maska & x;
        
        if( (broj1 ^ broj2) == 0 )
           y = y | maska;
       
       maska <<= 1;
    }
        
    
    return y;
}
int main ()
{
    /*unsigned x;
    
    scanf("%u", &x);
    
    ispisi_heksadekadni(x); */
    
    int n;
    unsigned  * niz;
    unsigned x;
    
    scanf("%u", &x);
    scanf("%d", &n);
    if(n > 32 || n < 0)
        greska();
    
    niz = malloc(sizeof(unsigned) * n);
    if(niz == NULL)
        greska();
     
    int i;
    unsigned k;
    
    for(i=0; i<n; i++) {
        scanf("%u", &niz[i]);
    }
    
    //k = napravi(niz,n);
    k = poredi(niz,n,x);
    
    printf("%u\n", k);
    free(niz);
    return 0;
    
}
