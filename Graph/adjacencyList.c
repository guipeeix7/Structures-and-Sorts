// typedef struct node *link;

typedef struct Node{
    int v; 
    struct Node *next; 
}Node; 

typedef struct Graph{
    int V; //Vertices
    int E; //Edges
    struct Node *adj; 
}Graph; 

typedef struct Edge{
    int v; 
    int w; 
}Edge; 

// Edge EDGE(int, int);

Node *newNode(int v, Node* next){
    Node *new = (Node*) malloc(sizeof(Node)); 
    if(new == NULL) printf("Could not alloc more memory");
    new->v = v; 
    new->next = next; 
    return new; 
}

Graph *GraphInit(int V){
    int v; 
    Graph *G = (Graph*) malloc(sizeof(Graph)); 
    G->V = V; 
    G->E = 0; 
    G->adj = malloc(V*sizeof(Node*));

    for(v = 0; v < V ; v++){
        G->adj[v] = NULL; 
    }
    return G; 
}

Graph graphInsert(Graph *G, int v, int w){
    G->adj[v] = newNode(w, G->adj[v]); 
    G->adj[w] = newNode(v, G->adj[w]); 

    G->E++;
}

int GraphEdges(Edge a[], Graph *G){
    int v; 
    int E = 0; 
    Node *t; 

    for(v = 0 ; v < G->V ; v++){
        for(t = G->adj[v] ; t!= NULL; t = t->next){
            if(v < t->v){
                a[E++].v = v;
                a[E].w = t->v;
            }
        }  
    }
    return E; 
}


void showLinkedList(Graph *G, int size){
    
    for(int i = 0 ; i < size ; i++){
        printf("%d:", i);
        Node *aux = G[i].adj; 
        if(aux->next != NULL){
             while(aux != NULL){
                printf(" -> %d", aux->v);
                aux = aux->next; 
            }
        } 
        printf("\n");
    }
    return; 
}

int depthFirstSearchRec(Graph *G, Edge e, int *pre, int cnt){
   int t, w = e.w;
   pre[w] = cnt++;
   for(t = 0 ; t < G->V; t++){
       for(Node *tempNode = G->adj[t]; tempNode!= NULL; tempNode = tempNode->next){
           if(pre[t] == -1){
                e.w = w; 
                e.v = t;
                depthFirstSearchRec(G,e, pre, cnt);
           }
       }
   }
}

