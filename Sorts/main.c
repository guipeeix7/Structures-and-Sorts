#include "header.c"

int main(){
    int lenghtOfVector = 5000; //150000 is the test base 2000000
    int *V = generateReverseOrderedVector(lenghtOfVector);
        
    // return 0;
    
    // selectionSortI(V , 0 , lenghtOfVector);
    // real    0m22.022s
    // user    0m22.018s
    // sys     0m0.000s
    
    // selectionSortR(V , 0 , lenghtOfVector);
    // real    0m22.514s
    // user    0m22.510s
    // sys     0m0.000s
    
    // selectionSortV2(V , 0 , lenghtOfVector); 
    // real    0m42.968s
    // user    0m42.966s
    // sys     0m0.000s

    // BubbleSort(V , 0 , lenghtOfVector);
    // real    1m22.464s
    // user    1m22.460s
    // sys     0m0.000s

    // bubbleSortV2(V , 0 , lenghtOfVector); By me Thx God :D 
    // real    0m58.508s
    // user    0m58.505s
    // sys     0m0.000s

    // inserctionSortV1(V , 0 , lenghtOfVector); 
    // real    0m29.217s
    // user    0m29.204s
    // sys     0m0.010s

    // inserctionSortV2(V , 0 , lenghtOfVector);
    // real    0m10.323s
    // user    0m10.310s
    // sys     0m0.010s
    // printf("Sorted\n\n");

    // shellSort(V , 0 , lenghtOfVector);
    // real    0m0.034s
    // user    0m0.032s
    // sys     0m0.000s

    // mergeSort(V , 0 , lenghtOfVector);
    // real    0m0.029s
    // user    0m0.027s
    // sys     0m0.000s
    
    quickSort(V , 0 , lenghtOfVector-1);
    // real    0m0.024s
    // user    0m0.022s
    // sys     0m0.000s
    // showVector(V, lenghtOfVector); 

    // quickSortM3(V , 0 , lenghtOfVector-1);
    // quicksortM3Adapted(V , 0 , lenghtOfVector);
    // real    0m0.004s
    // user    0m0.002s
    // sys     0m0.000s
    // quickSortByInterval(V , 0 , lenghtOfVector,5);

    // quickSelect(V , 0 , lenghtOfVector,5);
    // quickSelect(V, 0, 2000000,10);

    // iReallySholdKnowThisIntroSort(V, 0, lenghtOfVector-1); 
    // showVector(V, lenghtOfVector); 
    // showVector(V, lenghtOfVector); 
    // showVector(V, lenghtOfVector); 
    

    showVectorIntervals(V, 0, lenghtOfVector-1); 
    free(V);
    return 0; 
}