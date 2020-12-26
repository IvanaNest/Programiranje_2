#include <stdio.h>
#include <stdlib.h>

void greska() {
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
    
}

int main(int argc, char **argv) {
    FILE *ulaz;
    int k;
    int *niz;
    int i=0, alocirano;
    
    if(argc != 2) {
        greska();
    }
    
    k = atoi(argv[1]);
    if (k < 1) 
        greska();
    
    ulaz = fopen("brojevi.txt", "r");
    if(ulaz == NULL) 
        greska();
    
    niz = (int *) malloc(k*sizeof(int));
    alocirano = k;
    
    while(1) {
        
        if(alocirano == i) {
            alocirano += k;
            
            niz= (int *) realloc(niz,alocirano*sizeof(int));
            if(niz == NULL) 
                greska();
        }
            
        fscanf(ulaz, "%d", &niz[i]);
        
        if(niz[i] == 0) {
            break;
        }
        
        i++;
    }
    
    int n = i;
    
    
    float srednji;
    if(n%2 == 0)
        srednji = (niz[n/2-1] + niz[n/2])/2.0;
    else
        srednji = niz[n/2];
  
    for(i=0; i<n; i++) {
        if(niz[i] > srednji) {
            printf("%d ", niz[i]);
            printf("\n");
        }
    }
  
  free(niz);
 
  fclose(ulaz);
  return 0;

    
        
    

return 0; }
