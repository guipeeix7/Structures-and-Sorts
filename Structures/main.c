#include "header.h"

int main(){
    // PriorityQueue *V = pQInit(500);
    // pQinsert(V, 45); 
    // pQinsert(V, 3);
    // pQinsert(V, 500); 
    // pQinsert(V, 'E'); 
    // pQinsert(V, 'N'); 
    // pQinsert(V, 'H'); 
    // pQinsert(V, 'G'); 
    // pQinsert(V, 'I'); 
    // pQinsert(V, 'R'); 
    // pQinsert(V, 'O'); 
    // pQinsert(V, 500); 
    // pQinsert(V, 100); 
    // pQinsert(V, 200); 
    // pQinsert(V, 50); 
    // pQinsert(V, 1000); 
    // pQDelMaxPriority(V);
    // pQinsert(V, 1000); 
    // showInterval(0,V->n,V->pQ);
    // showInterval(0,100,V->pQ);
    // pQDelMaxPriority(V);
    // showInterval(0,100,V->pQ);
    // pQDelMaxPriority(V);
    // pQDelMaxPriority(V);
    // pQDelMaxPriority(V);
    // showInterval(0,V->n,V->pQ);
    
    //working (:
    

    // //STACK
    // Stack *headNode = initStack();
    // insertStack(9 , headNode);   
    // insertStack(3 , headNode);   
    // insertStack(2 , headNode);   
    // insertStack(4 , headNode);   
    // insertStack(5 , headNode);   
    // insertStack(7 , headNode);   
    // popTopStack(headNode);
    // popTopStack(headNode);
    // popTopStack(headNode);
    // popTopStack(headNode);
    // popTopStack(headNode);
    // showStack(headNode);
    
    DLL *headNode = init();

    // Double linked list
    orderedInserction(0,2,headNode);
    orderedInserction(0,1,headNode);
    orderedInserction(10,3, headNode);
    // orderedInserction(50,5, headNode);
    // orderedInserction(50,4, headNode);
    // orderedInserction(10,0, headNode);

    // printf("%d\n", );
    searchAndDelete(2, headNode);
    searchAndDelete(3, headNode);
    searchAndDelete(10, headNode);
    searchAndDelete(2, headNode);
    searchAndDelete(1, headNode);
    // orderedInserction(10,5, headNode);
    orderedInserction(10,5, headNode);
    // searchAndDelete(2, headNode);
    // searchAndDelete(20, headNode);

    // // orderedInserction(2,40, headNode);

    showList(headNode);
    // printf("==================\n");
    // showReveseList(headNode);
}