#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DUZINA 201

void greska() {
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}


int main (int argc, char * argv[]) {
    FILE * ulaz1, *ulaz2;
    
        if(argc != 3) {
            greska();
        }
    ulaz1 = fopen(argv[1], "r");
    ulaz2 = fopen(argv[2], "r");
    
    
    if(ulaz1 == NULL || ulaz2 == NULL) {
        greska();
    }
    
    char linija1[MAX_DUZINA], linija2[MAX_DUZINA];
    int i=0;
    
    char *d1, * d2;
    
    d1 = fgets(linija1, MAX_DUZINA, ulaz1);
    d2 = fgets(linija2, MAX_DUZINA, ulaz2);
    
    while(d1 != NULL && d2 != NULL) {
        if(strcmp(linija1, linija2) != 0) {
            printf("%d ", i);
        }
        
    d1 = fgets(linija1, MAX_DUZINA, ulaz1);
    d2 = fgets(linija2, MAX_DUZINA, ulaz2);    
    
    i++;
  }
  
  while(d1 != NULL)
  {
    printf("%d ", i);
    d1 = fgets(linija1, MAX_DUZINA, ulaz1);
    i++;
  }
  
  while(d2 != NULL)
  {
    printf("%d ", i);
    d2 = fgets(linija2, MAX_DUZINA, ulaz2);
    i++;
  }
        
        
        
        
  fclose(ulaz1);
  fclose(ulaz2);
  
return 0; }
        
        
        
        
    
