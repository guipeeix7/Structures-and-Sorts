#include <stdio.h>
#include <stdlib.h>
#define INIT_SIZE_V 100000
typedef int Item;
#define key(A) (A) //key(A) (A.chave)
#define less(A,B) (key(A) < key(B))
#define lesseq(A,B) (key(A) <= key(B))
#define exch(A,B) {Item t = A; A = B; B = t;}
#define cmpexch(A,B) {if(less(A,B)) exch(A,B);} 


int showVector(int *vector, int lenght){
    for(int i = 0 ; i <= lenght ; i++){
        printf("%d" , vector[i]);
        (i != lenght) ? printf(" ") : printf("\n"); 
    }
    return 0;
}

int intercala2(int* V, int sizeOfBigV,int *V_a, int sizeVa){ 
    int *aux = (int*) malloc((sizeOfBigV+sizeVa+2)*sizeof(int)); 

    int j = 0 , i = 0 , k = 0;  
    while(i <= sizeVa && j <= sizeOfBigV && sizeOfBigV > 0){
        if(lesseq(V_a[i], V[j]))
            aux[k++] = V_a[i++];
        else aux[k++] = V[j++];
    }
    while(i <= sizeVa){
        aux[k++] = V_a[i++]; 
    }


    while(j <= sizeOfBigV && sizeOfBigV > 0){
        aux[k++] = V[j++]; 
    }

    printf("asdad\n");
    showVector(aux,k-1);
    printf("asdad\n");
    
    int p = 0;
    while(p < k){
        V[p] = aux[p];
        p++;
    }        

    showVector(V,k-1);
    // showVector(V, k);

    printf("\n");
    free(aux);
    return sizeVa; 
}

int receiveValues(int *V, int sizeV){
    int i = 0; 
    for(i= 0 ;  i < sizeV ; i++){
        scanf("%d", &V[i]);
    }
    return sizeV - 1; 
}



void A(){
    int sizeOfBigV = 0; 
    int loop = 3;
    int *V = (int*) malloc(INIT_SIZE_V * sizeof(int));  
    while(loop--){
        int sizeA = 0; 
        scanf("%d", &sizeA);
        // getchar(); 
        if(sizeA == 0) continue; 
        int *V_a = (int*) malloc((sizeA+1) * sizeof(int));  

        sizeA = receiveValues(V_a, sizeA); 
  
        sizeOfBigV += intercala2(V, sizeOfBigV, V_a, sizeA);
        printf("->%d<-\n", sizeOfBigV);
        free(V_a);
    }
    showVector(V, sizeOfBigV+1);
 
    free(V);
    return;
}


int main(){
    A();
    return 0;
}

// int *aux = (int*) malloc((sizeOfBigV+sizeVa+1)*sizeof(int));
//     int Vab_size = 0;
    
//     if(sizeOfBigV+sizeVa > INIT_SIZE_V){
//         V = (int*) realloc(V,sizeVa);
//     }

//     int i = 0, j = 0 , k = 0; 
    
//     while(i <= sizeVa && j <= sizeOfBigV && sizeOfBigV > 0){
//         if(lesseq(V_a[i], V[j]))
//             aux[k++] = V_a[i++];
//         else aux[k++] = V[j++];
//     }
//     while(i <= sizeVa) { //This happens because i putting the value readed by the user input, not by my function that reads information
//         aux[k++] = V_a[i++]; 
//     }

//     while(j <= sizeOfBigV && sizeOfBigV > 0) {
//         aux[k++] = V[j++]; 
//     }   

    
//     showVector(aux,k-1); 
//     printf("\n\n");
//     return;
//     int sizeAb = k; 
//     k = 0;     


//     while(k < sizeAb){
//         V[k] = aux[k]; 
//         k++;
//     }
        
//     free(aux);
//     return sizeAb;