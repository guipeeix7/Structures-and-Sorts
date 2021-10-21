#include <stdio.h>
#include <stdlib.h>
#define key(A) (A) //key(A) (A.chave)
#define less(A,B) (key(A) < key(B))
#define lesseq(A,B) (key(A) <= key(B))
#define exch(A,B) {Item t = A; A = B; B = t;}
#define cmpexch(A,B) {if(less(A,B)) exch(A,B);}  

#define MAX_SIZE 128000

typedef struct Person{
    int code; 
    int reps; 
} Person; 


void merge(Person *V, int l, int middle, int r)
{
    Person *VAux = (Person *)malloc((r-l+1) * sizeof(Person)); 
    int k = 0, i = l, j = middle+1;
    while ((i <= middle) && (j <= r)){
        if (lesseq( V[i].reps, V[j].reps)){
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
    while((l + k) <= r){
        V[l + k] = VAux[k];
        k++;
    }
    free(VAux); //Free nao funciona em arrays de uma posição
}

void mergeByCode(Person *V, int l, int middle, int r)
{
    Person *VAux = (Person *)malloc((r-l+1) * sizeof(Person)); 
    int k = 0, i = l, j = middle+1;
    while ((i <= middle) && (j <= r)){
        if (lesseq(V[i].code, V[j].code)){
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
    while((l + k) <= r){
        V[l + k] = VAux[k];
        k++;
    }
    free(VAux); //Free nao funciona em arrays de uma posição
}


void mergeSortByCode(Person *V, int l, int r)
{
    if (l >= r)
        return;
    int middle = (r + l) / 2;
    mergeSortByCode(V, l, middle);
    mergeSortByCode(V, middle + 1, r);
    mergeByCode(V, l, middle, r);
}
void mergeSort(Person *V, int l, int r)
{
    if (l >= r)
        return;
    int middle = (r + l) / 2;
    mergeSort(V, l, middle);
    mergeSort(V, middle + 1, r);
    merge(V, l, middle, r);
}


int showVectorIntervals(Person *vector, int begin,int end){

    for(int i = begin ; i <= end ; i++){
        if(vector[i].reps == 0)continue;
        printf("%d" , vector[i].code);
        if(i != end) printf(" ");
    } 
    printf("\n");
    return 0;
}


int C(){
    int note = 0;
    int notes = 0; 
    Person *V = (Person*) malloc(MAX_SIZE*sizeof(Person)); 
    
    for(int i = 0; i <= MAX_SIZE ; i++){
        V[i].reps = 0;
        V[i].code = i;
    }

    while(scanf("%d", &note) != EOF){
        notes++;
        V[note].reps+=1;
    }
    mergeSort(V, 0, 128000);
    showVectorIntervals(V, 128000 , 128000); 
}

int main(){
    C();
}
