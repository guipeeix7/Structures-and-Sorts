static int N; 
// static Item *pq; 
/**
 * Insert 
 * Delete
 * Fix Up 
 * Fix Down
 * Sort 
 */ 

typedef struct PriorityQueue
{
    int n;  //Size of priority queue
    int *pQ;  
} PriorityQueue;

PriorityQueue *pQInit(int size){
    PriorityQueue *pQItem = (PriorityQueue *) malloc(sizeof(PriorityQueue));
    pQItem->pQ = (Item *) malloc((size+1)*sizeof(Item));
    pQItem->n = 0;
    return pQItem; 
}

void fixUp(int *V, int k){
    while(k > 1 && less(V[k/2] , V[k])){
        exch(V[k], V[k/2]);
        k=k/2;  
    } 
}

void fixDown(int *V, int k, int n){
   int j; 
   while(2*k <= n){
        j = 2*k; 
        if(j < n && less(V[j], V[j+1])) j++; 
        if(!less(V[k], V[j])) break; 
        exch(V[k], V[j]); 
        k = j ; 
   } 
}
int pQempty(PriorityQueue *pq){
    return pq->n == 0; 
}

void pQinsert(PriorityQueue *pQItem, int novo){
    pQItem->pQ[++pQItem->n] = novo;
    fixUp(pQItem->pQ, pQItem->n);
    return; 
}

void showInterval(int l, int r, int *pQ){
    for(int i = l ; i <= r ; i++){
        if(pQ[i] != 0){
            printf("%d ", pQ[i]);
        }
    }
    printf("\n");
}

int pQDelMaxPriority(PriorityQueue *pQItem){
    exch(pQItem->pQ[1], pQItem->pQ[pQItem->n]); 
    fixDown(pQItem->pQ, 1 , --pQItem->n);
    return pQItem->pQ[pQItem->n+1];
}

// void sortPq(int l, int r, int *V){
//     int k; 
//     pQInit(r-l+1);
//     for(k = l ; k<=r; k++) pQinsert(V,V[k]);
//     for(k = r ; k>= l ; k--) V[k] = pQDelMaxPriority(V);
// }
