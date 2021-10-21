#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>

typedef struct no {
   int dado;
   struct no *esq, *dir;
} no;

//Init function makes any sense  ?? 'o.... NO
no* init(){
    no *root = (no*) malloc(sizeof(no));
    root->dir = NULL;
    root->esq = NULL;
    root->dado = 0;
    return root; 
}

no* insert(no *node,int dado){
    no *newNode = (no*) malloc(sizeof(no));
    newNode->dir = NULL;
    newNode->esq = NULL;
    newNode->dado = dado;
    return newNode; 
}


no* searchAndInsert(no *node,int dado){
    if(node == NULL) {return insert(node, dado);}
    // else if(dado > node->dado && node->dir == NULL){ node->dir = insert(node, dado); return NULL; } 
    // else if(dado <= node->dado && node->esq == NULL) {node->esq = insert(node, dado); return NULL; } 
    else if(dado > node->dado) node->dir = searchAndInsert(node->dir, dado);
    else if(dado <= node->dado ) node->esq = searchAndInsert(node->esq, dado);
}

no* search(no *node,int dado){
    if(node == NULL) return NULL; 
    
    else if(node->dado == dado){return node;}   
    else if(node->dado < dado) search(node->dir, dado);
    else if(node->dado > dado) search(node->esq, dado);
}


no* showBinaryTree(no *node){
    if(node->esq != NULL) showBinaryTree(node->esq);
    printf("%d ", node->dado); 
    if(node->dir != NULL) showBinaryTree(node->dir); 
}

int isNotEmpty(no *node){
    return (node != NULL) ?  1 : 0;   
}

no* deleteNode(no *node , int dado){
    no *finding = search(node, 99);
    if(finding != NULL){
        free(finding);
    }
    else{
        printf("This node isn't exists");
    }
    return finding;

    //This will be a lot more complex my brother
}

/*STACK CODE*/

typedef struct Stack{
    struct no *currentNo; 
    struct Stack *prox; 
} Stack; 

Stack *initStack(){
    Stack *headNode = (Stack*) malloc(sizeof(Stack));  
    headNode->currentNo = NULL; 
    headNode->prox = NULL; 
    return headNode; 
}

// void insertStack(no *node, Stack *headNode){
//     Stack *newNode = (Stack*) malloc(sizeof(Stack));
//     newNode->currentNo = node; 
//     newNode->prox = NULL; 
//     if(headNode == NULL){
//         headNode = newNode;
//         return;
//     }
//     newNode->prox = headNode; 
//     headNode = newNode;
//     printf("[%d]\n", headNode->currentNo->dado);
//     return; 
// }

void insertStack(no *node, Stack *headNode){
    Stack *newNode = (Stack*) malloc(sizeof(Stack));
    newNode->currentNo = node; 
    newNode->prox = NULL; 
    if(headNode->prox == NULL){
        headNode->prox = newNode;
        return;  
    }

    newNode->prox = headNode->prox; 
    headNode->prox = newNode; 
    return; 
}

int isEmptyStack(Stack *headNode){
    if(headNode->prox == NULL){
        printf("Stack is empty!\n");
        return 1; 
    } 
    return 0;
}

void popTopStack(Stack *headNode){
    if(isEmptyStack(headNode)) return; 
    Stack *topNode = headNode->prox; 
    headNode->prox = topNode->prox; 
    free(topNode);
    return;  
}

// void showStack(Stack *headNode){
//     Stack *temp = headNode->prox; 
    
//     while(temp != NULL){
//         printf("value: %d\n", temp->value);
//         temp = temp->prox; 
//     }
//     return; 
// }

/*END OF STACK CODE*/
void downhill(no *raiz, Stack *headNode){
    no *aux = raiz; 
    while(aux != NULL){
        insertStack(aux,headNode);
        aux = aux->esq;   
    }    
}
void showStack(Stack *headNode){
    Stack *temp = headNode->prox; 
    
    while(temp != NULL){
        printf("value: %d\n", temp->currentNo->dado);
        temp = temp->prox; 
    }
    return; 
}


void em_ordem (no *raiz){
    no *aux = raiz;
    Stack *headNode = initStack();
    
    // insertStack(aux,headNode);
    
    downhill(raiz, headNode);
    // showStack(headNode);
    // return; 

    // no *reference = (no*) malloc(sizeof(no));
    // reference = headNode->prox->currentNo; 
    // printf("%d", headNode->prox->currentNo->dado);
    // return;
    while(headNode->prox != NULL){
        if(headNode->prox->currentNo->dir != NULL){
            downhill(headNode->prox->currentNo->dir, headNode);

            popTopStack(headNode);
        }
        // if(headNode->prox->currentNo->dir == NULL){
        //     printf("deleted: %d\n", headNode->prox->currentNo->dado);
        //     printf("deleted: %d\n", headNode->prox->currentNo->dado);
        // } 
        showStack(headNode);
    }
    // free(reference);
    // insertStack(raiz , headNode);

    // printf("%d", headNode->currentNo);
    
    // printf("[%d]\n", headNode->prox->currentNo->dado);
    // return; 
    // while(headNode->prox->currentNo != NULL){
    //     downhill(raiz, headNode);
    //     popTopStack(headNode);
        
        
    //     // printf("%d\n", headNode->prox->currentNo->dado);
    //     // // usleep(2000); 
    //     // // continue;
    //     // if(headNode->prox->currentNo->dir != NULL){
    //     //     showStack(headNode);
    //     //     no *aux = headNode->prox->currentNo->dir; 
    //     //     printf("%d", headNode->prox->currentNo->dado);
    //     //     insertStack(aux , headNode);   
    //     //     popTopStack(headNode);
    //     //     // return;
    //     // }
    //     showStack(headNode);
    //     return;
    // }
    // }
};


int main(){
    no *root = NULL; 
    root = searchAndInsert(root , 99); 
    searchAndInsert(root , 6); 
    searchAndInsert(root , 1); 
    searchAndInsert(root , 2); 
    searchAndInsert(root , 4); 
    searchAndInsert(root , 3); 
    searchAndInsert(root , 5); 
    // searchAndInsert(root , 0); 

    // searchAndInsert(root , 838); 

    // showBinaryTree(root);

    // deleteNode(root,15);
    // no *finding = search(root, 99);:
    em_ordem(root); 
    // showBinaryTree(root);
    

    printf("\n");

}