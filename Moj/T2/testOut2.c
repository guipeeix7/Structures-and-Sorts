
typedef int Item;

#define key(A) (A) //key(A) (A.chave)
#define less(A,B) (key(A) < key(B))
#define lesseq(A,B) (key(A) <= key(B))
#define exch(A,B) {Item t = A; A = B; B = t;}
#define cmpexch(A,B) {if(less(A,B)) exch(A,B);}  
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXSIZE 10000 


typedef struct MojinStack{
    char areaAvaliable[8];  // (-1,-1) , (0,-1) , (1, 0); 
                            // (-1, 0) , (0, 0) , (1, 1); 
                            // (-1, 1) , (0,+1) , (1, 1);
    int x; 
    int y; 
    struct MojinStack *prox; 
} MojinStack;
MojinStack *initMojinStack(){
    MojinStack *headNode = (MojinStack*) malloc(sizeof(MojinStack));
    for(int i = 0 ; i < 8 ; i++){
        headNode->areaAvaliable[i] = '1';
    }  
    headNode->x = 0; 
    headNode->y = 0; 
    headNode->prox = NULL; 
    return headNode; 
}
void insertMojinStack(MojinStack *headNode, int *value, int x , int y){
    MojinStack *newNode = (MojinStack*) malloc(sizeof(MojinStack));
    newNode->x = x; 
    newNode->y = y; 
    newNode->prox = NULL; 

    for(int i = 0 ; i < 8 ; i++){
        headNode->areaAvaliable[i] = '0';
    }  

    if(headNode->prox == NULL){
        headNode->prox = newNode;
        return;  
    }

    newNode->prox = headNode->prox; 
    headNode->prox = newNode; 
    return; 
}
int isEmptyMojinStack(MojinStack *headNode){
    if(headNode->prox == NULL){
        printf("MojinStack is empty!\n");
        return 1; 
    } 
    return 0;
}
void popTopMojinStack(MojinStack *headNode){
    if(isEmptyMojinStack(headNode)) return; 
    MojinStack *topNode = headNode->prox; 
    headNode->prox = topNode->prox; 
    free(topNode);
    return;  
}

int main(){
    MojinStack *headNode = initMojinStack();
    insertMojinStack(9 ,21 , 15, headNode);   
    insertMojinStack(3 ,43 , 12, headNode);   
    insertMojinStack(2,98 , 32, headNode);   
    insertMojinStack(4 ,65 , 54, headNode);   
    insertMojinStack(5 ,98 , 34, headNode);   
    insertMojinStack(7 ,76 , 76,headNode);   
    popTopStack(headNode);
    popTopStack(headNode);
    // popTopStack(headNode);
    // popTopStack(headNode);
    // popTopStack(headNode);
    showStack(headNode);
    
}