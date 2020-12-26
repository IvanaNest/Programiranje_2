#include "liste.h"

//4 5 9 8
Cvor* izbaci1(Cvor * glava, int broj) 
{
    if(glava == NULL)
        return NULL;
    
    Cvor * pomocna = glava;
    
    if(glava->vrednost == broj) {
        glava = pomocna->sledeci;
        free(pomocna);
        return glava;
    }
    
    Cvor * prethodni = glava;
    pomocna = pomocna->sledeci;
    
    while(pomocna->sledeci != NULL) {
        if(pomocna->vrednost == broj) {
            prethodni->sledeci = pomocna->sledeci;
            free(pomocna);
            break;
        }
        
        prethodni = pomocna;
        pomocna = pomocna->sledeci;
            
            
    }
    
    if(pomocna->vrednost == broj) {
        prethodni->sledeci = NULL;
        free(pomocna);
    }
    
    return glava;
        
        
}

Cvor* izbaci3(Cvor * glava, int broj) 
{
    
    Cvor * pomocna = glava;
    
    while(1) {
        if(glava == NULL)
        return NULL;
        
        if(glava->vrednost == broj) {
            glava = pomocna->sledeci;
            free(pomocna);
            continue;
        }
        
        break;
    }
    
    
    // 5 9 (2) 4 5
    Cvor * prethodni = glava;
    pomocna = pomocna->sledeci;
    Cvor * pomocna2 = NULL;
    
    while(pomocna->sledeci != NULL) {
        if(pomocna->vrednost == broj) {
            pomocna2 = pomocna;
            prethodni->sledeci = pomocna->sledeci;
            pomocna = pomocna->sledeci;
            free(pomocna2);
            continue;
            
        }
        
        prethodni = pomocna;
        pomocna = pomocna->sledeci;
            
            
    }
    
    if(pomocna->vrednost == broj) {
        prethodni->sledeci = NULL;
        free(pomocna);
    }
    
    return glava;
        
        
}

Cvor* izbaci2(Cvor * glava, int broj) 
{
    if(glava == NULL)
        return NULL;
    
    int brojac = 0;
    
    Cvor * pomocna = glava;
    Cvor * izmeniti = NULL;
    
    if(glava->vrednost == broj) {
            izmeniti = glava;
            brojac = 1;
    }
    
    Cvor * prethodni = glava;
    Cvor * pre_izmene = NULL;
    pomocna = pomocna->sledeci;
    
    while(pomocna->sledeci != NULL) {
        if(pomocna->vrednost == broj) {
            brojac = 0;
            izmeniti = pomocna;
            pre_izmene = prethodni;
        }
        
        prethodni = pomocna;
        pomocna = pomocna->sledeci;
            
            
    }
    
    if(pomocna->vrednost == broj) {
        brojac = 2;
        izmeniti = pomocna;
        pre_izmene = prethodni;
    }
    
    if(izmeniti == NULL)
        return glava;
    
    if(brojac == 1) {
        glava = glava->sledeci;
        free(izmeniti);
        return glava;
    }
    
    if(brojac == 2) {
        pre_izmene->sledeci = NULL;
        free(izmeniti);
    }
    
    pre_izmene->sledeci = izmeniti->sledeci;
    free(izmeniti);
    
    
    return glava;
        
}
    
int main(int argc, char ** argv)
{
    if(argc != 2)
        greska();
    
    int x;
    scanf("%d", &x);
    
    FILE * ulaz;
    
    ulaz = fopen(argv[1],"r");
    if(ulaz == NULL)
        greska();
    
    Cvor * glava = NULL;
    ucitaj_listu(&glava, ulaz);
    
    glava = izbaci3(glava,x);
    
    ispisi_listu(glava,stdout);
    oslobodi_listu(glava);
    fclose(ulaz);
    return 0;
}
