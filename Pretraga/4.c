#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 21

void greska()
{
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

typedef struct {
    char ime[MAX];
    char prezime[MAX];
    char smer;
    double prosek;
}STUDENT;

int poredi(const void * a, const void *b)
{
    char * a1 = (char *)a;
    STUDENT * b1 = (STUDENT *)b;
    
    return strcmp(a1,b1->prezime);
}

int main() 
{
    FILE * ulaz;
    int n,i;
    char trazeno_prez[MAX];
    STUDENT  * niz;
    STUDENT * p;
    
    
    ulaz = fopen("studenti.txt", "r");
    if(ulaz == NULL)
        greska();
    
    fscanf(ulaz, "%d", &n);
    if(n < 0)
        greska();
    
    niz = malloc(n * sizeof(STUDENT));
    if(niz == NULL)
        greska();
    
    scanf("%s", trazeno_prez);
    
    for(i=0; i < n; i++)
        fscanf(ulaz, "%s%s %c%lf", niz[i].ime, niz[i].prezime, &niz[i].smer, &niz[i].prosek);
    
    p = bsearch(trazeno_prez,niz, n, sizeof(STUDENT), &poredi );
    
    if(p == NULL)
        printf("Nema studenata sa prezimenom %s\n", trazeno_prez);
    else printf("%s %s %c %g\n", p->ime, p->prezime, p->smer, p->prosek);
    
    i=1;
    while(strcmp(p->prezime,(p + i)->prezime) == 0) {                                            //ispisuje sve osobe sa istim prezimenom
        printf("%s %s %c %g\n", (p+i)->ime, (p+i)->prezime, (p+i)->smer, (p+i)->prosek);
        i++;
    }
    
    i=1;
    while(strcmp(p->prezime,(p - i)->prezime) == 0) {
        printf("%s %s %c %g\n", (p-i)->ime, (p-i)->prezime, (p-i)->smer, (p-i)->prosek);
        i--;
    }
    
    free(niz);
    fclose(ulaz);
    return 0;
}
