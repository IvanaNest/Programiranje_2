#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void greska() {
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}
void provera_razlomaka(char * a) {
    int i;
    
    for(i=0; a[i] != '\0'; i++) {
        if(!(isdigit(a[i])) && a[i] != '/') {
            greska();
        }
        
    }
        if(a[0] == '/' || a[i-1] == '/') {
            greska();
        }
}
    
int main(int argc, char **argv) {
    
    int i=0;
    int brojilac, imenilac;
    
    for(i=1; i<argc; i++) {
        provera_razlomaka(argv[i]);
    }
    
    for(i=1; i<argc; i++) {
        sscanf(argv[i],"%d/%d", &brojilac, &imenilac);
        printf("%.2f ", (float)brojilac/imenilac );
    }
    
return 0; }
