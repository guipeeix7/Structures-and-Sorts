#include <stdio.h>
#include <stdlib.h>

typedef int Item;

#define key(A) (A) //key(A) (A.chave)
#define less(A,B) (key(A) < key(B))
#define lesseq(A,B) (key(A) <= key(B))
#define exch(A,B) {Item t = A; A = B; B = t;}
#define cmpexch(A,B) {if(less(A,B)) exch(A,B);} 
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


void mergeSort(int *V, int l, int r){
    if (l >= r)
        return;
    int middle = (r + l) / 2;
    mergeSort(V, l, middle);
    mergeSort(V, middle + 1, r);
    merge(V, l, middle, r);
}

int binarySearch(int *V, int number,  int l , int r){
    int middle = l+(r-l)/2;
    if(V[middle] == number) return middle;
    else if(l >= r) return -1;
    
    if(V[middle] < number)
        binarySearch(V, number, middle+1, r); 
    else if(V[middle] > number)
        binarySearch(V, number, l, middle-1); 
}

int receiveValues(int *V, int sizeV){
    for(int i = 0 ; i < sizeV ; i++){
        scanf("%d", &V[i]); 
    }
    return sizeV; 
}


int showVector(int *vector, int lenght){
    for(int i = 0 ; i <= lenght ; i++){
        printf("%d" , vector[i]);
        (i != lenght) ? printf(" ") : printf("\n"); 
    }
    return 1;
}

void F(){
    int sizeV = 0; 
    scanf("%d", &sizeV); 

    int *V = (int*) malloc(sizeV*sizeof(int));
    receiveValues(V, sizeV);
    mergeSort(V, 0, sizeV-1);
    int num = 0; 
    while(scanf("%d", &num) != EOF){
        int bSReturn = binarySearch(V, num, 0 , sizeV-1);  
        printf("%s\n", bSReturn != -1 ? "sim" : "nao") ;
    }
    return;
}

int main(){
    F();
}