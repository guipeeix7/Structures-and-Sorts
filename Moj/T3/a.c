#include <stdio.h>
#include <stdlib.h>

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



typedef struct Edge{
    int v; 
    int w; 
}Edge; 

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
        printf("Graph is empty!\n");
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

    printf("Value not found!\n"); 
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

int depthFirstSearchRec(int *pre, Graph *G, Node *cNode){
    if(cNode == NULL) return 0; 
    for(; cNode != NULL ; cNode = cNode->next){
        if(pre[cNode->v] == -1){
            pre[cNode->v]++;
            // printf("%d\n", cNode->v); 
            depthFirstSearchRec(pre,G,G[cNode->v].adj);
        }
    }
}




int bfs(){

}

int main(){

    

    int sizeN = 0;

    scanf("%d" , &sizeN);
    
        
    int cnt = 0; //counter
    GraphData *GData = GDataInit(sizeN);
    Graph *mainGraph = GraphInit(GData);
    int *pre = (int*) malloc(sizeN*sizeof(int));
    for(int i = 0 ; i < sizeN; i++ ){
        pre[i] = -1;
    }

    for(int i = 0; i < sizeN ; i++){
        int v ,w;
        int thisthing = scanf("%d %d", &v, &w); 
        if(thisthing != -1){
            insert(v,w, mainGraph,GData);  
        }
    }
    // insert(5,2, mainGraph,GData);  

    // insert(3,5, mainGraph, GData); 
    // insert(3,4, mainGraph, GData); 
    // insert(9,7, mainGraph, GData); 
    // insert(2 ,10, mainGraph, GData); 

    int islands = 0;

    for(int i =0 ; i < sizeN; i++){
        if(pre[i] == -1){
            depthFirstSearchRec(pre, mainGraph,mainGraph[i].adj);
            islands++;
        }
    }
    
    // showLinkedList(mainGraph, GData->V);
    printf("%d\n", islands); 


    // for(int i = 0 ; i < sizeN; i++){
    //     if(pre[i] != -1 ){
    //         printf(">%d< ", i);
    //     }
    // }
    // printf("\n"); 
    return 0; 
}