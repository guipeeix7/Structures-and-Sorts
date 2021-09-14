void M3(int *V, int l, int r){
    int middle = (int) (l+r)/2; 
    if(V[r] < V[l])
        exch(V[l],V[r]);       
    if(V[middle] < V[l])
        exch(V[middle], V[l]);
    if(V[r] < V[middle])
        exch(V[r], V[middle]);
    
    printf("%d %d %d\n", V[l], V[middle] ,V[r]);
    return;
}
int partition(int *V, int l, int r){
    M3(V, l , r);

    int pv = r, i = l-1;
    for(int j = l; j < r ; j++){
        if(V[j] < V[pv]){
            i++;
            exch(V[i], V[j]);
        }
    } 
    i++; 
    exch(V[i], V[pv]);
    return i; 
}

void quickSortM3(int *V, int l, int r){
    if(r < l) return;
    int pivot = partition(V, l, r );
    quickSortM3(V, l , pivot-1); 
    quickSortM3(V, pivot+1, r);
}
void quickSort(int *V, int l, int r){
    if(r < l) return; 
    int pivot = partition(V, l, r );
    quickSort(V, l , pivot-1); 
    quickSort(V, pivot+1, r);
}

void swap(int A[], int i, int j){
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

int partitionAdt(int A[], int l, int r) {
    //procura a mediana entre i, md e r
    int md = (l + r) / 2;
    int a = A[l];
    int b = A[md];
    int c = A[r];
    int mI;
    // printf("%d %d %d\n", a, b ,c);

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
    swap(A, mI, r);
    int pivo = A[r];
    int i = l - 1;
    int j;
    for (j = l; j <= r - 1; j++) {
        if (A[j] <= pivo) {
            i = i + 1;
            swap(A, i, j);
        }
    }
    swap(A, i + 1, r);
    return i + 1; 
}
void quicksortM3Adapted(int *V, int l, int r) {
    if (l < r) {
        int q = partitionAdt(V, l, r);
        quicksortM3Adapted(V, l, q - 1);
        quicksortM3Adapted(V, q + 1, r);
    }
}