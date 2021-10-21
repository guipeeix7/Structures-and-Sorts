#include <stdio.h>
#include <stdlib.h>
typedef int Item;
#define key(A) (A) //key(A) (A.chave)
#define less(A,B) (key(A) < key(B))
#define exch(A,B) {Item t = A; A = B; B = t;}
#define cmpexch(A,B) {if(less(A,B)) exch(A,B);}  



int showVector(int *vector, int lenght){
    for(int i = 0 ; i <= lenght ; i++){
        printf("%d" , vector[i]);
        (i != lenght) ? printf(" ") : printf("\n"); 
    }
}

void inserctionSort(int *V , int l , int r){
    for(int i = l+1 ; i <= r ; i++){
        int temp = V[i];
        int j = i;  
        // cmpexch(V[j-1], V[j]); With this line the algorithim become slow
        while(less(temp , V[j-1]) && j){
            // exch(V[j] , V[j-1]); wasted ram
            V[j] = V[j-1];
            j--;
        }
        V[j] = temp;
    }
    return; 
}

int *getInput(){
    int *V; 
    V = (int*) malloc(50001*sizeof(int));
    int i = 0; 
    while(scanf("%d", &V[i]) != EOF){
        i++; 
    }
    V[50001] = i-1;  
    return V;  
}


int main(){
    int *V = getInput(); 
    inserctionSort(V, 0 , V[50001]);
    showVector(V, V[50001]); 
    return 0; 
}
