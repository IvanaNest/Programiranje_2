#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX1 21
#define MAX2 51

void greska()
{
    fprintf(stderr,"-1\n");
    exit(EXIT_FAILURE);
}

typedef struct {
    char bar_kod[MAX1];
    char ime_artikla[MAX2];
    char proizvodjac[MAX2];
    float cena;
}PRODAVNICA;

int poredi(const void * kljuc, const void * pr)
{
    char * kljuc1 = (char *)kljuc;
    PRODAVNICA * pr1 = (PRODAVNICA *)pr;
    
    return strcmp(kljuc1,pr1->bar_kod);
}
int main()
{
    FILE * ulaz;
    char datoteka[MAX2];
    PRODAVNICA *niz;
    int i;
    float ukupna_cena =0;
    char  kod[MAX1];
    PRODAVNICA *p;
    
    scanf("%s", datoteka);
    
    ulaz = fopen(datoteka, "r");
    if (ulaz == NULL)
        greska();
    
    int alocirano = 1;
    niz = malloc(alocirano * sizeof(PRODAVNICA));
    if(niz == NULL)
        greska();
    
    for(i=0; ;i++){
        if(fscanf(ulaz, "%s %s %s %f", niz[i].bar_kod, niz[i].ime_artikla, niz[i].proizvodjac, &niz[i].cena) == EOF)
            break;
        
        alocirano ++;
        niz = realloc(niz,alocirano * sizeof(PRODAVNICA));
        if(niz == NULL)
            greska();
    }
    
    while(1){
        scanf("%s", kod);
        if(strcmp(kod,"0") == 0)
            break;
        
        if((p=bsearch(kod,niz,i,sizeof(PRODAVNICA),&poredi)) == NULL)
            printf("Nepostojeci bar kod\n");
        else ukupna_cena += p->cena;
    }
        
        
    printf("%g\n", ukupna_cena);
    
    
        
        
        
    
    fclose(ulaz);
    free(niz);
    return 0;
}
