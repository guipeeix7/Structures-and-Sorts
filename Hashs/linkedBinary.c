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


typedef struct BinaryTree
{
    struct BinaryTree *right; 
    struct BinaryTree *left;
    int value; 
} BinaryTree;

typedef struct LinkedHash{
    int value; 
    short flag; 
    struct BinaryTree *BtsV; 
}LinkedHash;


BinaryTree* insertBt(int value){
    BinaryTree *newNode = (BinaryTree*) malloc(sizeof(BinaryTree));
    newNode->right = NULL;
    newNode->left = NULL;
    newNode->value = value;
    return newNode; 
}

BinaryTree* searchAndInsertBt(BinaryTree *node,int value){
    if(node == NULL) return insertBt(value);
    else if(value > node->value) node->right = searchAndInsertBt(node->right, value);
    else if(value <= node->value ) node->left = searchAndInsertBt(node->left, value);
    return node;
}

void showBinaryTreeIn(BinaryTree *node){
    if(node->left != NULL) showBinaryTreeIn(node->left);
    printf("%d ", node->value); 
    if(node->right != NULL) showBinaryTreeIn(node->right); 
}

void deleteTree(BinaryTree* node)
{
    if (node == NULL) return;
 
    deleteTree(node->left);
    deleteTree(node->right);
     
    free(node);
}

LinkedHash *initLH(int sizeVector){
    LinkedHash *V = (LinkedHash*) malloc((sizeVector+1)*sizeof(LinkedHash));
     
    for(int i = 0 ; i < sizeVector ; i++){
        V[i].value = 0; 
        V[i].flag = -1; 
        V[i].BtsV = NULL; 
        // V[i].BtsV = (BinaryTree*) malloc(sizeof(BinaryTree));
        // root = searchAndInsert(root , 321); 
    }   
    return V; 
}

int hash(int num){
    return num%MAXSIZE;
}

int isEmptyLinkedHash(LinkedHash *headNode){
    if(headNode->BtsV == NULL){
        printf("LinkedHash is empty!\n");
        return 1; 
    } 
    return 0;
}

// LinkedHash *search(int value, LinkedHash *headNode, char opt[]){
//     LinkedHash *temp = headNode[hash(value)].BtsV;

//     while(temp != NULL){
//         if(temp->value == value) return temp;
//         temp = temp->prox;
//     }

//     printf("Value not found!\n"); 
//     return NULL; 
// }

BinaryTree* searchBT(BinaryTree *node, int value){ //THIS FUNTION CULD NEED A REPAIR
    if(node == NULL) return NULL; 
    else if(node->value == value){return node;}   
    else if(node->value < value) return searchBT(node->right, value);
    else if(node->value > value) return searchBT(node->left, value);
    return node;
}

BinaryTree *searchNode(LinkedHash *V, int value){
    if(V[hash(value)].flag == -1){
        printf("not finded\n");
        return NULL; 
    } 

    if(searchBT(V[hash(value)].BtsV, value) != NULL){
        printf("finded: %d\n", searchBT(V[hash(value)].BtsV, value)->value);
        return searchBT(V[hash(value)].BtsV, value); 
    }
    return NULL; 
}


//trying to see the hash function
// void showStack(LinkedHash *headNode){
//     LinkedHash *temp = headNode; 
    
//     while(temp != NULL){
//         printf(" -> %d", temp->value);
//         temp = temp->prox; 
//     }
//     return; 
// }


void showLinkedList(LinkedHash *V, int size){
    for(int i = 0 ; i < size ; i++){
        printf("%d: ", V[i].value);
        if(V[i].BtsV != NULL){
            showBinaryTreeIn(V[i].BtsV);   
        } 
        printf("\n");
    }
    return; 
}

// LinkedHash *insertLinked(int value, LinkedHash *headNode){
//     LinkedHash *newNode = (LinkedHash*) malloc(sizeof(LinkedHash));
//     newNode->value = value; 
//     newNode->prox = headNode; 

//     return newNode; 
// }

LinkedHash *insert(int value, LinkedHash *V){ 
    if(V[hash(value)].BtsV == NULL){
        V[hash(value)].BtsV = searchAndInsertBt(V[hash(value)].BtsV, value);
    }
    else{
        searchAndInsertBt(V[hash(value)].BtsV, value);
    }
    
    if(V[hash(value)].flag == -1){
        V[hash(value)].value = hash(value);
    }

    V[hash(value)].flag = 1; 

    return V;
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
    // popTopLinkedHash(V, hash(8));
    // popTopLinkedHash(V, hash(8));
    // popTopLinkedHash(V, hash(8));
    // popTopLinkedHash(V, hash(8));
    // insert(65, V);
    insert(65, V);
    insert(75, V);
    insert(85, V);
    insert(25, V);
    insert(15, V);

    insert(28, V);
    
    showLinkedList(V, sizeVector);

    if(V[hash(28)].flag != -1){
        BinaryTree *varReturn = searchBT(V[hash(15)].BtsV , 28);
        if(varReturn != NULL){
            printf("\nFinded: %d\n", varReturn->value);
        }
        else{
            printf("not finded!\n\n");
        }
    }
    // popTopLinkedHash(&V[hash(8)]);
    // popTopLinkedHash(&V[hash(8)]);
    // popTopLinkedHash(&V[hash(8)]);
    // popTopLinkedHash(&V[hash(8)]);
    // popTopLinkedHash(&V[hash(8)]);
    // popTopLinkedHash(&V[hash(8)]);
    // popTopLinkedHash(&V[hash(8)]);
    // searchNode(10, V);
    // insert(6, V);
    // popTopLinkedHash(&V[hash(4)]);
    // popTopLinkedHash(&V[hash(4)]);
    // popTopLinkedHash(&V[hash(4)]);
    // popTopLinkedHash(&V[hash(4)]);

    // insert(4, V);
    // insert(4, V);
    // insert(7, V);
    // insert(5, V);

    // showLinkedList(V, sizeVector);
    
    free(V);
    return 0; 
}


int main(){
    linkedHash(10);
}