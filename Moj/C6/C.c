/*
    1 - Read the data
    2 - order by the data value in all interval of class  
    3 - order by strict interval read by user
*/

#include <stdio.h>
#include <stdlib.h>
#define key(A) (A) //key(A) (A.chave)
#define less(A,B) (key(A) < key(B))
#define lesseq(A,B) (key(A) <= key(B))
#define exch(A,B) {Item t = A; A = B; B = t;}
#define cmpexch(A,B) {if(less(A,B)) exch(A,B);}  

#define MAX_SIZE 100000

typedef struct Person{
    int code; 
    int reps; 
} Person; 


void merge(Person *V, int l, int middle, int r)
{
    Person *VAux = (Person *)malloc((r-l+1) * sizeof(Person)); 
    int k = 0, i = l, j = middle+1;
    while ((i <= middle) && (j <= r)){
        if (lesseq( V[j].reps, V[i].reps)){
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
        if (lesseq( V[j].code, V[i].code)){
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

    // printf("[");
    for(int i = begin ; i <= end ; i++){
        if(vector[i].reps == 0)continue;
        printf("%d" , vector[i].code);
        if(i != end) printf(" ");
    } 
    printf("\n");
    return 0;
}


int C(){
    int senators = 0, depFederal = 0, depState = 0; 
    scanf("%d %d %d", &senators, &depFederal, &depState);
    int vote = 0;
    int valid = 0, invalid = 0; 
    int presValid = 0;
    
    Person *V = (Person*) malloc(MAX_SIZE*sizeof(Person)); 
    
    for(int i = 0; i < MAX_SIZE ; i++){
        V[i].reps = 0;
        V[i].code = i;
    }

    while(scanf("%d", &vote) != EOF){
        if(vote < 0 || vote > 99999){
            invalid++; 
            continue;   
        }
        valid++;
        V[vote].reps+=1;
    }

    for(int i = 0 ; i <= 99 ; i++){
        presValid+= V[i].reps;
    }

    mergeSortByCode(V, 100, 999);
    mergeSortByCode(V, 1000, 9999);
    mergeSortByCode(V, 10000, 99999);

    mergeSort(V, 0, 99);
    mergeSort(V, 100, 999);
    mergeSort(V, 1000, 9999);
    mergeSort(V, 10000, 99999);


    double percentage = presValid*0.51; 


    // printf("%d\n", V[1].reps);
    // return;
    printf("%d %d\n",valid , invalid);

    if(V[0].reps <= percentage){
        printf("Segundo turno\n");
    }
    else{
        printf("%d\n", V[0].code);
    }
    showVectorIntervals(V, 100 , 100+senators-1); 
    showVectorIntervals(V, 1000 , 1000+depFederal-1); 
    showVectorIntervals(V, 10000 , 10000+depState-1); 
}

int main(){
    C();
}
