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
    int visited;
} Stack; 
//Init function makes any sense  ?? 'o.... NO
no* init(){
    no *root = (no*) malloc(sizeof(no));
    root->dir = NULL;
    root->esq = NULL;
    root->dado = 0;
    return root; 
}

no* insert(int dado){
    no *newNode = (no*) malloc(sizeof(no));
    newNode->dir = NULL;
    newNode->esq = NULL;
    newNode->dado = dado;
    return newNode; 
}


no* searchAndInsert(no *node,int dado){
    if(node == NULL) {return insert(dado);}
    else if(dado > node->dado) node->dir = searchAndInsert(node->dir, dado);
    else if(dado <= node->dado ) node->esq = searchAndInsert(node->esq, dado);
    return node;
}

no* search(no *node,int dado){
    if(node == NULL) return NULL; 
    
    else if(node->dado == dado){return node;}   
    else if(node->dado < dado) search(node->dir, dado);
    else if(node->dado > dado) search(node->esq, dado);
    return node; 
}


no* showBinaryTree(no *node){
    if(node->esq != NULL) showBinaryTree(node->esq);
    printf("%d ", node->dado); 
    if(node->dir != NULL) showBinaryTree(node->dir); 
    return node; 
}

int isNotEmpty(no *node){
    return (node != NULL) ?  1 : 0;   
}

no* deleteNode(no *node , int dado){
    no *finding = search(node, dado);
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
    headNode->visited = 0;

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
    newNode->visited = 0; 
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
        printf("%d ", temp->currentNo->dado);
        temp = temp->prox; 
    }
    return; 
}

void downHill(no *raiz, Stack *headNode, Stack *headWChildOnR){ //Receive a stack value (:
    //Go left adding to the queue whatever the node has a right children
    no *temp = raiz; 

    while(temp != NULL){
        if(temp->dir != NULL){
            insertStack(temp, headWChildOnR); 
        }
        else{
            insertStack(temp, headNode);
        }
        temp = temp->esq; 
    }
    return; 
}

void pos_ordem(no *raiz){
    Stack *headNode = initStack();
    Stack *headWChildOnR = initStack();
    downHill(raiz,headNode,headWChildOnR); 
    while(headNode->prox != NULL || headWChildOnR->prox != NULL){
        no *temp = (no*) malloc(sizeof(no));
        temp = headWChildOnR->prox->currentNo;

        if(headNode->prox != NULL){
            printf("%d ", headNode->prox->currentNo->dado);
            popTopStack(headNode); 
            continue; 
        }// SACANAGEM ISSO AQUI 
        if(headNode->prox == NULL ){
            if(headWChildOnR->prox->visited == 0){
                headWChildOnR->prox->visited = 1;
                downHill(temp->dir, headNode, headWChildOnR);
                continue;             
            } 
            if(headWChildOnR->prox->visited == 1){
                printf("%d ",  headWChildOnR->prox->currentNo->dado);
                popTopStack(headWChildOnR); 
            }
        }
    }
    printf("\n");
};

// //Worked :D
int main(){
    no *root = NULL; 
    int num = 0;
    int begin = 0;  
    // while(scanf("%d", &num) != EOF){
    //     if(begin == 0){
    //         root = searchAndInsert(root , num); 
    //         begin = 1;
    //         continue;
    //     }
    //     searchAndInsert(root , num); 
    // }
        root = searchAndInsert(root , 25); 

    searchAndInsert(root , 15); 
    searchAndInsert(root , 50); 
    searchAndInsert(root , 10); 
    searchAndInsert(root , 22); 
    searchAndInsert(root , 35); 
    searchAndInsert(root , 70); 
    // searchAndInsert(root , 4); 
    searchAndInsert(root , 12); 
    searchAndInsert(root , 18); 
    searchAndInsert(root , 24); 
    searchAndInsert(root , 26); 
    searchAndInsert(root , 31); 
    searchAndInsert(root , 44); 
    searchAndInsert(root , 66); 
    searchAndInsert(root , 90);
    searchAndInsert(root , 91);
    // searchAndInsert(root , 0); 

    // searchAndInsert(root , 838); 

    // showBinaryTree(root);

    // deleteNode(root,15);
    // no *finding = search(root, 99);:
    pos_ordem(root); 
    // showBinaryTree(root);
    

    printf("\n");

}
