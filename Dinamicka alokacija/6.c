#include <stdio.h>
#include <stdlib.h>

void greska() {
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
    
}

typedef struct{
    unsigned int a, b;
    char ime[5];
    } PRAVOUGAONIK;
    
int ucitaj_pravougaonik (PRAVOUGAONIK * A, FILE * ulaz) {
    if (fscanf(ulaz, "%d%d", &A->a, &A->b) == EOF) {
        return -1;
    }
    
    if(fgets(A->ime, 5, ulaz ) == NULL)
        return -1;
    
    return 1;
}
        
    
int main(int argc, char ** argv) {
    
    FILE * ulaz;
    int alocirano=1;
    PRAVOUGAONIK * niz;
    int i,m;
    
    if(argc != 2) 
        greska();
    
    ulaz = fopen(argv[1], "r");
    if(ulaz == NULL) {
        greska();
    }
    
    niz  = (PRAVOUGAONIK *) malloc(alocirano * sizeof(PRAVOUGAONIK));
    
    for(i=0; ; i++) {
        m = ucitaj_pravougaonik(&niz[i], ulaz);
        if(m == -1) 
            break;
    
        alocirano ++;
    
        niz = (PRAVOUGAONIK *) realloc(niz, alocirano * sizeof(PRAVOUGAONIK));
    
    }
    
    int max_pravougaonik=0;
    int trenutni;
    
    for(i=0; i < (alocirano-1); i++) {
        if(niz[i].a == niz[i].b) {
            printf("%s ", niz[i].ime);
        } else {
            if( (trenutni = (niz[i].a * niz[i].b)) > max_pravougaonik) {
                max_pravougaonik = trenutni;
            }
        }
        
        
    }
    printf("%d\n",max_pravougaonik);
        
    
    
    
    free(niz);
    
    fclose(ulaz);
    
    return 0; }
    
