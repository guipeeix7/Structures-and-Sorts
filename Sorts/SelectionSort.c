void selectionSortR(int *V, int l, int r)
{
    if (l == r)
        return;
    int min = l;
    for (int i = l + 1; i <= r; i++)
    {
        if (less(V[i], V[min]))
            min = i;
    }
    exch(V[min], V[l]);
    selectionSortR(V, l + 1, r);
}

void selectionSortI(int *V, int l, int r)
{
    for (int i = l; i <= r; i++)
    {
        int min = i;
        for (int j = i + 1; j <= r; j++)
        {
            if (less(V[j], V[min]))
                min = j;
        }
        exch(V[min], V[l]);
    }
    return;
}


void selectionSortV2(int *V , int l , int r){
    for(int i = l; i <= r ; i++){
        int lowest = i; 
        for(int j = i ; j <= r ; j++){
            if(less(V[j] , V[lowest])){
                exch(V[j] , V[lowest]);
                lowest = j; 
            }
        }
    }
    return; 
}
