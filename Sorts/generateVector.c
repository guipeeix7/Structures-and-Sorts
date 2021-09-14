int *generateVector(int sizeVector){
    int *vector = (int*)  malloc((sizeVector+1)*sizeof(int));
    for(int i = 0 ; i <= sizeVector ; i++){
        vector[i] = (1 + rand() % (sizeVector+1000)); 
    }
    return vector;
}

int *generateSeedVector(int sizeVector){
    int *vector = (int*)  malloc((sizeVector+1)*sizeof(int));
    time_t t;

    srand((unsigned) time(&t));
    for(int i = 0 ; i <= sizeVector ; i++){
        vector[i] = (1 + rand() % (sizeVector+1000)); 
    }
    return vector;
}


int *generateOrderedVector(int sizeVector){
    int *vector = (int*)  malloc(sizeVector*sizeof(int));
    for(int i = 0 ; i <= sizeVector ; i++){
        vector[i] = i; 
    }
    return vector;
}

int *generateReverseOrderedVector(int sizeVector){
    int *vector = (int*)  malloc(sizeVector*sizeof(int));
    int j = 0; 
    for(int i =  sizeVector; i >= 0 ; i--){
        vector[j++] = i; 
    }
    return vector;
}


int showVector(int *vector, int lenght){
    
    printf("[");
    for(int i = 0 ; i < lenght ; i++){
        printf(" %d " , vector[i]);
    } 
    printf("]\n");
    return 0;
}

int showVectorIntervals(int *vector, int begin,int end){

    printf("[");
    for(int i = begin ; i <= end ; i++){
        printf(" %d " , vector[i]);
    } 
    printf("]\n");
    return 0;
}
