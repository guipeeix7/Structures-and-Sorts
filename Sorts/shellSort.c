void inserctionSortShell(int *V , int l , int r,int h){
    for(int i = l+h ; i <= r ; i++){
        int tempItem = V[i];
        int j = i;   
        while(j >= l+h && less(tempItem , V[j-h])){
            V[j] = V[j-h];   
            j-=h;
        }
        V[j] = tempItem;
    }
    return; 
}

void shellSort(int *V, int l , int r){
    int h; 
    for(h = 1 ; h <= (r-l)/9 ; h=(3*h+1));
    for(;h>0; h=h/3){
        inserctionSortShell(V,l,r,h); 
    }
    return; 
}