#include <stdio.h>

#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>

typedef struct no {
   int dado;
   struct no *esq, *dir;
} no;

typedef struct Stack{
    struct no *currentNo; 
    struct Stack *prox; 
} Stack; 
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
// void downhill(no *raiz, Stack *headNode){
//     no *aux = raiz; 
//     while(aux != NULL){
//         insertStack(aux,headNode);
//         aux = aux->esq;   
//     }    
// }


void showStack(Stack *headNode){
    Stack *temp = headNode->prox; 
    
    while(temp != NULL){
        printf("value: %d\n", temp->currentNo->dado);
        temp = temp->prox; 
    }
    return; 
}

void downHill(no *raiz, Stack *headNode){ //Receive a stack value (:
    //Go left adding to the queue whatever the node has a right children
    no *temp = raiz; 
    while(temp != NULL){
        insertStack(temp, headNode); 
        temp = temp->esq; 
    }
    return; 
}

void em_ordem (no *raiz){
    no *aux = raiz;
    Stack *headNode = initStack();
    downHill(raiz,headNode); 
    while(headNode->prox != NULL){
        no *temp = (no*) malloc(sizeof(no));
        temp = headNode->prox->currentNo; 
        popTopStack(headNode); 
        if(temp->dir != NULL){
            downHill(temp->dir,headNode); 
        }
        printf("%d ", temp->dado); 
    }
};

// //Worked :D
// int main(){
//     no *root = NULL; 
//     root = searchAndInsert(root , 99); 
//     searchAndInsert(root , 5); 
//     searchAndInsert(root , 3); 
//     searchAndInsert(root , 8); 
//     searchAndInsert(root , 4); 
//     searchAndInsert(root , 3); 
//     searchAndInsert(root , 5); 
//     // searchAndInsert(root , 0); 

//     // searchAndInsert(root , 838); 

//     // showBinaryTree(root);

//     // deleteNode(root,15);
//     // no *finding = search(root, 99);:
//     em_ordem(root); 
//     // showBinaryTree(root);
    

//     printf("\n");

// }
