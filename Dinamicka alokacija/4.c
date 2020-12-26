#include <stdio.h>
#include <stdlib.h>

void greska() {
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

void alociraj (int ***a, int n, int m) {
    int i;
    *a= (int **)malloc(n*sizeof(int*));
    if(a == NULL)
        greska();
    
    for(i=0; i<n; i++) {
        (*a)[i] = (int *) malloc(m* sizeof(int));
        if((*a)[i] == NULL)
            greska();
    }
    
}

void ucitaj_matricu(int ** a, int n, int m) {
    int i,j;
    
    for(i=0; i<n; i++) {
        for (j=0; j<m; j++) {
            scanf("%d", &a[i][j]);
        }
    }
}

void ispisi_matricu(int ** a, int n, int m) {
    int i,j;
    
    for(i=0; i<n ; i++) {
        for(j=0; j<m; j++) {
            printf("%d ", a[i][j] );
        }
        printf("\n");
    }
}

void oslobodi(int ***a, int n, int m) {
    int i;
    
    for(i=0; i<n; i++) {
        free((*a)[i]);
    }
    
    free(*a);
}

int main() {
    int **a;
    int n,m;
    
    scanf("%d%d", &n, &m);
    
    alociraj(&a, n, m );
    
    ucitaj_matricu(a, n, m);
    
    ispisi_matricu(a,n,m);
    
    oslobodi(&a, n ,m);
return 0; }
    
