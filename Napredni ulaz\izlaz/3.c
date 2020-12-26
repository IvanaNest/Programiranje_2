#include <stdio.h>
#include <stdlib.h>

void greska() {
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}
int main () {
    int n,i,j;
    FILE * izlaz;
    char naziv_fajla[51];
    
    scanf("%d", &n);
    if(n<0 || n>100)
        greska();
    
    for(i=1; i<=n; i++) {
        sprintf(naziv_fajla, "%d.txt", i);
        
        izlaz = fopen(naziv_fajla, "w");
        if(izlaz == NULL) 
            greska();
    
        for(j=0; j<= n; j+=i) {
            fprintf(izlaz, "%d ", j);
        }
        
        fclose(izlaz);
    }
    
    
return 0; }
