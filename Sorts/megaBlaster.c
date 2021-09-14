int quickTrapStop = 0; 
void quickSortM3V2(int *V, int l, int r, int maxRecurssion){
    if(maxRecurssion == 0) {quickTrapStop = 1; return;} 
    if(quickTrapStop == 1) return; 
    if(r-l <= 32) return;
    int middle = (l+r)/2; 
    exch(V[middle] , V[r-1]);
    cmpexch(V[middle], V[r]);
    cmpexch(V[l], V[middle]);
    cmpexch(V[r], V[middle]);
    int pivot = partition(V, l, r );
    quickSortM3V2(V, l , pivot-1, maxRecurssion-1); 
    quickSortM3V2(V, pivot+1, r,maxRecurssion-1 );
}

void iReallySholdKnowThisIntroSort(int *V, int l,int r){
    int maxRec = 2*log2((r-l+1));
    quickSortM3V2(V, l , r, maxRec);
    if(quickTrapStop == 1){
        mergeSort(V, l , r); 
    }
    else{
        inserctionSortV2(V, l ,r);
    }
}