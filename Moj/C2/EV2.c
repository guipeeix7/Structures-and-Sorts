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
    int middle = (r+l)/2;
    if(V[middle].key == number) return middle;
    else if(l == r) return -1;
    
    if(V[middle].key < number)
        binarySearch(V, number, middle+1, r); 
    else if(V[middle].key > number)
        binarySearch(V, number, l, middle-1); 
}

void inserctionSort(Element *V , int l , int r){
    for(int i = l+1 ; i <= r ; i++){
        Element temp = V[i];
        int j = i;  
        // cmpexch(V[j-1], V[j]); With this line the algorithim become slow
        while(less(temp.key , V[j-1].key) && j){
            // exch(V[j] , V[j-1]); wasted ram
            V[j] = V[j-1];
            j--;
        }
        V[j] = temp;
    }
    return; 
}


Element *getInput(int loop){
    Element *V = (Element*) malloc((2147483647+1)*sizeof(Element));  
    for(int i = 0 ; i < loop ; i++){
        int key; 
        char name[16]; 
        scanf("%d %s" , &V[i].key , V[i].name);


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

int main(){
    unsigned int loop = 0; 
    scanf("%d", &loop); 
    Element *V; 
    V = getInput(loop);

    inserctionSort(V, 0 , loop);
    findInstructions(V, loop);  

    return 0; 
}