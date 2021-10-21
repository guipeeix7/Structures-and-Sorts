#include <stdio.h>
#include <stdlib.h>
typedef int Item;
#define key(A) (A) //key(A) (A.chave)
#define less(A,B) (key(A) < key(B))
#define exch(A,B) {Item t = A; A = B; B = t;}
#define cmpexch(A,B) {if(less(B,A)) exch(A,B);}  


int showVector(int *vector, int lenght){
    for(int i = 0 ; i <= lenght ; i++){
        printf("%d" , vector[i]);
        (i != lenght) ? printf(" ") : printf("\n"); 
    }
}

void selectionSort(int *V , int l , int r){
    for(int i = l; i <= r ; i++){
        int lowest = i; 
        for(int j = i ; j <= r ; j++){
            if(less(V[j] , V[lowest])){
                // exch(V[j] , V[lowest]); If i stop and only change on the lowest number it will increase speed by aomething around 2x.
                lowest = j; 
            }
        }
        exch(V[i] , V[lowest]); 
    }
    return; 
}

int *getInput(){
    int *V; 
    V = (int*) malloc(1001*sizeof(int));
    int i = 0; 
    while(scanf("%d", &V[i]) != EOF){
        i++; 
    }
    V[1001] = i-1;  
    return V;  
}


int main(){
    int *V = getInput(); 
    // showVector(V, V[1001]); 
    selectionSort(V, 0 , V[1001]);
    showVector(V, V[1001]); 
    return 0; 
}
