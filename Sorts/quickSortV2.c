int M3(int *V, int l , int r){
    int md = (l+r)/2;
    if(V[l] > V[md]) exch(V[l] , V[md]); 
    if(V[md] > V[r]) exch(V[md] , V[r]); 
    if(V[l] > V[md]) exch(V[l] , V[md]); //Fim da ordenação aqui
    exch(V[md] , V[r]);                  //Aqui eu separo e faço o meio ficar em r (:'
}

int partition(int *V, int l, int r){
    M3(V, l ,r);
    int i = l - 1; 
    for(int k = l ; k < r ; k++){
        if(V[k] <= V[r]){
            i++;
            exch(V[k] , V[i]); 
        }
    }
    i++; 
    exch(V[r], V[i]); 
    return i;
}

void quickSort(int *V, int l , int r){
    if(l > r) return; 
    int pv = partition(V, l , r);  
    quickSort(V , l , pv-1); 
    quickSort(V , pv+1 , r); 
}