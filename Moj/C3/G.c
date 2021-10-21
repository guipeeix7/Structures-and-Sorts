#include <stdio.h>
#include <stdlib.h>

typedef int Item;

#define key(A) (A) //key(A) (A.chave)
#define less(A,B) (key(A) < key(B))
#define lesseq(A,B) (key(A) <= key(B))
#define exch(A,B) {Item t = A; A = B; B = t;}
#define cmpexch(A,B) {if(less(A,B)) exch(A,B);} 

typedef struct LinkedList{
    int val; 
    int prox; 
    int prev; 
} LinkedList; 

LinkedList *ptr1;
LinkedList *ptr2;

void init(){
    ptr1 = (LinkedList *)malloc(sizeof(LinkedList)); 
    ptr2 = (LinkedList *)malloc(sizeof(LinkedList)); 
    ptr1->prev = NULL;
    ptr1->val = NULL;
    ptr1->prox = NULL; 
    
    ptr2->prev = NULL;
    ptr2->val = NULL;
    ptr2->prox = NULL; 

    return;
}

int showVector(int *vector, int lenght){
    for(int i = 0 ; i <= lenght ; i++){
        printf("%d" , vector[i]);
        (i != lenght) ? printf(" ") : printf("\n"); 
    }
}



typedef struct Item{
    int key; 
    int value;    
    struct Item *prevNodeAddress; 
    struct Item *proxNodeAddress; 

} Item; 

//receive the data to the node ?
// https://docs.google.com/drawings/d/1YZYjI_7NeXlYUMQQAL-116gLrXH4_1RWBKCfwjsFIIc/edit?usp=sharing
Item *headNode = NULL;


// Item *headNode; 
Item *initLL(){
    Item *headNode = (Item*) malloc(sizeof(Item));  
    headNode->key = 0; 
    headNode->proxNodeAddress = NULL; 
    headNode->prevNodeAddress = NULL; 
    return headNode; 
}

Item *addBeginList(int key, int value){
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

Item *search(int value, char opt[]){
    Item *temp = headNode;

    while(temp->proxNodeAddress != NULL){
        if(temp->value == value) return temp;
        temp = temp->proxNodeAddress;
    }

    printf("Value not found!\n"); 
    return NULL; 
}

int isEmpty(){
    if(headNode->proxNodeAddress == NULL && headNode->prevNodeAddress == NULL){
        printf("Double Linked list is empty!\n");
        return 1; 
    } 
    return 0;
}


void showList(){
    Item *temp = headNode->prevNodeAddress; 

    while(temp != NULL){
        printf("key: %d value: %d\n", temp->key, temp->value);
        temp = temp->proxNodeAddress; 
    }
    return; 
}

void merge(LinkedList *V, int l, int middle, int r){
    LinkedList *VAux = (LinkedList *)malloc((r-l+1) * sizeof(LinkedList)); 
    int k = 0, i = l, j = middle+1;
    
    while ((i <= middle) && (j <= r))
    {
        if (lesseq(V[i].val, V[j].val)){
            VAux[k++] = V[i++];
        }
        else{
            VAux[k++] = V[j++];
        }
    }
    while (i <= middle){
        VAux[k++] = V[i++];
    }
    while (j<=r){
        VAux[k++] = V[j++];        
    }


    k = 0;
    while((l + k) <= r)
    {
        V[l + k] = VAux[k];
        k++;
    }
    free(VAux); //Free nao funciona em arrays de uma posição
}

int showVectorIntervals(int *vector, int begin,int end){
    printf("[");
    for(int i = begin ; i <= end ; i++){
        printf(" %d " , vector[i]);
    } 
    printf("]\n");
    return 0;
}

void mergeSort(LinkedList *V, int l, int r){
    if (l >= r)
        return;
    int middle = (r + l) / 2;
    mergeSort(V, l, middle);
    mergeSort(V, middle + 1, r);
    merge(V, l, middle, r);
}

int binarySearch(LinkedList *V, int number,  int l , int r){
    int middle = l+(r-l)/2;
    if(V[middle].val == number) return middle;
    else if(l >= r) return -1;
    
    if(V[middle].val < number)
        binarySearch(V, number, middle+1, r); 
    else if(V[middle].val > number)
        binarySearch(V, number, l, middle-1); 

    return -1;
}

int receiveValues(LinkedList *V, int sizeV){
    int i = 0;
    char c_prox = '0' , c_prev = '0', v = '0';  
    while(scanf("%c %c %c", c_prev,c_prox,v) != EOF){
        if(i == 0){
            ptr1->prev = (int) c_prev; 
            ptr1->prox = (int) c_prox; 
            ptr1->val = (int) v; 
        }
        if(i == 1){
            ptr2->prev = (int) c_prev; 
            ptr2->prox = (int) c_prox; 
            ptr2->val = (int) v; 
        }
        
        getChar(); 
        V[i++].prev = (int) c_prev; 
        V[i++].prox = (int) c_prox; 
        V[i++].val = (int) v;  
    }
    return sizeV; 
}

int removePtrs(LinkedList *V, int sizeV){
    int numberOFSalts = 0; 
    int bsReturn = binarySearch(V, V[bsReturn].prox ,0, sizeV);
    
    while(V[bsReturn].val != ptr2->val){
        addBeginList(V[bsReturn].val, 0);
        bsReturn = binarySearch(V, V[bsReturn].prox ,0, sizeV);
        numberOFSalts++; 
        
        //Tipo o free
        V[bsReturn].val = 0; 
        V[bsReturn].prox = 0; 
        V[bsReturn].prev = 0; 
    }

    //Tipo o free
    addBeginList(V[bsReturn].val, 0);
    V[bsReturn].val = 0; 
    V[bsReturn].prox = 0; 
    V[bsReturn].prev = 0; 

    numberOFSalts++;
    if(bsReturn != sizeV){
        V[numberOFSalts].prev = ptr1->prev;
    }

    return numberOFSalts++; 
}

void removeMeuOdio(LinkedList *V, int sizeV){    
    //Fazendo certinho 
    //Andar na lista enquanto não encontrar o valor de ptr1 em algum V.prox; OK 
     //Quando o encontrar devo segurar esse número pois terei de alterar o V.prox com o ptr2.prox ;-; OK
    //Assim que encontrar ptr1 eu insiro os números entre eles em uma 'stack' até encontrar ptr2 OK
    //Quando encontrar ptr2 devo inserir o V.prev que está logo após ptr2 com o valor de V.prox anterior a ptr1 OK
    //Devo mover as lacunas abertas entre os ponteiros (posso fazer isso contando o número de posições entre ptr1 e ptr2) e copiando as posicoes após ptr OK
    //  em V[i] = V[i+tamanho da lacuna]; OK

    //Qual a necessidade desse exercicio ? D:
    // Pronto, acabou comigo esse bagulho T.T
        // if(V[bsReturn].prox == ptr1->val || V[0].val == ptr1->val){ //
        //     V[bsReturn].prox = ptr2->prox; 
        // }
        // if(V[i].val == ptr1->val){
        //     removePtrs(V,sizeV);    
        // }
        

    int bsReturn = 0;
    LinkedList *aux = (LinkedList*) malloc(sizeof(LinkedList)); 
    int numberOfSalts = 0; 
    for(int i = 0 ; i < sizeV ; i++){
        if(V[i].prox = ptr1->val){
            V[i].prox = ptr2->prev;
        }
        
        if(V[i].val == ptr1->val){
            numberOfSalts = removePtrs(V,sizeV);    
        }

        for(int g = i; g < numberOfSalts; g++ ){
            V[i] = V[g+numberOfSalts];
        }

        bsReturn = binarySearch(V, V[bsReturn].prox ,0, sizeV);
    }


    for(int i = 0 ; i <= sizeV-numberOfSalts ; i++){
        printf("%d %d %d\n" , V[i].prev , V[i].val , V[i].prox);
    }
    return; 
}


void F(){
    int sizeV = 0; 
    init();
    LinkedList *V = (LinkedList*) malloc(sizeV*sizeof(LinkedList));
    receiveValues(V, sizeV);
    mergeSort(V, 0, sizeV);
    headNode = initLL();

    removeMeuOdio(V , sizeV);
    showList();

    free(V);
    return;
}

// Recebo os valores OK
// Como o mergeSort eu organizo o array de acordo com o valor; OK 
// Com o binarySearch eu pesquiso o valor
// Com uma lista encadeada eu adiciono e removo o valor (pilha) (:
// No final verifico se a pilha está vazia

int main(){
    F();
}