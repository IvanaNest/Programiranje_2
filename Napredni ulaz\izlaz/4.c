#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 21

void greska() {
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

int main(int argc, char ** argv) {
    if(argc != 2) 
        greska();
    
    FILE * ulaz;
    
    char * linija = NULL;
    unsigned long duzina_linije = 0;
    
    int procitano, k, brojac, n;
    
    char rec[MAX], uneta_rec[MAX];
    
    
    scanf("%d%s", &n, rec);
    
    ulaz = fopen (argv[1], "r");
    if(ulaz == NULL)
        greska();
    
    
    while(getline(&linija, &duzina_linije, ulaz) != EOF)
    {
      procitano = 0;
      brojac = 0;
      
       while(sscanf(linija + procitano, "%s%n", rec, &k) != EOF)
      {
        procitano += k;
        if(strcmp(rec, uneta_rec) == 0)
          brojac++;
      }
      
      if(brojac == n)
        printf("%s", linija);
    }
    
    fclose(ulaz);
    free(linija);
      
return 0; }
                    
                    
                    
                    
                    
                    
                    
                    
                    
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
    
    
