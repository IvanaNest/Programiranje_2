#include <stdio.h>
#include <stdlib.h>

void greska()
{
    fprintf(stderr,"-1\n");
    exit(EXIT_FAILURE);
}
//1 5 3 2 4

int poredi_rastuce(int a, int b)
{
    if(a<b)
        return 1;
    else return 0;
}

int poredi_opadajuce(int a, int b) {
    if(a>b)
        return 1;
    else return 0;
}

void insertion_sort(int * A, int n, int (*poredi)(int,int) )
{
    int i,j;
    for(i=1; i<n; i++) {
        for(j=i; j>0 && (*poredi)(A[j],A[j-1]); j--) {      
            int tmp = A[j-1];
            A[j-1] = A[j];
            A[j] = tmp;
        }
    }
}

int nadji_min(int * A, int n, int (*poredi)(int,int))        //max za opadajuci
{
    int i;
    int m = A[0];
    int m_koef = 0;
    
    for(i=0; i<n; i++) {
        if((*poredi)(A[i],m)) {
            m = A[i];
            m_koef = i;
        }
    }
    
    return m_koef;
}

void razmeni (int * A, int n, int m)
{
    int temp = A[0];
    A[0] = A[m];
    A[m] = temp;
}

//1 5 9 8 2
//1 5   9 8 2
//l d 
//1   5   9  8  2
  

void selection_sort(int * A, int n, int (*poredi)(int,int))
{
    if(n == 1)
        return;
    
    int min = nadji_min(A,n,poredi);
    razmeni(A,n,min);
    
    selection_sort(A+1, n-1,poredi);
    
}
// 1  4   2 3 5

void merge(int * A, int n1, int * B, int n2, int * P, int (*poredi)(int,int))
{
    int i=0, j=0,k=0;
    
    while(i<n1 && j<n2) {
        if((*poredi)(A[i],B[j])) 
            P[k++] = A[i++];
        else 
            P[k++] = B[j++];
    }
    
    while(i<n1) 
        P[k++] = A[i++];
    
    while(j < n2)
        P[k++] = B[j++];
        
            
}


void merge_sort(int * A, int l, int d, int * pom, int (*poredi)(int,int)) 
{
    if(l>=d)
        return;
    
    int n = d - l + 1;
    int s = l + n/2;
    int n1 = s - l; int n2 = n - n1;
    
    merge_sort(A, l,s-1, pom,poredi);
    merge_sort(A,s,d,pom,poredi );
    
    merge(A+l, n1, A+s, n2, pom,poredi);
    
    int i,j;
    
    for(i=l,j=0; i<=d; i++,j++)
        A[i] = pom[j];
}
// 2 4 4 7 5  3          2 3 5 6 7 9    3
//
int particionisanje(int * A, int l, int d, int (*poredi)(int,int))
{
    int pivot = A[l];
    
    while(l<d) {
        while((*poredi)(A[d],pivot) == 0 && l<d) {
            d--; 
        }
        if(l != d) {
            A[l++] = A[d]; 
            
        }
        
        while((*poredi)(pivot,A[l]) == 0 && l<d) {
            l++;
            
        }
        
        if(l != d) {
            A[d--] = A[l];
            
        }
    }
    
    A[l] = pivot;
    
    return l;
        
        
}
void quick_sort(int * A, int l, int d, int (*poredi)(int,int))
{
    if(l>=d)
        return;
    
    int poz_pivota = particionisanje(A,l,d,poredi);
    quick_sort(A,l, poz_pivota - 1,poredi);
    quick_sort(A, poz_pivota+1, d,poredi);
}

int porednjenje_rastuce(const void *a, const void * b)
{
    int a1 = *(int *)a;
    int b1 = *(int *)b;
    
    if(a1<b1)
        return -1;
    if(a1>b1)
        return 1;
    
    return 0;    
}

int porednjenje_opadajuce(const void *a, const void * b)
{
    int a1 = *(int *)a;
    int b1 = *(int *)b;
    
    if(a1>b1)
        return -1;
    if(a1<b1)
        return 1;
    
    return 0;    
}


int main ()
{
    int n;
    int *A,*p;
    int i;
    
    scanf("%d", &n);
    if(n<1)
        greska();
    
    A = malloc(n * sizeof(int));
    if(A == NULL)
        greska();
    
    p= malloc(n * sizeof(int));
    if(p == NULL)
        greska(); 
    
    for(i=0; i<n; i++)
        scanf("%d", &A[i]);
    
    //insertion_sort(A,n,&poredi_opadajuce);
    //selection_sort(A,n,&poredi_rastuce);
    //merge_sort(A,0,n-1,p,&poredi_rastuce);
    //quick_sort(A,0,n-1,&poredi_opadajuce);
    qsort(A,n, sizeof(int), &porednjenje_opadajuce);

    for(i=0; i<n; i++)
        printf("%d ", A[i]);
    
    printf("\n");
    
    free(A);
    free(p);
 return 0;   
}
