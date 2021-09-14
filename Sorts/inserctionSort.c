void inserctionSortV2(int *V , int l , int r){
    for(int i = r; i > l ; i--){
        cmpexch(V[i] , V[i-1]);
    }

    for(int i = l+2 ; i <= r ; i++){
        int tempItem = V[i];
        int j = i;   
        while(less(tempItem , V[j-1])){
            V[j] = V[j-1];   
            j--;
        }
        V[j] = tempItem;
    }
    return; 
}


void inserctionSortV1(int *V , int l , int r){
    for(int i = l+1; i <= r ; i++){
        for(int j = i; j > l ; j--){
            cmpexch(V[j], V[j-1]);
        }
    }
    return; 
}