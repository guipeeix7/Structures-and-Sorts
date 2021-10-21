#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 10 


int Hash(int hKey){
    return hKey%101; 
}

typedef struct LinkedHash{
    /* data */
    int key; 
    char value[102]; 
    short flag; 
    struct LinkedHash *prox; 
}LinkedHash;

int hKey(char *key){
    int hKey = 0; 
    for(int i = 0 ; key[i] != '\0' ; i++){
        hKey+=((int) key[i]*(i+1));
    }   
    return Hash(19*hKey); 
}


LinkedHash *insertLinked(char *value, LinkedHash *headNode, int hkey){

    LinkedHash *newNode = (LinkedHash*) malloc(sizeof(LinkedHash));
    strcpy(headNode[hkey].value, value);
    headNode[hkey].key = hkey;
    newNode->prox = headNode; 

    return newNode; 
}

int insert(char *value, LinkedHash *V){ 
    int hkey = hKey(value); 
    int inserctions = 0;
    
    if(V[hkey].flag == 1){
        return 0; 
        // V[hkey].prox = insertLinked(value, V[hKey(value)].prox, hkey);
    }
    else{
        strcpy(V[hkey].value, value); 
        V[hkey].key = hkey;
        V[hkey].flag = 1; 
        return 1; 
    }
    // It means already used space

}


int isEmptyLinkedHash(LinkedHash *headNode){
    if(headNode->prox == NULL){
        return 1; 
    } 
    return 0;
}
int popTopLinkedHash(LinkedHash *headNode){
    // printf("I POOPED"); 
    int returnNum = 0; 
    if(headNode->flag == 1 && headNode->prox == NULL){
        headNode->flag = -1; 
        headNode->key = -1; 
        strcpy(headNode->value,"\0");
        headNode->prox = NULL;
        // return 1;
        returnNum = 1;
        return 1;  
    }
    if(isEmptyLinkedHash(headNode)) return 0; 
    LinkedHash *headPointer = headNode->prox; 

    LinkedHash *topNode = headNode->prox; 
    headNode->prox = topNode->prox; 
    strcpy(headNode->value,topNode->value);

    free(topNode);
    return returnNum;
}

void showStack(LinkedHash *headNode){
    LinkedHash *temp = headNode; 
    
    while(temp != NULL){
        printf(" -> %d", temp->value);
        temp = temp->prox; 
    }
    return; 
}

void showLinkedList(LinkedHash *V, int size){
    for(int i = 0 ; i < size ; i++){
        if(V[i].key != -1 ){

            printf("%d:%s\n", V[i].key, V[i].value);
            // if(V[i].prox != NULL){
            //     showStack(V[i].prox);   
            // } 
        }
    }
    // printf("\n");
    return; 
}


void F(){
    int loop = 0; 
    scanf("%d", &loop);
    
    while(loop--){
        int operations = 0, inserctions = 0;
        scanf("%d", &operations);

        LinkedHash *V = (LinkedHash*) malloc(1001*sizeof(LinkedHash)); 
        for(int i = 0 ; i < 1001 ; i++){
            V[i].key = -1; 
            V[i].flag = -1; 
            V[i].prox = NULL; 
        }   

        for(int i = 0 ; i < operations ; i++){
            char operation[5] = {'\0', '\0', '\0'}; // WTH????? Why 5 ????
            char name[102] = {'\0'}; 

            scanf("%[^:]s", operation);
            getchar(); 
            scanf("%[^\n]s", name);
            
            
            if(operation[1] == 'A'){
                inserctions += insert(name,V);
            }
            else{
                inserctions -= popTopLinkedHash(&V[hKey(name)]);
            }
                    // showLinkedList(V, 1000);

        } 
        printf("%d\n" , inserctions);
        showLinkedList(V, 1000);
        // if(loop != 0){
        //     printf("\n");
        // }
    }
    // int rVal = hKey("do");

    
    // printf("%d\n", rVal);
    return; 
}

int main(){
    F(); 
}