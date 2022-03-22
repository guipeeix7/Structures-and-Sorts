//C Libraries
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//Util files



// typedef struct MojinStack{
//     int key; 
//     int value;    
//     struct MojinStack *prevNodeAddress; 
//     struct MojinStack *proxNodeAddress; 

// } MojinStack; 

typedef struct MojinStack{
    char areaAvaliable[8];  
    long x; 
    long y; 
    struct MojinStack *prevNodeAddress; 
    struct MojinStack *proxNodeAddress; 
} MojinStack;

//receive the data to the node ?
// https://docs.google.com/drawings/d/1YZYjI_7NeXlYUMQQAL-116gLrXH4_1RWBKCfwjsFIIc/edit?usp=sharing
// MojinStack *headNode; 
MojinStack *initMojinStack(){
    MojinStack *headNode = (MojinStack*) malloc(sizeof(MojinStack));  
    for(int i = 0 ; i < 8 ; i++){
            headNode->areaAvaliable[i] = '0';
        }  
    headNode->x = 0; 
    headNode->y = 0; 
    headNode->proxNodeAddress = NULL; 
    headNode->prevNodeAddress = NULL; 
    return headNode; 
}

MojinStack *insertMojinStack(int x, int y, MojinStack *headNode){ //The same as add begin list
    MojinStack *newNode = (MojinStack*) malloc(sizeof(MojinStack)); 
    
    if(headNode->prevNodeAddress == NULL &&  headNode->proxNodeAddress == NULL){
        headNode->proxNodeAddress = newNode; 
        newNode->proxNodeAddress = NULL; 
    }else{
        newNode->proxNodeAddress = headNode->prevNodeAddress; 
        headNode->prevNodeAddress->prevNodeAddress = newNode; 
    }
    newNode->x = x; 
    newNode->y = y;  
    for(int i = 0 ; i < 8 ; i++){
        newNode->areaAvaliable[i] = 0;
    }  

    newNode->prevNodeAddress = NULL; 
    headNode->prevNodeAddress = newNode; 

    return newNode; 
}


int isEmptyMojinStack(MojinStack *headNode){
    if(headNode->proxNodeAddress == NULL && headNode->prevNodeAddress == NULL){
        printf("Double Linked list is empty!\n");
        return 1; 
    } 
    return 0;
}


MojinStack *search(int x, int y , MojinStack *headNode, char opt[]){
    if(isEmptyMojinStack == 0) return NULL;  

    MojinStack *temp = headNode->prevNodeAddress;
    while(temp != NULL){
        if((temp->x == x) && (temp->y == y)) return temp;
        temp = temp->proxNodeAddress;
    }

    printf("Value not found!\n"); 
    return NULL; 
}


void searchAndDelete(int x, int y, MojinStack *headNode){
    if(isEmptyMojinStack(headNode) == 1) return; 
    
    MojinStack *item = search(x, y,headNode, "");
    if(item == NULL) return;

    MojinStack *prevNode = item->prevNodeAddress; 
    MojinStack *proxNode = item->proxNodeAddress; 
    MojinStack *aux = item;
    
    if(proxNode == NULL){
        headNode->proxNodeAddress = prevNode;
    }
    else{
        proxNode->prevNodeAddress = prevNode; 
    }
    if(prevNode == NULL){
        headNode->prevNodeAddress = proxNode;
    }
    else{
        prevNode->proxNodeAddress = proxNode; 
    }


    free(item);
}

MojinStack exchangePosition(){
    
}

void showList(MojinStack *headNode){
    MojinStack *temp = headNode->prevNodeAddress; 
    
    while(temp != NULL){
        printf("x: %d y: %d\n", temp->x, temp->y);
        temp = temp->proxNodeAddress; 
    }
    return; 
}

void showReveseList(MojinStack *headNode){
    MojinStack *temp = headNode->proxNodeAddress; 
    
    while(temp != NULL){
        printf("x: %d y: %d\n", temp->x, temp->y);
        temp = temp->prevNodeAddress; 
    }
    return; 
}

int *swapNode(){ //It will pick 2 numbers and swap their adress! (This will be insane) 
    return 0; 
}


int main(){
    MojinStack *headNode = initMojinStack();

    // Double linked list
    insertMojinStack(0,2,headNode);
    insertMojinStack(0,1,headNode);
    insertMojinStack(10,3, headNode);
    // printf("%d\n", );
    // searchAndDelete(2, headNode);
    // searchAndDelete(3, headNode);
    // searchAndDelete(10, headNode);
    // searchAndDelete(2,3, headNode);
    searchAndDelete(0,2, headNode);
    // searchAndDelete(0,2, headNode);
    // searchAndDelete(0,1, headNode);
    // searchAndDelete(10,3, headNode);

    // searchAndDelete(1, headNode);
    // orderedInserction(10,5, headNode);
    // orderedInserction(10,5, headNode);
    // searchAndDelete(2, headNode);
    // searchAndDelete(20, headNode);

    // // orderedInserction(2,40, headNode);

    showList(headNode);
    // printf("==================\n");
    // showReveseList(headNode);
}
// int addAfterNode(){
//     return 0;
// }

// int *addEndList(){
//     return 0; 
// }





