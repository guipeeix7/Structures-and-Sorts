//C Libraries
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <unistd.h> // notice this! you need it!

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

// #define exch(A,B) {Item t = A; A = B; B = t;}
// #define key(A) (A) //key(A) (A.chave)
// Edge EDGE(int, int);

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

void GraphInsert(graph *G, Edge e){
    int v = e.v; 
    int w = e.w; 

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


int main(){
    // int sizeN = 20;
    graph *G = GraphInit(SIZEN); 
    for(int i = 0 ; i < G->V; i++){
        pre[i] = -1; 
    }

    dfsR(G, 0,0); 
}