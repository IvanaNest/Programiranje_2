#include <stdio.h>
#include <stdlib.h>

void greska() {
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

int main() {
    FILE * ulaz;
    int brojac=0;
    char c;
    
    ulaz = fopen("knjiga.txt", "r");
    if(ulaz == NULL) {
        greska();
    }
    
    while((c = fgetc(ulaz)) != EOF) {
       if(c == '\n')  
        brojac ++;
    }
    
    
    printf("%d\n", brojac);
    
    
    
    fclose(ulaz);
return 0; } 
