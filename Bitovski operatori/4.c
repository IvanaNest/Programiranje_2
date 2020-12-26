#include <stdio.h>
#include <stdlib.h>
#define VELICINA 8 * sizeof(int) - 1

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

void greska()
{
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}


int suma_bitova (int n)                //4.c
{
    unsigned int maska = 1;
    maska = maska << (VELICINA);
    
    int suma = 0;
    
    while(maska) {
        if(maska & n)
            suma ++;
        maska >>= 1;
    }

    return suma;
    
        
}
//0000111110000
unsigned get_bits(int x, int p, int n)        //5.x
{
    unsigned int maska1;
    maska1 = (~(~0 <<n)) <<p;
    
    return (maska1 & x);
    
    
}

unsigned set_bits(unsigned x, int p, int n, unsigned y)
{
    unsigned int maska1, maska2;
    maska1 = ~(~0 << n);
    
    maska2 = ~((~(~0 <<n)) <<p);
    
    unsigned int bitovi = maska1 & y;
    bitovi = bitovi << p;
    
    unsigned int bez_bitova = x & maska2;
    
    return bez_bitova | bitovi;
    
}

unsigned invert_bits(unsigned x, int p, int n)            //7.c
{
    unsigned int maska1;
    maska1 = (~(~0 << n)) << p;
    unsigned int bitovi = maska1 & x;
    unsigned int invertovani_bitovi = maska1 ^ bitovi;
    
    maska1 = ~maska1;
    
    unsigned int bez_bitova = maska1 & x;
    
    return bez_bitova | invertovani_bitovi;
}

unsigned right_rotate(unsigned x, int n)
{
    int i;
    unsigned int maska1 = 1;
    unsigned int maska2 = maska1 << (VELICINA);
    
    for (i=0; i<n; i++) {
        if(maska1 & x) {
            x = x >> 1;
            x = x | maska2;
        }
        
        else x = x >> 1;
    }
    
    return x;
            
}

unsigned mirror(unsigned x) 
{
    unsigned int maska1 = 1;
    unsigned int maska2 = maska1 << (VELICINA);
    unsigned rezultat = 0;
    
    while(maska1) {
        if(maska1 & x) 
            rezultat = rezultat | maska2;
        
        maska1 <<= 1;
        maska2 >>=1;
    }
        
        
    return rezultat;        
            
        
}
int main()
{
    unsigned x;
    //int y;
    //int p;
    //int n;
    unsigned int k;
    scanf("%u", &x);
    //scanf("%d", &n);
    
    //if(n<0)
        //greska();
    
    //n = n % ((VELICINA)+1);
    
   // k = right_rotate(x,n);
    
    //scanf("%d%d", &n,&p );
   // if(p<0 || n<0 || p+n >= (VELICINA))
       // greska();
    
    //k = get_bits(x,p,n);
    
    //k = set_bits(x,p,n,y);

    //printf("%d\n", suma_bitova(x));
    //k = invert_bits(x,p,n);
    k = mirror(x);
    print_bits(x);
    print_bits(k);
    
    return 0;
}
