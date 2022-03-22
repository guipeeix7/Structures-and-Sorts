#include "./header.h"
Edge EDGE(int, int);

int main(){

    

    int sizeN = 20; 
    int cnt = 0; //counter
    GraphData *GData = GDataInit(sizeN);
    Graph *mainGraph = GraphInit(GData);
    int *pre = (int*) malloc(sizeN*sizeof(int));
    for(int i = 0 ; i < sizeN; i++ ){
        pre[i] = -1;
    }

    insert(5,2, mainGraph,GData);  

    // insert(3,5, mainGraph, GData); 
    // insert(3,4, mainGraph, GData); 
    // insert(9,7, mainGraph, GData); 
    // insert(2 ,10, mainGraph, GData); 
    showLinkedList(mainGraph, GData->V);


    depthFirstSearchRec(pre, mainGraph,mainGraph[7].adj);
    for(int i = 0 ; i < sizeN; i++){
        if(pre[i] != -1 ){
            printf(">%d< ", i);
        }
    }
    printf("\n"); 
    return 0; 
}