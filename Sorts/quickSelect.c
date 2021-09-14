void quickSelect(int *V, int l, int r, int k)
{   
    if (l < r)
    {   
        int pi = partition(V, l, r);
        if(k == pi)
            return;
        if(k <= pi)
            quickSelect(V, l,pi - 1, k);
        if(k > pi)
       	    quickSelect(V,pi + 1, r, k);
    }
}
