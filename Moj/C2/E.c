#include <stdio.h>
#include <stdlib.h>
typedef int Item;
#define key(A) (A) //key(A) (A.chave)
#define less(A,B) (key(A) < key(B))
#define exch(A,B) {Item t = A; A = B; B = t;}
#define cmpexch(A,B) {if(less(A,B)) exch(A,B);}  


typedef struct Element{
    unsigned int key; 
    char name[16]; 
}Element; 

int binarySearch(Element *V, int number,  int l , int r){
    int middle = l+(r-l)/2;
    if(V[middle].key == number) return middle;
    else if(l >= r) return -1;
    
    if(V[middle].key < number)
        binarySearch(V, number, middle+1, r); 
    else if(V[middle].key > number)
        binarySearch(V, number, l, middle-1); 
}

Element *getInput(int loop){
    Element *V = (Element*) malloc((loop+1)*sizeof(Element));  
    for(int i = 0 ; i < loop ; i++){
        scanf("%d %[^\n]s" , &V[i].key , V[i].name);
        getchar();
    }

    return V;  
}

void findInstructions(Element *V, int loop){
    int i = 0, findKey = 0; 
    while(scanf("%d" , &findKey) != EOF){
        int binarySearchReturn = binarySearch(V, findKey, 0 , loop);
        printf("%s\n" , (binarySearchReturn != -1) ? V[binarySearchReturn].name : "undefined"); 
        i++;
    }
    return; 
    
}


// void inserctionSort(Element *V , int l , int r){
//     for(int i = l+1 ; i <= r ; i++){
//         Element temp = V[i];
//         int j = i;  
//         while(less(temp.key , V[j-1].key) && j){
//             V[j] = V[j-1];
//             j--;
//         }
//         V[j] = temp;
//     }
//     return; 
// }

void inserctionSortShell(Element *V , int l , int r,int h){
    for(int i = l+h ; i <= r ; i++){
        Element tempItem = V[i];
        int j = i;   
        while(j >= l+h && less(tempItem.key , V[j-h].key)){
            V[j] = V[j-h];   
            j-=h;
        }
        V[j] = tempItem;
    }
    return; 
}

void shellSort(Element *V, int l , int r){
    int h; 
    for(h = 1 ; h <= (r-l)/9 ; h=(3*h+1));
    for(;h>0; h=h/3){
        inserctionSortShell(V,l,r,h); 
    }
    return; 
}

int showVector(Element *vector, int lenght){

    printf("[");
    for(int i = 0 ; i <= lenght ; i++){
        printf(" %d " , vector[i].key);
    } 
    printf("]\n");
}


int main(){
    unsigned int loop = 0; 
    scanf("%d", &loop); 
    Element *V; 
    V = getInput(loop);

    // inserctionSort(V, 0 , loop-1);
    shellSort(V, 0, loop-1);
    findInstructions(V, loop-1);  
    return 0; 
}