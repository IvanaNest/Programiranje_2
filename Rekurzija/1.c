#include <stdio.h>
#include <stdlib.h>

void greska() {
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

void ispis1 (int x) {
    
    if( abs(x) < 10 ) {
            
        printf("%d ", x);
        return ;
    }
    
    ispis1(abs(x) / 10);
    printf("%d ", abs(x) % 10);
}

void ispis2 (int x) {
    
    if( x < 10) {
        printf("%d ", x);
        return;
    }
    
    printf("%d ", x%10);
    ispis2(x/10);
}

int broj_parnih(int x) {
    
    if(x < 10) {
        if(x%2 == 0)
            return 1;
        else return 0;
    }
    
    if( x%2 == 0) {
        return 1 + broj_parnih(x / 10);
    } else {
        return broj_parnih(x/10);
    }
}

int najveca_cifra(int x) {
    if( x < 10) {
        return x; 
    }
    
    int najveca_levo = najveca_cifra(x/10);
    
    if( x%10 > najveca_levo) {
        return x%10;
    } else {
        return najveca_levo;
    }
}
    
int ukloni(int x, int c) {
    if( x < 10) {
        if(x == c)
            return 0;
        else return x;
    }
    
    int levo = ukloni(x/10,c);
    
    if(x%10 == c) {
        return levo;
    } else {
        return levo * 10 + x%10;
    }
}

int duzina_broja(int x) {
    
    if( x < 10) 
        return 1;
    
    return 1 + duzina_broja(x / 10);
}

void napravi_niz(int * kraj_niza, int broj) {
    if( broj < 10) {
        kraj_niza[0] = broj;
        return ;
    }
    
    kraj_niza[0] = broj%10;
    
    napravi_niz(kraj_niza - 1, broj / 10);
}

void ispisi_niz(int * niz, int n) {
    
    if(n == 0) {
        printf("\n");
        return ;
    }
    
    printf("%d ", niz[0]);
    ispisi_niz(niz + 1, n-1);
}
    
int obrni(int x, int p) {
       if(x < 10) {
           return p + x;
       }
       p += x%10;
       x /= 10;
       obrni(x, p*10);
}

void obrni_niz(int *a, int n){
    if(n < 3) {
        int tmp = a[0];
        a[0] = a[n-1];
        a[n-1] = tmp;
        return ;
    }
    
    int tmp = a[0];
    a[0] = a[n-1];
    a[n-1] = tmp;
    
    obrni_niz(a+1, n-2);
}

int palindrom(int* a, int n) {
    if(a[0] != a[n-1]) {
        printf("Nije palindrom\n");
        return 0;
    }
    
    if(n < 3) {
        printf("Jeste palindrom\n");
        return 1;
    }
    
    palindrom(a+1, n-2);
}
                                    
int dodaj_0 (int x) {
    if (x < 10) {
        if(x%2 == 0) 
        return x;
         else 
            return x*100;
    }
    
    if(x%2 == 0) 
        return x%10 + dodaj_0(x/10)*10;
    else return x%10*100 + dodaj_0(x/10)*1000;     
}

int skalarni_proizvod(int * a, int * b, int n) {
    if(n == 1 ) {
        return a[0]*b[0];
    }                                                            
    
    return a[0] * b[0] + skalarni_proizvod(a+1,b+1, n-1);
}

void trougao(int n, int trenutna_linija){
    int i = 0;
    if(trenutna_linija == n) {
        while(i<n) {
            printf("*");
            i++;
        }
        
        printf("\n");
        return;
    }
    
    while(i < (n-trenutna_linija)) {
        printf(" ");
        i++;
    }
    
    while(i<n) {
        printf("*");
        i++; 
    }
    
    printf("\n");
    trougao(n, trenutna_linija + 1);
}
    
    
int main() {
    int  * x;
    int * y;
    int n,m;
    int p=1;
    
    scanf("%d", &n);
    trougao(n,p);
   /* x = malloc(duzina_broja(n) * sizeof(int));
    if (x == NULL)
        greska();
    
    y = malloc(duzina_broja(m) * sizeof(int));
    if (y == NULL ) 
        greska();

    printf("%d", dodaj_0(n) );
    napravi_niz(x+duzina_broja(n)-1, n);
    napravi_niz(y+duzina_broja(m)-1, m);
    
    printf("%d", skalarni_proizvod(x,y,duzina_broja(n)));
    palindrom(x, duzina_broja(n));
    obrni_niz(x, duzina_broja(n));
    ispisi_niz(x, duzina_broja(n));      */

return 0;
}
