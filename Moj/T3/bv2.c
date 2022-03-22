//C Libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // notice this! you need it!

#define SIZEN 20
typedef struct node *linkNode; 

typedef struct node{
    int v;
    linkNode next; 
}node;
typedef struct graph{
    int V;
    int E; 
    linkNode *adj; 
}graph; 

typedef struct Edge{
    int v; 
    int w;
} Edge; 

typedef struct animals{
    char name[31]; 
}animals; 


// #define exch(A,B) {Item t = A; A = B; B = t;}
// #define key(A) (A) //key(A) (A.chave)
// Edge EDGE(int, int);

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

node *New(int v, linkNode next){
    node *x = malloc(sizeof(node)); 
    if(x == NULL){printf("No memory"); return 0;}
    x->v = v; 
    x->next = next; 
    return x; 
}

graph *GraphInit(int V){
    int v;
    graph *G = malloc(sizeof(graph));  
    G->V = V;
    G->E = 0; 
    G->adj = malloc(V*sizeof(linkNode)); 
    for(v = 0 ; v < V ; v++){
        G->adj[v] = NULL;
    }
    return G;
}

void GraphInsert(int v , int w, graph *G){
    // int v = e.v; 
    // int w = e.w; 

    G->adj[v] = New(w, G->adj[v]);
    G->adj[w]= New(v, G->adj[w]);
    G->E++; 
}

int GraphEdges(Edge a[], graph *G){
    int v, E = 0; linkNode t;
    for(v =0 ; v < G->V; v++){
        for(t = G->adj[v]; t!=NULL; t = t->next){
            if(v < t->v){
                a[E].v = v;
                a[E].w = t->v;
                E++;  
            } 
        }
    }
    return E; 
}
static int cnt, pre[SIZEN];

void dfsR(graph *G,int w, int t){
    // int t;
    linkNode l; 
    pre[w] = cnt++; 

    for(l = G->adj[w] ; l != NULL; l=l->next){
        t = l->v; 
        if(pre[t] == -1){
            dfsR(G,w,t);
        }
    }
}

typedef struct DLL{
    int key; 
    int value;    
    struct DLL *prevNodeAddress; 
    struct DLL *proxNodeAddress; 

} DLL; 
DLL *init(){
    DLL *headNode = (DLL*) malloc(sizeof(DLL));  
    headNode->key = 0; 
    headNode->proxNodeAddress = NULL; 
    headNode->prevNodeAddress = NULL; 
    return headNode; 
}

int isEmpty(DLL *headNode){
    if(headNode->proxNodeAddress == NULL && headNode->prevNodeAddress == NULL){
        printf("Double Linked list is empty!\n");
        return 1; 
    } 
    return 0;
}

DLL *search(int value, DLL *headNode, char opt[]){
    if(isEmpty(headNode) == 0) return NULL;  

    DLL *temp = headNode->prevNodeAddress;
    while(temp != NULL){
        if(temp->value == value) return temp;
        temp = temp->proxNodeAddress;
    }

    printf("Value not found!\n"); 
    return NULL; 
}


DLL *addBeginList(int key, int value, DLL *headNode){
    DLL *newNode = (DLL*) malloc(sizeof(DLL)); 
    
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


void searchAndDelete(int value, DLL *headNode){
    if(isEmpty(headNode) == 1) return; 
    
    DLL *item = search(value,headNode, "");
    if(item == NULL) return;

    DLL *prevNode = item->prevNodeAddress; 
    DLL *proxNode = item->proxNodeAddress; 
    DLL *aux = item;
    
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


DLL *queueGet(DLL *headqueue){
    
    return headqueue->proxNodeAddress;
}

void bfs(graph *G, int v, int w, DLL *queue){
    // int v, w; 
    addBeginList(v,w, queue); 

    pre[w] = cnt++; 
    while(!isEmpty(queue)){
        v = queueGet(queue)->key; 
        w = queueGet(queue)->value; 
    }

    for(node *l = G->adj[w] ; l != NULL ; l = l->next){
        int t = l->v;
        if(pre[t] == -1){
            addBeginList(w,t, queue); 
            pre[t] = cnt++; 
        } 
    }
}

void graphSearch(graph *G){
    int v; int conexos = 0; 
    cnt = 0; 
    for(v = 0 ; v < G->V; v++){
        pre[v] = -1;
    }
    for(v = 0; v < G->V; v++){
        if(pre[v] == -1){
            dfsR(G,v,v); 
            conexos++; 
        }
    }
}

static int euPrecisoDormirUrgentementeContador = 0; 

int main(){
    // int sizeN = 20;
    // graph *G = GraphInit(SIZEN); 
    // for(int i = 0 ; i < G->V; i++){
    //     pre[i] = -1; 
    // }

    // dfsR(G, 0,0); 

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
        graph *G = GraphInit(sizeN);
        // Graph *mainGraph = GraphInit(GData);

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
            
            GraphInsert(v,w, G);  
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
                // depthFirstSearchRec(pre, G,G[i].adj);
                bfs(G->adj[i]->v, G);
                if(euPrecisoDormirUrgentementeContador > biggest){
                    biggest = euPrecisoDormirUrgentementeContador; 
                }
                euPrecisoDormirUrgentementeContador = 0; 
                islands++;
            }
        }
        // showLinkedList(mainGraph, GData->V);
        
        printf("%d\n", biggest); 


    }
    return 0; 
}