#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef int Item;
#define SIZE_V 2000000
#define key(A) (A) //key(A) (A.chave)
#define less(A,B) (key(A) < key(B))
#define lesseq(A,B) (key(A) <= key(B))
#define exch(A,B) {Item t = A; A = B; B = t;}
#define cmpexch(A,B) {if(less(A,B)) exch(A,B);} 

/**
 * Procurar um algorítimo que ordene um lindo intervalo (; 
 * 1 - If 1 receive the data and save into array 
 * 2 - If 2 organize a section of array and print the lowest numbers saved in the interval choosed by the user
 */

/**
 * this -> Preciso de encontrar a posição certa do elemento que será meu pivot
 * após isso posso fazer um lindo quickSort a partir de um pivot (; 
 */

/**
 * Até então sei que o selection sort pode fazer a ordenação de um espaço do vetor
 * Também sei que o quickSort pode ser útil para ignorar a parte mais a direita do meu vetor,
 * a partir do momento que meu meu pivot for igual à posição que eu desejo eu ordeno o intervalo de 0 até o pivot
 */

/**
 *  Casos lascados...
 * 1 - Vetor ordenado 
 * 2 - Vetor ordenado reverso 
 */

/**
 * 1 bubble No 
 * 2 Inserction NO
 * 3 mergeSort ? (Maybe)
 * 4 quickSort Mais rápido ;-; 
 * 5 Selection Sort (Maybe)
 * 6 Shell sort NO
 * 
 */ 

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

int partition(int *V, int l, int r){
    int pv = r, i = l-1;
    for(int j = l; j < r ; j++){
        if(V[j] < V[pv]){
            i++;
            exch(V[i], V[j]);
        }
    } 
    i++; 
    exch(V[i], V[pv]);
    return i; 
}
int quickTrapStop = 0; 
void quickSortM3V2(int *V, int l, int r, int maxRecurssion){
    if(maxRecurssion == 0) {quickTrapStop = 1; return;} 
    if(quickTrapStop == 1) return; 
    if(r-l <= 32) return;
    int middle = (l+r)/2; 
    exch(V[middle] , V[r-1]);
    cmpexch(V[middle], V[r]);
    cmpexch(V[l], V[middle]);
    cmpexch(V[r], V[middle]);
    int pivot = partition(V, l, r );
    quickSortM3V2(V, l , pivot-1, maxRecurssion-1); 
    quickSortM3V2(V, pivot+1, r,maxRecurssion-1 );

    
}

// void SortQuickInserct(int *V, int l, int r){
//     quickSortM3(V, l ,r); 
//     inserctionSortV2(V, l, r);
// }

//Order by position
int partitionSel(int arr[], int low, int high)
{
    int pivot = arr[low];    // pivot
    int i = low,j;  // Index of smaller element
 
    for (j = low+1; j <= high; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            exch(arr[i], arr[j]);
        }
    }
    exch(arr[i], arr[low]);
    return i;
}
 
void quickSelect(int arr[], int low, int high, int k)
{
    if (low < high)
    {
        int pi = partitionSel(arr, low, high);

        if(k <= pi)
            quickSelect(arr, low,pi - 1, k);
        if(k == pi+1)
            return;
        else
       	    quickSelect(arr,pi + 1, high, k);

    }
}
void inserctionSortShell(int *V , int l , int r,int h){
    for(int i = l+h ; i <= r ; i++){
        int tempItem = V[i];
        int j = i;   
        while(j >= l+h && less(tempItem , V[j-h])){
            V[j] = V[j-h];   
            j-=h;
        }
        V[j] = tempItem;
    }
    return; 
}

void shellSort(int *V, int l , int r){
    int h; 
    for(h = 1 ; h <= (r-l)/9 ; h=(3*h+1));
    for(;h>0; h=h/3){
        inserctionSortShell(V,l,r,h); 
    }
    return; 
}


int showVectorIntervals(int *vector, int begin,int end){
    for(int i = begin ; i <= end ; i++){
        printf("%d" , vector[i]);
        (i != end) ? printf(" ") : printf("\n"); 
    } 
    return 0;
}

void iReallySholdKnowThisIntroSort(int *V, int l,int r){
    int maxRec = 2*log2((r-l+1));
    quickSortM3V2(V, l , r, maxRec);
    if(quickTrapStop == 1){
        mergeSort(V, l , r); 
    }
    else{
        inserctionSortV2(V, l ,r);
    }
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
            // printf("%d\n", numberOfInserctions); 
            if(numberOfInserctions < 40){
                inserctionSortV2(V, 0 , pos-1); 
            }
            else{
                quickSelect(V, 0, pos-1,num-1); 
                iReallySholdKnowThisIntroSort(V, 0 , pos-1); //27s
            }
            numberOfInserctions = 0;
            // showVectorIntervals(V, 0 , num-1);
        }
    }
    free(V);
}

int main(){
    C();
    return 0;
}