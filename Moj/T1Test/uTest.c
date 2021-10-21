#include "header.h"

int main(){
    int lenghtOfVector = 200000; //150000 is the test base 2000000
    int *V = generateVector(lenghtOfVector);
    
    // showVector(V, lenghtOfVector);
    // quicksortM3Adapted(V, 0, lenghtOfVector); 
    // printf("%d\n", V[lenghtOfVector]) ;
    // quickSortM3(V, 0, lenghtOfVector);
    // showVectorIntervals(V, 0,20);
    // quickSelect(V, 0, lenghtOfVector, 10); 
    showVectorModified(V, lenghtOfVector);
    // showVectorIntervals(V, 0,100);

    free(V); 
}