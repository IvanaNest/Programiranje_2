#include <stdio.h>
#include <stdlib.h>

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

void jedinica_na_k(int n, unsigned int k )         //2.c
{
    unsigned int maska = 1;
    maska = maska << k;
    
    if(n & maska)
        printf("jeste\n");
    else printf("nije\n");
}

int stavi_jedinicu(int n, unsigned int k)     //3.c
{
    unsigned int maska = 1;
    maska <<= k;
    
    return n | maska;
}
int main()
{
    int n;
    unsigned int k;
    //scanf("%d", &n);
    //scanf("%u", &k);
    
    //print_bits(n);
    
    //if(k<0 || k>31)
        //greska();
    
    //jedinica_na_k(n,k);
    //printf("%d\n", stavi_jedinicu(n,k));
    print_bits(1431655765);
    
    
    
    
    return 0;
}
