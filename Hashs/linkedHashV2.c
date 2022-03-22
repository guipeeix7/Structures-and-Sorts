//Faço um vetor linear 
//Faço o link de uma linked list com o endereço desse vetor
//Insiro no rabico do vetor adosdkoka
//Lets rush
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <unistd.h> // notice this! you need it!

#define MAXSIZE 10 

typedef struct LinkedHash{
    /* data */
    int value; 
    short flag; 
    struct LinkedHash *prox; 
}LinkedHash;


LinkedHash *initLH(int sizeVector){
    LinkedHash *V = (LinkedHash*) malloc((sizeVector+1)*sizeof(LinkedHash));
     
    for(int i = 0 ; i < sizeVector ; i++){
        V[i].value = 0; 
        V[i].flag = -1; 
        V[i].prox = NULL; 
    }   
    return V; 
}

int hash(int num){
    return num%MAXSIZE;
}
int isEmptyLinkedHash(LinkedHash *headNode){
    if(headNode->prox == NULL){
        printf("LinkedHash is empty!\n");
        return 1; 
    } 
    return 0;
}

//Aqui devo verificar se o meu node atual já é nulo, inclusive o do meu vetor 
//Se ele nao for devo fazer o pop dele e substituir com o próximo valor 
//Se ele for entao deixo queto ;-; 
void popTopLinkedHash(LinkedHash *headNode, int hashValue){
    if(isEmptyLinkedHash(&headNode[hashValue])) return;
    
    LinkedHash *topNode = headNode[hashValue].prox; 
    headNode[hashValue].prox = topNode->prox; 
    
    // printf("altera essa trem %d\n\n", headNode->prox->value);
    free(topNode);
    

    if(headNode[hashValue].flag == 1 && headNode[hashValue].prox == NULL){
        headNode[hashValue].flag = -1; 
        headNode[hashValue].value = 0;
        headNode[hashValue].prox = NULL;
    }
    return;
}

LinkedHash *search(int value, LinkedHash *headNode, char opt[]){
    LinkedHash *temp = headNode[hash(value)].prox;

    while(temp != NULL){
        if(temp->value == value) return temp;
        temp = temp->prox;
    }

    printf("Value not found!\n"); 
    return NULL; 
}

LinkedHash *searchNode(int value, LinkedHash *V){

    if(V[hash(value)].flag == -1){
        printf("not finded\n");
        return NULL; 
    } 
    if(search(value, V,  "") != NULL){
        printf("finded: %d\n", search(value, V,  "")->value);
        return search(value, V,  ""); 
    }
    return NULL; 
}


//trying to see the hash function
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
        printf("%d:", V[i].value);
        if(V[i].prox != NULL){
            showStack(V[i].prox);   
        } 
        printf("\n");
    }
    return; 
}

LinkedHash *insertLinked(int value, LinkedHash *headNode){
    LinkedHash *newNode = (LinkedHash*) malloc(sizeof(LinkedHash));
    newNode->value = value; 
    newNode->prox = headNode; 


    return newNode; 
}

LinkedHash *insert(int value, LinkedHash *V){ 
    V[hash(value)].prox = insertLinked(value, V[hash(value)].prox);
    if(V[hash(value)].flag == -1){
        V[hash(value)].value = hash(value);
    }

    V[hash(value)].flag = 1; 
}

int linkedHash(){
    int sizeVector = 10;
    LinkedHash *V = initLH(sizeVector);

    //  for(int i = 0 ; i < sizeVector ; i++){
    //     V[i].value = 0; 
    //     V[i].flag = -1; 
    //     V[i].prox = NULL; 
    //     printf("%d", V[i].flag);
    // }   
    // insert(4, V);
    // insert(14, V);
    // insert(24, V);
    // insert(34, V);
    // insert(8, V);
    // insert(8, V);
    insert(9, V);
    insert(18, V);
    insert(18, V);
    insert(28, V);
    insert(38, V);
    // insert(8, V);
    popTopLinkedHash(V, hash(8));
    popTopLinkedHash(V, hash(8));
    popTopLinkedHash(V, hash(8));
    popTopLinkedHash(V, hash(8));
    insert(28, V);
    insert(28, V);
    // popTopLinkedHash(&V[hash(8)]);
    // popTopLinkedHash(&V[hash(8)]);
    // popTopLinkedHash(&V[hash(8)]);
    // popTopLinkedHash(&V[hash(8)]);
    // popTopLinkedHash(&V[hash(8)]);
    // popTopLinkedHash(&V[hash(8)]);
    // popTopLinkedHash(&V[hash(8)]);
    searchNode(8, V);
    // insert(6, V);
    // popTopLinkedHash(&V[hash(4)]);
    // popTopLinkedHash(&V[hash(4)]);
    // popTopLinkedHash(&V[hash(4)]);
    // popTopLinkedHash(&V[hash(4)]);

    // insert(4, V);
    // insert(4, V);
    // insert(7, V);
    // insert(5, V);

    showLinkedList(V, sizeVector);
    
    free(V); 
}


int main(){
    linkedHash(10);
}