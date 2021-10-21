#include <stdio.h>
#include <stdlib.h>
typedef int Item; 
#define key(A) (A)
#define less(A,B) (key(A) < key(B))
#define exch(A,B) {Item t = A ; A = B ; B = t;}
#define compExch(A,B) {if(less(A,B)) exch(A,B)}

//Remebering bubble sort will get each element and try to bring lowest to the front and heviest to the end
void bubbleSort(int *V , int l , int r){
    for(int i = 0 ; i < r ; i++){
        for(int j = 0 ; j < r-i ; j++){
            compExch(V[j+1], V[j]);
        }
    }
    return;
}

void bubbleSortR(int *V , int l , int r){
    if(l == r) return; 
    for(int j = 0 ; j < r-l ; j++){
            compExch(V[j+1], V[j]);
    }
    bubbleSort(V, l+1, r);
}

int* getNumbers(){
    int *V; 
    V = (int*) malloc(1001 * sizeof(int));
    int i = 0; 
    while(scanf("%d" , &V[i]) != EOF){
        i++;
    }
    V[1001] = i-1; //Saving the size in the last position of array (;
    return V; 
}


int showVector(int *vector, int lenght){
    for(int i = 0 ; i <= lenght ; i++){
        printf("%d" , vector[i]);
        (i != lenght) ? printf(" ") : printf("\n"); 
    }
}


int main(){
    int *V = getNumbers();
    // showVector(V, V[1001]);
    bubbleSortR(V , 0 , V[1001]);
    showVector(V, V[1001]);
    return 0; 
}
