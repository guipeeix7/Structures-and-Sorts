//Faço um vetor linear 
//Faço o link de uma linked list com o endereço desse vetor
//Insiro no rabico do vetor adosdkoka
//Lets rush
#define MAXSIZE 10 

typedef struct LinkedHash{
    /* data */
    int value; 
    short flag; 
    struct LinkedHash *prox; 
}LinkedHash;

// LinkedHash *initLinkedHash(){
//     LinkedHash *headNode = (LinkedHash*) malloc(sizeof(LinkedHash));  
//     headNode->value = 0; 
//     headNode->prox = NULL; 
//     return headNode; 
// }

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
void popTopLinkedHash(LinkedHash *headNode){
    if(headNode->flag == 1 && headNode->prox == NULL){
        headNode->flag = 0; 
        headNode->value = 0;
        headNode->prox = NULL;
    }
    if(isEmptyLinkedHash(headNode)) return; 
    LinkedHash *headPointer = headNode->prox; 

    LinkedHash *topNode = headNode->prox; 
    headNode->prox = topNode->prox; 
    headNode->value = topNode->value;

    free(topNode);
    return;
}

LinkedHash *search(int value, LinkedHash *headNode, char opt[]){
    if(isEmptyLinkedHash == 0) return NULL;  

    LinkedHash *temp = headNode->prox;
    while(temp != NULL){
        if(temp->value == value) return temp;
        temp = temp->prox;
    }

    printf("Value not found!\n"); 
    return NULL; 
}

LinkedHash *searchNode(int value, LinkedHash **V){
    LinkedHash *NodeSearchReturn = NULL;  

    if(V[hash(value)]->value == value){
        printf("Finded\n"); 
        NodeSearchReturn = V[hash(value)];  
        return V[hash(value)]; 
    }
    else if(V[hash(value)]->flag == 1){
        NodeSearchReturn = search(value, V[hash(value)],  "");
        return (NodeSearchReturn == NULL) ? NULL : NodeSearchReturn;  
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
        printf("%d", V[i].value);
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
    if(V[hash(value)].flag == 1){
        V[hash(value)].prox = insertLinked(value, V[hash(value)].prox);
    }
    else{
        V[hash(value)].value = value;
    }
    V[hash(value)].flag = 1; 
    // It means already used space
}

int linkedHash(int sizeVector){
    LinkedHash *V = (LinkedHash*)  malloc((sizeVector+1)*sizeof(LinkedHash));
     
    for(int i = 0 ; i < sizeVector ; i++){
        V[i].value = 0; 
        V[i].flag = -1; 
        V[i].prox = NULL; 
    }   


    insert(4, V);
    insert(14, V);
    insert(24, V);
    insert(34, V);
    insert(8, V);
    insert(8, V);
    insert(9, V);
    insert(10, V);
    // insert(6, V);
    popTopLinkedHash(&V[hash(4)]);
    popTopLinkedHash(&V[hash(4)]);
    popTopLinkedHash(&V[hash(4)]);
    popTopLinkedHash(&V[hash(4)]);

    insert(4, V);
    insert(4, V);
    insert(7, V);
    insert(5, V);

    showLinkedList(V, sizeVector);
    
    free(V); 
}