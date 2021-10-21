//C Libraries
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
//Util files

//function Files
typedef struct Item{
    char value[27]; 
    // int value;    
    struct Item *prevNodeAddress; 
    struct Item *proxNodeAddress; 

} Item; 

//receive the data to the node ?
// https://docs.google.com/drawings/d/1YZYjI_7NeXlYUMQQAL-116gLrXH4_1RWBKCfwjsFIIc/edit?usp=sharing


// Item *headNode; 
Item *init(){
    Item *headNode = (Item*) malloc(sizeof(Item));  
    headNode->proxNodeAddress = NULL; 
    headNode->prevNodeAddress = NULL; 
    return headNode; 
}

Item *addEndList(char *value, Item *headNode){
    Item *newNode = (Item*) malloc(sizeof(Item)); 
    
    if(headNode->prevNodeAddress == NULL &&  headNode->proxNodeAddress == NULL){
        newNode->prevNodeAddress = NULL; 
        headNode->prevNodeAddress = newNode; 
    }else{
        newNode->prevNodeAddress = headNode->proxNodeAddress; 
        headNode->proxNodeAddress->proxNodeAddress = newNode; 
    }
    strcpy(newNode->value , value);  
    newNode->proxNodeAddress = NULL;  
    headNode->proxNodeAddress = newNode; 

    return newNode; 
}

void showList(Item *headNode){
    Item *temp = headNode->prevNodeAddress; 
    char lastCityChar = {'9'};

    while(temp != NULL){
        char currentCitylChar = temp->value[0];        
        if((char)((int)currentCitylChar+32) == lastCityChar){
            addEndList(temp->value,headNode);
            temp = temp->proxNodeAddress; 
            lastCityChar = '9';

            continue; 
        }

        lastCityChar = temp->value[strlen(temp->value)-1];
        printf("%s\n",temp->value);
        temp = temp->proxNodeAddress; 
    }
    return; 
}
int *swapNode(){ //It will pick 2 numbers and swap their adress! (This will be insane) 
    return 0; 
}


int main(){
    Item *headNode = init();
    char name[27] = ""; 

    while(scanf("%s" , name) != EOF){ 
        addEndList(name,headNode);
    }
    showList(headNode);
}



