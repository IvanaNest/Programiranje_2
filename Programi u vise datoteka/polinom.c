#include <stdio.h>
#include <stdlib.h>
#include "polinom.h"

void greska() {
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

int * unos (int * n) {              //n stepen polinoma
    scanf("%d", n);
    
    int *p;
    
    p = calloc((*n+1), sizeof(int) );
        if(p == NULL) 
            greska();
        
    int i;
    
    for(i=0; i <= *n; i++) {
        scanf("%d", &p[i]);
    }
    
    return p;
}

void ispis_polinoma(int *a, int n) {
    int i;
    int k=n;
    int brojac=0;
    
    for(i=0; i<= n; i++) {
        if( a[i] != 0 ) {
            
            if(i == 0) {
                if(a[i] < 0) {
                    printf("- %d ",abs(a[i]));
                } else {
                    printf("%d ", abs(a[i]));
                }
            }
            
            if( i == 1) {
                    if(a[i] < 0) {
                        printf("- %d*x ", abs(a[i]));
                    } else {
                        if(brojac == 0) {
                            printf("%d*x ", abs(a[i]));
                        }
                        if(brojac != 0) {
                            printf("+ %d*x ", abs(a[i]));
                        }
                    }
            }
            
            if( i> 1) {
                if(a[i] < 0) {
                    printf("- %d*x^%d ", abs(a[i]), i);
                } else {
                    if(brojac == 0) {
                        printf("%d*x^%d ", abs(a[i]), i);
                    }
                
                    if(brojac != 0) {
                        printf("+ %d*x^%d ", abs(a[i]), i);
                    }
                }
            }
            
            
            brojac ++ ;
        }
    }
}
    
int max(int a, int b) {
        if(a > b) {
            return a;
        } else 
            return b;
}

int suma_polinoma(int* a, int n, int* b, int m, int** r) {
    int i,j;
    int k;
    
    k = max(n,m);
    int *c = NULL;
    c = calloc(k+1, sizeof(int *));
    if(c == NULL) 
        greska();
    
    for(i = 0; i<= n && i<= m ; i++) {
        c[i] = a[i]+b[i];
    }
    
    if(i<= n && i>m) {
        for(i; i<=n; i++) {
            c[i] = a[i];
        }
    }
    
    if(i<= m && i>n) {
        for(i; i<=m; i++) {
            c[i] = b[i];
        }
    }
    *r = c; 
    
return k;
}
            
    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
    
