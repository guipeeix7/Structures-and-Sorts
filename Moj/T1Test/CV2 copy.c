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


int showVectorIntervals(int *vector, int begin,int end){
    for(int i = begin ; i <= end ; i++){
        printf("%d" , vector[i]);
        if(i != end){
            printf(" ");
        } 
    } 
    printf("\n");
    return 0;
}

int partition(int *V, int l, int r){
    M3(V, l , r);

    int i = l-1;
    for(int j = l; j < r ; j++){
        if(V[j] <= V[r]){
            i++;
            exch(V[i], V[j]);
        }
    } 
    i++; 
    exch(V[i], V[r]);
    return i; 
}

void quickSortM3(int *V, int l, int r){
    if(l < r ){
        int pivot = partition(V, l, r );
        quickSortM3(V, l , pivot-1); 
        quickSortM3(V, pivot+1, r);
    } 
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
void inserctionSortV2(int *V , int l , int r){
    // for(int i = r; i > l ; i--){
    //     cmpexch(V[i] , V[i-1]);
    // }

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
            if(numberOfInserctions < 50){
                inserctionSortV2(V, 0 , pos-1); 
            }

            if(numberOfInserctions >= 1){
                quickSelect(V, 0 , pos-1, num-1);
                // quickSortM3(V, 0 , pos-1);
                if(pos > 99){
                    pos = 99;
                }
            }
            numberOfInserctions = 0; 
            showVectorIntervals(V, 0,num-1);
        }
    }
    free(V);
}

int main(){
    C();
    return 0;
}