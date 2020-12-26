#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 51

void greska ()
{
    fprintf(stderr,"-1\n");
    exit(EXIT_FAILURE);
}
// ivana ana dragana petra
void insertion_sort(char ** a, int n)
{
    int i,j;
    char priv[MAX];
    
    for(i=1; i<n; i++) {
        for(j=i;j>0 && strcmp(a[j],a[j-1])<0; j--) {
            strcpy(priv,a[j-1]);
            strcpy(a[j-1],a[j]);
            strcpy(a[j],priv);
        }
    }
}

int nadji_min(char **niz, int n)
{
    char minimum[MAX];
    strcpy(minimum,niz[0]);
    int i;
    int indeks=0;
    
    for(i=0; i<n; i++)  {
        if(strcmp(niz[i], minimum) < 0) {
            strcpy(minimum,niz[i]);
            indeks = i;
        }
    }
    
    return indeks;
            
}

void razmeni(char **niz, int n, int indeks) 
{
    char tmp[MAX];
    strcpy(tmp,niz[0]);
    strcpy(niz[0], niz[indeks]);
    strcpy(niz[indeks], tmp);
}
void selection_sort(char ** a, int n)
{
    if(n==1)
        return;
    int indeks;
    indeks = nadji_min(a,n);
    razmeni(a,n,indeks);
    selection_sort(a+1,n-1);
}


void merge(char **a, int n1, char **b, int n2, char ** pomocni)
{
    int i=0,j=0,k=0;
    
    while(i<n1 && j<n2) {
        if(strcmp(a[i],b[j]) < 0)
            strcpy(pomocni[k++],a[i++]);
        else strcpy(pomocni[k++],b[j++]);
    }
    
    while(i<n1)
        strcpy(pomocni[k++],a[i++]);
    
    while(j<n2)
        strcpy(pomocni[k++],b[j++]);
    
}
void merge_sort(char ** a, int levo, int desno, char ** pomocni)
{   
    if(levo >= desno)
        return;
    
    int n = desno - levo + 1;
    int srednji = levo + n/2;
    int n1 = srednji - levo, n2 = n - n1;
    
    merge_sort(a,levo, srednji - 1, pomocni);
    merge_sort(a,srednji, desno, pomocni);
    
    merge(a+levo,n1,a+srednji,n2,pomocni);
    
    int i,j;
    for(i=levo,j=0; i<=desno; i++,j++)
        strcpy(a[i],pomocni[j]);
    
    
}
// aba bojan dragana     bojan ivana sanja         ana
int particionisanje(char ** niz, int levo, int desno) {
    char pivot[MAX];
    
    strcpy(pivot,niz[levo]);
    
    while(levo < desno) {
        while(strcmp(niz[desno],pivot) >= 0 && levo<desno)
            desno --;
        
        if(levo != desno)
            strcpy(niz[levo ++],niz[desno]);
        
        while(strcmp(niz[levo],pivot) <= 0 && levo<desno)
            levo++;
        
        if(levo != desno)
            strcpy(niz[desno--], niz[levo]);
    }
    
    strcpy(niz[levo], pivot);
    
    return levo;
}
        
        
    
void quick_sort(char ** niz, int levo, int desno )
{
    if(levo >= desno)
        return;
    
    int poz_pivota = particionisanje(niz,levo,desno);
    quick_sort(niz,levo, poz_pivota - 1);
    quick_sort(niz, poz_pivota+1, desno);
}
int main()
{
    int n,i;
    char ** niz;
    char **pomocni;
    
    scanf("%d", &n);
    if(n < 1)
        greska();
    
    niz = malloc (n * sizeof (char *));
    if(niz == NULL)
        greska();
    
    for(i=0; i<n; i++) {
        niz[i] = malloc(MAX * sizeof(char));
        if(niz[i] == NULL)
            greska();
    }
    
    pomocni= malloc (n * sizeof (char *));
    if(pomocni == NULL)
        greska();
    
    for(i=0; i<n; i++) {
        pomocni[i] = malloc(MAX * sizeof(char));
        if(pomocni[i] == NULL)
            greska();
    }
    
    
    
    for(i=0; i<n; i++) 
        scanf("%s", niz[i]);
    
    //insertion_sort(niz,n);
    //selection_sort(niz,n);
    //merge_sort(niz,0,n-1,pomocni);
    quick_sort(niz,0,n-1);
    for (i=0; i<n; i++)
        printf("%s ", niz[i]);
    
    printf("\n");
    
    for(i=0; i<n; i++)
        free(niz[i]);
    
    
    free(niz);
    
    for(i=0; i<n; i++)
        free(pomocni[i]);
    
    
    free(pomocni);
    return 0;
}
