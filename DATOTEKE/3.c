#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]) {
    int i,j;
    
    for(i=0; i<argc; i++) {
        if(argv[i][0] == '-') {
            for(j=1; argv[i][j] != '\0'; j++) {
                printf("%c", argv[i][j]);
            }
            
            printf("\n");
        }
    }
    
return 0 ; }
    
