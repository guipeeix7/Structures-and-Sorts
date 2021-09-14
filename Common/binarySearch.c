// https://docs.google.com/drawings/d/1XHUWRaYqVkG22y2mOpPrKwfaNWY2L7cV7DJ3hyRaenM/edit
int binarySearch(int *V, int number,  int l , int r){
    int middle = l+(r-l)/2;
    if(V[middle] == number) return middle;
    else if(l >= r) return -1;
    
    if(V[middle] < number)
        binarySearch(V, number, middle+1, r); 
    else if(V[middle] > number)
        binarySearch(V, number, l, middle-1); 
}