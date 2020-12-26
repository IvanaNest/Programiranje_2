#include <stdio.h>
#include <stdlib.h>

#define MAX_LINIJA 81

void greska() {
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}
    

int main () {
    FILE * ulaz, * izlaz;
    char linija[MAX_LINIJA];
    char c;
    
    ulaz = fopen("ulaz.txt", "r");
    if(ulaz == NULL) {
        greska();
    }
    
    izlaz = fopen("izlaz.txt", "w");
    if(izlaz == NULL) {
        greska();
    }
    
    // karakter po karakter - 1.nacin
    
   /*
    while(fscanf(ulaz, "%c", &c) != EOF) {
        fprintf(izlaz, "%c", c );
    }
    */
        
    //karakter po karakter - 2. nacin
   
   /*while((c = fgetc(ulaz)) != EOF) {
        fputc(c,izlaz);
    }
   */
   
   //linija po linija
   while(fgets(linija, MAX_LINIJA, ulaz) != NULL) {
       fprintf(izlaz, "%s", linija);
   }
   
    
    
   fclose(ulaz);
   fclose(izlaz);
   
return 0; }
