#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 10 

typedef struct Node{
    int v; 
    struct Node *next; 
}Node; 

typedef struct Graph{
    // int V; //Vertices
    // int E; //Edges
    short flag; 
    struct Node *adj; 
}Graph; 

typedef struct GraphData{
    int V; //Vertices
    int E; //Edges
    // short flag; 
    // struct Node *adj; 
}GraphData; 


typedef struct animals{
    char name[31]; 
}animals; 

typedef struct Edge{
    int v; 
    int w; 
}Edge; 

// https://docs.google.com/drawings/d/1XHUWRaYqVkG22y2mOpPrKwfaNWY2L7cV7DJ3hyRaenM/edit
int binarySearch(animals *V, char *nameOfAnimal,  int l , int r){
    int middle = l+(r-l)/2;
    if(strcmp(nameOfAnimal, V[middle].name ) == 0) return middle;
    else if(l >= r) return -1;
    
    if(strcmp(V[middle].name, nameOfAnimal) < 0) //<
        binarySearch(V, nameOfAnimal, middle+1, r); 
    else if(strcmp(V[middle].name, nameOfAnimal) > 0) //>
        binarySearch(V, nameOfAnimal, l, middle-1); 
}

void merge(animals *V, int l, int middle, int r)
{
    animals *VAux = (animals *)malloc((r-l+1) * sizeof(animals)); 
    int k = 0, i = l, j = middle+1;
    while ((i <= middle) && (j <= r)){
        if (strcmp(V[i].name, V[j].name) < 0){
            // VAux[k++] = V[i++];
            strcpy(VAux[k++].name, V[i++].name ); 
        }
        else{
            // VAux[k++] = V[j++];
            strcpy(VAux[k++].name, V[j++].name); 
        }
    }
    while (i <= middle){
        // VAux[k++] = V[i++];
        strcpy(VAux[k++].name, V[i++].name); 
    }
    while (j<=r){
        // VAux[k++] = V[j++];        
        strcpy(VAux[k++].name, V[j++].name); 
    }
    k = 0;
    while((l + k) <= r){
        // V[l + k] = VAux[k];
        strcpy(V[l+k].name, VAux[k].name); 
        k++;
    }
    free(VAux); //Free nao funciona em arrays de uma posição
}

void mergeSort(animals *V, int l, int r)
{
    if (l >= r)
        return;
    int middle = (r + l) / 2;
    mergeSort(V, l, middle);
    mergeSort(V, middle + 1, r);
    merge(V, l, middle, r);
}


Graph *GraphInit(GraphData *GD){
    Graph *G = (Graph*) malloc(GD->V*sizeof(Graph));

    for(int i = 0 ; i < GD->V ; i++){
        G[i].flag = -1; 
        G[i].adj = NULL; 
    }   
    return G; 
}

GraphData *GDataInit(int numberOfNodes){
    GraphData *GD = (GraphData*) malloc(sizeof(GraphData));
    GD->V = numberOfNodes; 
    GD->E = 0;
    return GD;  
} 


int isEmptyLinkedHash(Graph *G){ //Deve receber o G[?]
    if(G->adj == NULL){
        return 1; 
    } 
    return 0;
}

Node *search(int v, Graph *G, char opt[]){
    Node *temp = G[v].adj;

    while(temp != NULL){
        if(temp->v == v) return temp;
        temp = temp->next;
    }
    return NULL; 
}

Node *searchNode(int v, Graph *G){

    if(G[v].flag == -1){
        printf("not finded\n");
        return NULL; 
    } 
    if(search(v, G,  "") != NULL){
        printf("finded: %d\n", search(v, G,  "")->v);
        return search(v, G,  ""); 
    }
    return NULL; 
}

//trying to see the hash function
void showStack(Node *headNode){
    Node *temp = headNode; 
    
    while(temp != NULL){
        printf(" -> %d", temp->v);
        temp = temp->next; 
    }
    return; 
}


void showLinkedList(Graph *G, int size){
    for(int i = 0 ; i < size ; i++){
        printf("%d:", i);
        if(G[i].adj != NULL){
            // printf("%d:", i);
            showStack(G[i].adj);   
            // printf("\n");
        } 
        printf("\n");
    }
    return; 
}

Node *graphInsert(int v, int w, Node *headNode){
    Node *newNode = (Node*) malloc(sizeof(Node));
    if(newNode == NULL) printf("Could not alloc more memory");

    newNode->v = v; 
    newNode->v = w; 
    newNode->next = headNode; 


    return newNode; 
}

Graph *insert(int v, int w, Graph *G, GraphData *GD){ 
    G[v].adj = graphInsert(v, w, G[v].adj);
    G[w].adj = graphInsert(w,v, G[w].adj);
    GD->E++;

    G[v].flag = 1; 
}


// int depthFirstSearchRec(Graph *G, int v, int w, int *pre, int cnt){
//    int t;
//    pre[v] = cnt++;
//    for(t = 0 ; t < G->V; t++){
//        for(Node *tempNode = G[v]->adj; tempNode!= NULL; tempNode = tempNode->next){
//            if(pre[t] == -1){
//                 e.w = w; 
//                 e.v = t;
//                 depthFirstSearchRec(G,e, pre, cnt);
//            }
//        }
//    }
// }

#define MAX 5001

int intArray[MAX];
int front = 0;
int rear = -1;
int itemCount = 0;

int peek()
{
    return intArray[front];
}

int isEmpty()
{
    return itemCount == 0;
}

int isFull()
{
    return itemCount == MAX;
}

int size()
{
    return itemCount;
}

void insertQueue(int data)
{

    if (!isFull())
    {

        if (rear == MAX - 1)
        {
            rear = -1;
        }

        intArray[++rear] = data;
        itemCount++;
    }
}

int removeData()
{
    int data = intArray[front++];

    if (front == MAX)
    {
        front = 0;
    }

    itemCount--;
    return data;
}

static int euPrecisoDormirUrgentementeContador = 0; 
int depthFirstSearchRec(int *pre, Graph *G, Node *cNode){
    if(cNode == NULL) return 0; 
    for(; cNode != NULL ; cNode = cNode->next){
        if(pre[cNode->v] == -1){
            pre[cNode->v]++;
            // printf("%d\n", cNode->v); 
            euPrecisoDormirUrgentementeContador++;
            depthFirstSearchRec(pre,G,G[cNode->v].adj);
        }
    }
}

// int bfs(int *pre, Graph *G, Node *cNode){
//     //Get the initial node OK
//     //Run Search in all edges OK
//     ////Add the adges to queue OK
//     ////Change the pre  OK
//     ////at the end of search cut the first element in the queue and continue with the second
//     if(cNode == NULL) return 0; 
//     insertQueue(cNode->v);
//     if(pre[cNode->v] == -1){
//         pre[cNode->v]++;
//     }
    
//     while(!isEmpty() && pre[cNode->v] == -1){
//         // if(pre[cNode->v] == -1){
//         //     pre[cNode->v]++;
//         // }
//         cNode = cNode->next;
//         insertQueue(cNode->v);
//         if(cNode == NULL){
//             removeData(); //Remove o mais velho
//             cNode = G[intArray[front]].adj; //Cnode é o proximo elemento da queue
//             if(cNode != NULL){
//                 pre[cNode->v]++;
//                 insertQueue(cNode->v);
//             }
//         }
//     }
//     // for(; ){
//     //     insertQueue(cNode->v);
        
//     //     while(!isEmpty() && ){

//     //     }
//     // }

// }


void bfs(int *pre, Graph *G, Node *cNode){
    int v= 0, w=0; 
    if(cNode == NULL) return 0; 

    pre[cNode->v]++; 
    while(!isEmpty()){
        v = G[intArray[front]].adj->v;
    }

    for(Node *l = cNode ; l != NULL ; l = l->next){
        int t = l->v;
        if(pre[t] == -1){
            insertQueue(t);  
            pre[t]++; 
        } 
        removeData();
    }
}

int main(){
    while(1){
        int sizeN = 0;
        int relastionships = 0;
        scanf("%d %d" , &sizeN, &relastionships);
        if(!sizeN && !relastionships) return 0; 
        animals *aVec = (animals*) malloc((sizeN+1)*sizeof(animals));
        

        for(int i = 0 ; i < sizeN ; i++ ){
            char name[31] = {'\0'}; 
            scanf("%s", name);
            getchar();  

            strcpy(aVec[i].name, name);
        }
        

        mergeSort(aVec, 0, sizeN-1); //PODE ME DAR PROBLEMA ESSA LINHA*****
        // for(int i = 0 ; i < sizeN; i++){
        //     printf("%s\n", aVec[i].name); 
        // }
        int cnt = 0; //counter
        GraphData *GData = GDataInit(sizeN);
        Graph *mainGraph = GraphInit(GData);
        int *pre = (int*) malloc(sizeN*sizeof(int));
        for(int i = 0 ; i < sizeN; i++ ){
            pre[i] = -1;
        }

        // return 0;    
        for(int i = 0; i < relastionships ; i++){
            char vS[30] = {'\0'} ,wS[30] = {'\0'};
            int thisthing = scanf("%s %s", vS, wS); 
            getchar();


            int v = binarySearch(aVec, vS, 0, sizeN-1);
            int w = binarySearch(aVec, wS, 0, sizeN-1); 
            // printf("[%s %s]\n", vS, wS);
            
            insert(v,w, mainGraph,GData);  
            // printf("%d %d\n", v,w);
            // if(thisthing != -1){
            // }
        }
        // return; 
        // showLinkedList(mainGraph, GData->V);

        // insert(5,2, mainGraph,GData);  

        // insert(3,5, mainGraph, GData); 
        // insert(3,4, mainGraph, GData); 
        // insert(9,7, mainGraph, GData); 
        // insert(2 ,10, mainGraph, GData); 
        int islands = 0;
        int biggest = 0; 
        int counter = 0;
        for(int i = 0 ; i < sizeN; i++){
            if(pre[i] == -1){
                insertQueue(i);  
                bfs(pre, mainGraph, mainGraph[i].adj);
                // depthFirstSearchRec(pre, mainGraph,mainGraph[i].adj);
                if(euPrecisoDormirUrgentementeContador > biggest){
                    biggest = euPrecisoDormirUrgentementeContador; 
                }
                euPrecisoDormirUrgentementeContador = 0; 
                islands++;
            }
        }
        // showLinkedList(mainGraph, GData->V);
        
        printf("%d\n", biggest); 


        // for(int i = 0 ; i < sizeN; i++){
        //     if(pre[i] != -1 ){
        //         printf(">%d< ", i);
        //     }
        // }
        // printf("\n"); 
    }
    return 0; 
}