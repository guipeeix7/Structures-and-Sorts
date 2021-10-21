#include <stdio.h>
#include <stdlib.h>
typedef int Item; 
#define key(A) (A)
#define less(A,B) (key(A) < key(B))
#define exch(A,B) {Item t = A ; A = B ; B = t;}
#define compExch(A,B) {if(less(A,B)) exch(A,B)}
#define lesseq(A,B) (key(A) <= key(B))




void merge(int *V, int l, int middle, int r)
{

    int *VAux = (int *)malloc((r-l+1) * sizeof(int)); 
    int k = 0, i = l, j = middle+1;
    
    while ((i <= middle) && (j <= r))
    {
        if (lesseq(V[i], V[j])){
            VAux[k++] = V[i++];
        }
        else{
            VAux[k++] = V[j++];
        }
    }
    while (i <= middle){
        VAux[k++] = V[i++];
    }
    while (j<=r){
        VAux[k++] = V[j++];        
    }


    k = 0;
    while((l + k) <= r)
    {
        V[l + k] = VAux[k];
        k++;
    }
    free(VAux); //Free nao funciona em arrays de uma posição
}

void mergeSort(int *V, int l, int r)
{
    if (l >= r)
        return;
    int middle = (r + l) / 2;
    mergeSort(V, l, middle);
    mergeSort(V, middle + 1, r);
    merge(V, l, middle, r);
}


void getNumbers(int *V , int size){
    for(int i = 0 ; i < size ; i++){
        scanf("%d" , &V[i]);
    }
    return; 
}


int showVector(int *vector, int lenght){
    for(int i = 0 ; i <= lenght ; i++){
        printf("%d" , vector[i]);
        (i != lenght) ? printf(" ") : printf("\n"); 
    }
    return 1;
}


int main(){
    int size = 0 ; 
    scanf("%d", &size);
    int *V = (int*) malloc(size * sizeof(int));

    getNumbers(V, size);
    mergeSort(V, 0 , size-1);

    showVector(V, size-1);
}