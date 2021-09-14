
typedef struct Item{
    int key; 
    int value;    
    struct Item *prevNodeAddress; 
    struct Item *proxNodeAddress; 

} Item; 

//receive the data to the node ?
// https://docs.google.com/drawings/d/1YZYjI_7NeXlYUMQQAL-116gLrXH4_1RWBKCfwjsFIIc/edit?usp=sharing
// Item *headNode; 
Item *init(){
    Item *headNode = (Item*) malloc(sizeof(Item));  
    headNode->key = 0; 
    headNode->proxNodeAddress = NULL; 
    headNode->prevNodeAddress = NULL; 
    return headNode; 
}

Item *addBeginList(int key, int value, Item *headNode){
    Item *newNode = (Item*) malloc(sizeof(Item)); 
    
    if(headNode->prevNodeAddress == NULL &&  headNode->proxNodeAddress == NULL){
        headNode->proxNodeAddress = newNode; 
        newNode->proxNodeAddress = NULL; 
    }else{
        newNode->proxNodeAddress = headNode->prevNodeAddress; 
        headNode->prevNodeAddress->prevNodeAddress = newNode; 
    }
    newNode->key = key; 
    newNode->value = value;  

    newNode->prevNodeAddress = NULL; 
    headNode->prevNodeAddress = newNode; 

    return newNode; 
}

Item *addEndList( int key, int value, Item *headNode){
    Item *newNode = (Item*) malloc(sizeof(Item)); 
    
    if(headNode->prevNodeAddress == NULL &&  headNode->proxNodeAddress == NULL){
        newNode->prevNodeAddress = NULL; 
        headNode->prevNodeAddress = newNode; 
    }else{
        newNode->prevNodeAddress = headNode->proxNodeAddress; 
        headNode->proxNodeAddress->proxNodeAddress = newNode; 
    }
    newNode->key = key; 
    newNode->value = value;  
    newNode->proxNodeAddress = NULL;  
    headNode->proxNodeAddress = newNode; 

    return newNode; 
}


int isEmpty(Item *headNode){
    if(headNode->proxNodeAddress == NULL && headNode->prevNodeAddress == NULL){
        printf("Double Linked list is empty!\n");
        return 1; 
    } 
    return 0;
}


Item *search(int value, Item *headNode, char opt[]){
    if(isEmpty == 0) return NULL;  

    Item *temp = headNode->prevNodeAddress;
    while(temp != NULL){
        if(temp->value == value) return temp;
        temp = temp->proxNodeAddress;
    }

    printf("Value not found!\n"); 
    return NULL; 
}


void searchAndDelete(int value, Item *headNode){
    if(isEmpty(headNode) == 1) return; 
    
    Item *item = search(value,headNode, "");
    if(item == NULL) return;

    Item *prevNode = item->prevNodeAddress; 
    Item *proxNode = item->proxNodeAddress; 
    Item *aux = item;
    
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

Item exchangePosition(){
    
}
void orderedInserction(int key, int value, Item *headNode){
    //1 - Search for the greater number OK
    //2 - get the Current_Node->prox if its null just insert and set current->prox = new   OK
        //2B - Else get Current_Node->prox->prev and link it to my current node OK
    //3 - Get new->prox and set it to Current_node->prox  OK
    //3 - Get the new->prev and set it to current_node OK

    //1 - If it is the first node change the new->prox = head->prox 
    //2 - head->prox = new

    Item *newNode = (Item *) malloc(sizeof(Item)); 
    newNode->key = key; 
    newNode->value = value; 
    newNode->proxNodeAddress = NULL; 
    newNode->prevNodeAddress = NULL; 

    Item *i = headNode->prevNodeAddress; 
    if(isEmpty(headNode)){
        headNode->prevNodeAddress = newNode; 
        headNode->proxNodeAddress = newNode;
        return;  
    }

    //If is first 
    if(value <= headNode->prevNodeAddress->value){
        newNode->proxNodeAddress = headNode->prevNodeAddress; 
        headNode->prevNodeAddress->prevNodeAddress = newNode;
        headNode->prevNodeAddress = newNode;

        return;
    }
    

    //While is not the last ou is lower than the next number
    while(i->proxNodeAddress != NULL && value >= i->proxNodeAddress->value)
        i = i->proxNodeAddress;
    
    //Set the links in new node
    newNode->proxNodeAddress = i->proxNodeAddress; 
    newNode->prevNodeAddress = i; 

    // set the links to the new node 
    if(i->proxNodeAddress == NULL){
        headNode->proxNodeAddress = newNode; 
    }
    else{
        i->proxNodeAddress->prevNodeAddress = newNode;
    }
    i->proxNodeAddress = newNode; 

    return; 
}

void showList(Item *headNode){
    Item *temp = headNode->prevNodeAddress; 
    
    while(temp != NULL){
        printf("key: %d value: %d\n", temp->key, temp->value);
        temp = temp->proxNodeAddress; 
    }
    return; 
}

void showReveseList(Item *headNode){
    Item *temp = headNode->proxNodeAddress; 
    
    while(temp != NULL){
        printf("key: %d value: %d\n", temp->key, temp->value);
        temp = temp->prevNodeAddress; 
    }
    return; 
}

int *swapNode(){ //It will pick 2 numbers and swap their adress! (This will be insane) 
    return 0; 
}

// int addAfterNode(){
//     return 0;
// }

// int *addEndList(){
//     return 0; 
// }





