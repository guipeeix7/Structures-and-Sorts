void M3(int *V, int l, int r){
    int md = (int) (l+r)/2; 
    // if(V[r] < V[l])
    //     exch(V[l],V[r]);       
    // if(V[middle] < V[l])
    //     exch(V[middle], V[l]);
    // if(V[r] < V[middle])
    //     exch(V[r], V[middle]); This fails when vector is reverse ordered
    int a = V[l];
    int b = V[md];
    int c = V[r];
    int mI;

    if (a < b) {
        if (b < c) {
            mI = md;
        } else {
            if (a < c) {
                mI = r;
            } else {
                mI = l;
            }
        }
    } else {
        if (c < b) {
            mI = md;
        } else {
            if (c < a) {
                mI = r;
            } else {
                mI = l;
            }
        }
    }
    exch(V[md], V[r]);
    return;
}
int partition(int *V, int l, int r){
    M3(V, l , r);

    int i = l-1;
    for(int j = l; j < r ; j++){
        if(V[j] <= V[r]){
            i++;
            exch(V[i], V[j]);
        }
    } 
    i++; 
    exch(V[i], V[r]);
    return i; 
}
void quickSortM3(int *V, int l, int r){
    if(l < r ){
        int pivot = partition(V, l, r );
        quickSortM3(V, l , pivot-1); 
        quickSortM3(V, pivot+1, r);
    } 
}

int partitionSel(int *V, int l, int r)
{
    int pivot = V[l];
    int i = l,j; 
 
    for (j = l+1; j <= r; j++)
    {
        if (V[j] <= pivot)
        {
            i++;  
            exch(V[i], V[j]);
        }
    }

    exch(V[i], V[l]);
    return i;
}
 
void quickSelect(int *V, int l, int r, int k)
{   
    if (l < r)
    {   
        int pi = partition(V, l, r);

        if(k == pi+1)
            return;
        if(k <= pi)
            quickSelect(V, l,pi - 1, k);
        if(k > pi)
       	    quickSelect(V,pi + 1, r, k);
    }
}

