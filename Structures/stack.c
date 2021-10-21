
typedef struct Stack{
    int value;    
    struct Stack *prox; 

} Stack; 


Stack *initStack(){
    Stack *headNode = (Stack*) malloc(sizeof(Stack));  
    headNode->value = 0; 
    headNode->prox = NULL; 
    return headNode; 
}

void insertStack(int value, Stack *headNode){
    Stack *newNode = (Stack*) malloc(sizeof(Stack));
    newNode->value = value; 
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

void showStack(Stack *headNode){
    Stack *temp = headNode->prox; 
    
    while(temp != NULL){
        printf("value: %d\n", temp->value);
        temp = temp->prox; 
    }
    return; 
}




