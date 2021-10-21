#include <stdio.h>
#include <stdlib.h>
typedef int ItemNum; 
#define key(A) (A)
#define less(A,B) (key(A) < key(B))
#define exch(A,B) {ItemNum t = A ; A = B ; B = t;}
#define compExch(A,B) {if(less(A,B)) exch(A,B)}
#define lesseq(A,B) (key(A) <= key(B))

typedef struct Item{
    int val; 
    int pos; 
} Item; 

void merge(Item *V, int l, int middle, int r)
{

    Item *VAux = (Item *)malloc((r-l+1) * sizeof(Item)); 
    int k = 0, i = l, j = middle+1;
    
    while ((i <= middle) && (j <= r))
    {
        if (lesseq(V[i].val, V[j].val)){
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

void mergeSort(Item *V, int l, int r)
{
    if (l >= r)
        return;
    int middle = (r + l) / 2;
    mergeSort(V, l, middle);
    mergeSort(V, middle + 1, r);
    merge(V, l, middle, r);
}


void getNumbers(Item *V , int size){
    for(int i = 0 ; i < size ; i++){
        scanf("%d" , &V[i].val);
        V[i].pos = i; 
    }
    return; 
}


int showVector(Item *vector, int lenght){
    for(int i = 0 ; i <= lenght ; i++){
        printf("%d" , vector[i].val);
        (i != lenght) ? printf(" ") : printf("\n"); 
    }
    return 1;
}

int binarySearch(Item *V, int number,  int l , int r){
    int middle = l+(r-l)/2;
    if(V[middle].val == number) return middle;
    else if(l >= r) return -1;
    
    if(V[middle].val < number)
        binarySearch(V, number, middle+1, r); 
    else if(V[middle].val > number)
        binarySearch(V, number, l, middle-1); 
}

int main(){
    int size = 0 ; 
    int researches = 0; 
    scanf("%d %d", &size, &researches);
    Item *V = (Item*) malloc(size * sizeof(Item));

    getNumbers(V, size);
    size--;
    mergeSort(V, 0 , size);
    int num = 0;
    while(researches--){
        scanf("%d", &num);
        int returnBn = binarySearch(V , num, 0, size);
        printf("%d\n", returnBn != -1 ? (V[returnBn].pos) : -1 );
    }
    return 0; 

}