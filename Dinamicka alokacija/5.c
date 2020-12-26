#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 21

void greska() {
    fprintf(stderr, "-1\n");
    exit (EXIT_FAILURE);
}

int main () {
    int dimenzija;
    char *pretraga;
    char **niz_reci;
    int prva=0, poslednja=0;
    int i;
    
    pretraga =(char *) malloc(MAX * sizeof(char));
    if(pretraga == NULL ) 
        greska();
    
    scanf("%s", pretraga);
    
    scanf("%d",&dimenzija);
    
    if(dimenzija < 1) 
        greska();
    
    niz_reci = (char **) malloc(dimenzija * sizeof(char*));
    if(niz_reci == NULL) 
        greska();
    
    for(i=0; i<dimenzija; i++) {
        niz_reci[i] = (char *) malloc(MAX * sizeof(char));
        if(niz_reci[i] == NULL) {
            greska();
        }
    }
    
    
    
    for(i=0; i<dimenzija; i++) {
        scanf("%s", niz_reci[i]);
        
        if( strcmp(pretraga, niz_reci[i]) == 0 ) {
            if(prva == 0) {
                prva = i;
            }
            
            poslednja = i;
            
        }
    }
    
    if(prva == 0) {
        printf("-1 -1\n");
        return 0;
    }
    
    printf("%d %d\n", prva, poslednja);
    
    free(pretraga);
    
    for(i=0; i<dimenzija; i++) {
        free(niz_reci[i]);
    }
    
    free(niz_reci);
    
return 0; }
    
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
    
    
    
