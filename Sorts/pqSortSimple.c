#include "./../Structures/priorityQueue.c"

void sortPq(int l, int r, int *V){
    int k; 
    // pQInit(V, r-l+1);
    PriorityQueue *Vpq = pQInit(r-l+1);

    for(k = l ; k<=r; k++) pQinsert(Vpq,V[k]);
    for(k = r ; k>= l ; k--) V[k] = pQDelMaxPriority(Vpq);
}
