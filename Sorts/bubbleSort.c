void BubbleSortV1(int *V , int l, int r){
    for(int i = l ; i < r ; i++){
        int changes = 0; 
        for(int j = 0 ; j < r ; j++){
            if(less(V[j+1], V[j])){
                exch(V[j] , V[j+1]);
                changes++; 
            }
        }
        if(changes == 0) break;  
    }
    return; 
}


void bubbleSortV2(int *V , int l , int r){
    for(int i = l ; i < r ; i++){
        for(int j = 0 ; j < r-i ; j++){
            cmpexch(V[j] , V[j+1]);
        }
    }
    return;
}



void bubbleSortV2R(int *V , int l , int r){
    if(l == r) return; 
    for(int j = 0 ; j < r-l ; j++){
        cmpexch(V[j], V[j+1]);
    }
    bubbleSortV2R(V, l+1, r);
}
