#include <stdio.h>
#include <stdlib.h>

#define INIT_SIZE_V 100000
typedef int Item;
#define key(A) (A) //key(A) (A.chave)
#define less(A,B) (key(A) < key(B))
#define lesseq(A,B) (key(A) <= key(B))
#define exch(A,B) {Item t = A; A = B; B = t;}
#define cmpexch(A,B) {if(less(A,B)) exch(A,B);} 

int intercala2(int* V, int sizeOfBigV,int *V_a, int sizeVa, int *V_b, int sizeVb,int lastInsertedPos){
    
    int Vab_size = sizeVa+sizeVb; 
    if(sizeOfBigV > INIT_SIZE_V ){
        V = (int*) realloc(V,Vab_size);
    }
    int i = 0, j = 0 , k = 0; 
    while(i <= sizeVa && j <= sizeVb){
        if(lesseq(V_a[k], V_b[k]))
            V[k+=lastInsertedPos+1] = V_a[i++];
            
        else V[k+=lastInsertedPos+1] = V_b[j++];
    }

    while(i <= sizeVa) V[k+=lastInsertedPos+1] = V[i++];
    while(j <= sizeVb) V[k+=lastInsertedPos+1] = V[j++]; 

    return Vab_size+1; 
}

int receiveValues(int *V, int sizeV){
    scanf("%d", &sizeV); 
    int i = 0; 
    while(sizeV--){
        scanf("%d", &V[i++]); 
    }
    return sizeV; 
}

void A(){
    int sizeOfBigV = 0, lastInsertedPos = 0; 
    int loop = 16;
    int *V = (int*) malloc(INIT_SIZE_V * sizeof(int));  
    while(loop--){
        int sizeA = 0, sizeB = 0; 
        int *V_a = (int*) malloc((sizeA+1) * sizeof(int));  
        int *V_b = (int*) malloc((sizeB+1) * sizeof(int));  
        sizeOfBigV += receiveValues(V_a, sizeA); 
        sizeOfBigV += receiveValues(V_a, sizeB); 
        lastInsertedPos += intercala2(V, sizeOfBigV, V_a, sizeA, V_b , sizeB, lastInsertedPos);
        free(V_a);
        free(V_b); 
    }
    free(V);
    return 0;
}

int main(){
    A();
    return 0;
}