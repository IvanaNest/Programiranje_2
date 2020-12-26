#include <stdio.h>
#include <stdlib.h>

void greska()
{
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

typedef union broj {
    int int_vrednost;
    float float_vrednost;
} BROJ;

void stepen_dvojke(int x)
{
    int brojac = 0;
    unsigned int maska = 1;
    if(x & maska) {
        printf("NIJE\n");
        return;
    }
    
    maska <<=1;
    
    while(maska) {
        if(maska & x) 
            brojac++;
        
        if(brojac > 1) {
            printf("NIJE\n");
            return;
        }
        
        maska <<=1;
    }
    
    printf("JESTE\n");
        
        
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

int broj_parova(int x) 
{   
    int brojac = 0;
    unsigned int maska = 3;
    unsigned int maska2 = 0;
    maska2 = maska2 | x;
    
    while(maska2) {
        if((maska & maska2) == 3)
            brojac ++;
        
        maska2 >>=1;
    }
    
    return brojac;
    
}

unsigned najveci_broj(int x) 
{
    
    unsigned int maska1 = 1;
    unsigned int maska2 = 1 << (sizeof(int) * 8 - 2);
    unsigned rezultat = 0;
    
    while(maska1) {
        if(maska1 & x) {
            rezultat >>=1;
            rezultat = rezultat | maska2;
        }
        
        maska1 <<=1;
        
    }
    
    return rezultat;
}

unsigned najmanji_broj(int x)
{
    unsigned int maska1 = 1 << (sizeof(int) * 8 -1);
    unsigned int maska2 = 1;
    unsigned int rezultat = 0;
    
    while(maska1) {
        if(maska1 & x) {
            rezultat = rezultat | maska2;
            maska2 <<=1;
        }
    
        maska1 >>=1;
    }
    
    
    return rezultat;
    
}

int main()
{
    /*int n;
    
    scanf("%d", &n);
    
    printf("%u\n", najmanji_broj(n));
    
    //printf("%d\n", broj_parova(n));
    
    //stepen_dvojke(abs(n));
    print_bits(n); */
    
    BROJ a;
    scanf("%f", &a.float_vrednost);
    print_bits(a.int_vrednost);
    return 0;
}
