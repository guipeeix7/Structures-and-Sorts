#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef int Item;
#define SIZE_V 10000000
#define key(A) (A) //key(A) (A.chave)
#define less(A,B) (key(A) < key(B))
#define lesseq(A,B) (key(A) <= key(B))
#define exch(A,B) {Item t = A; A = B; B = t;}
#define cmpexch(A,B) {if(less(A,B)) exch(A,B);} 

void M3(int *V, int l, int r){
    int md = (int) (l+r)/2; 
    int a = V[l];
    int b = V[md];
    int c = V[r];
    int mI;

    if (a < b) {
        if (b < c) {
            mI = md;
        } else {
            if (a < c) {
                mI = r;
            } else {
                mI = l;
            }
        }
    } else {
        if (c < b) {
            mI = md;
        } else {
            if (c < a) {
                mI = r;
            } else {
                mI = l;
            }
        }
    }
    exch(V[md], V[r]);
    return;
}


void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}
int showVectorIntervals(int *vector, int begin,int end){
    for(int i = begin ; i <= end ; i++){
        printf("%d " , vector[i]);
    } 
    printf("\n");
    return 0;
}
 int partition(int V[], int l, int r) {

  int pivot = V[r];
  int i = (l - 1);
  for (int j = l; j < r; j++) {
    if (V[j] <= pivot) {
      i++;
      swap(&V[i], &V[j]);
    }
  }
  swap(&V[i + 1], &V[r]);
  return (i + 1);
}
void quickSelect(int *V, int l, int r, int k)
{   
    if (l < r)
    {   
        int pi = partition(V, l, r);

        if(k == pi)
            return;
        if(k <= pi)
            quickSelect(V, l,pi - 1, k);
        if(k > pi)
       	    quickSelect(V,pi + 1, r, k);
    }
}


void quickSort(int V[], int l, int r) {
  if (l < r) {
    M3(V,l,r);

    int pi = partition(V, l, r);
    quickSort(V, l, pi - 1);
    quickSort(V, pi + 1, r);
  }
}
void inserctionSortV2(int *V , int l , int r){
    for(int i = l+1 ; i <= r ; i++){
        int tempItem = V[i];
        int j = i;   
        while(less(tempItem , V[j-1])){
            V[j] = V[j-1];   
            j--;
        }
        V[j] = tempItem;
    }
    return; 
}

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



void C(){
    int *V = (int*)  malloc((SIZE_V+1)*sizeof(int));
    int pos = 0;
    int cmd = 0;
    int num = 0;
    int numberOfInserctions = 0; 
    while(scanf("%d %d", &cmd, &num) != EOF){
        if(cmd == 0 && num ==0) break;
        if(cmd == 1){             
            V[pos] = num;
            pos++;
            numberOfInserctions++;
        }
        else{ 
            if(numberOfInserctions > 0){
                quickSelect(V, 0 , pos-1, num-1);
                mergeSort(V, 0 , pos-1); 
                if(pos > 99){
                    pos = 100;
                }
            }
            showVectorIntervals(V, 0,num-1);
        }
    }
    free(V);
}

int main(){
    C();
    return 0;
}