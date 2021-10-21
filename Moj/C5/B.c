#include <stdio.h>
#include <stdlib.h>

typedef int Item;

#define key(A) (A) //key(A) (A.chave)
#define less(A,B) (key(A) < key(B))
#define lesseq(A,B) (key(A) <= key(B))
#define exch(A,B) {Item t = A; A = B; B = t;}
#define cmpexch(A,B) {if(less(A,B)) exch(A,B);}  

int M3(int *V, int l , int r){
    int md = (l+r)/2;
    if(V[l] > V[md]) exch(V[l] , V[md]); 
    if(V[md] > V[r]) exch(V[md] , V[r]); 
    if(V[l] > V[md]) exch(V[l] , V[md]); 
    exch(V[md] , V[r]);
}

int partition(int *V, int l, int r){
    M3(V, l,r);
    int i = l - 1; 
    for(int k = l ; k < r ; k++){
        if(V[k] <= V[r]){
            i++;
            exch(V[k] , V[i]); 
        }
    }
    i++; 
    exch(V[r], V[i]); 
    return i;
}

void quickSort(int *V, int l , int r){
    if(l > r) return; 
    int pv = partition(V, l , r);  
    quickSort(V , l , pv-1); 
    quickSort(V , pv+1 , r); 
}


void getNumbers(int *V , int size){
    for(int i = 0 ; i < size ; i++){
        scanf("%d" , &V[i]);
    }
    return; 
}


int showVector(int *vector, int lenght){
    for(int i = 0 ; i < lenght ; i++){
        printf("%d" , vector[i]);
        (i != lenght) ? printf(" ") : printf("\n"); 
    }
    return 1;
}


int main(){
    int size = 0 ;  
    scanf("%d", &size);
    
    
    int *V = (int*) malloc((size+1) * sizeof(int));
    getNumbers(V, size);
    // size--;
    quickSort(V , 0 , size-1);

    showVector(V,size);

    // mergeSort(V, 0 , size);
    return 0; 

}