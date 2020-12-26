#include <stdio.h>
#include <stdlib.h>

void greska() {
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

int main() {
    int n;
    int * a;
    
    scanf("%d", &n);
    if(n<0) 
        greska();
    
    
    
    a= (int *)malloc(n*sizeof(int));
    
    if(a == NULL) 
        greska();
    
    int i;
    
    for(i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }
    
    for(i= n-1; i>=0; i-- ) {
        printf("%d ", a[i]);
    }
    
    free(a);
    
return 0; }
    
    
    
    
    
    
    
