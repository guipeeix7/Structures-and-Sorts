//Desfile dos patos

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 1000001 

void arrayClear(int *V){
    for(int i = 0 ; i < MAXSIZE ; i++){
        V[i] = 0; 
    }
    return; 
}

void B(){

    int loop; 
    int *V = (int*) malloc(MAXSIZE*sizeof(int));
    while(1){
        scanf("%d" , &loop); 
        if(loop == 0) break; 
        int duck = 0;

        int lowest = MAXSIZE; 
        int greatest = 0; 
        
        for(int i = 0 ; i < loop ; i++){ 
            scanf("%d", &duck); 
            V[duck]+=1;
            if(duck < lowest){
                lowest = duck;  
            }
            else if(duck > greatest){
                greatest = duck;
            }
        }

        int winner = 0; 
        int votes = 0;

        for(int i = lowest ; i <= greatest ; i++){
            if(V[i] > votes){
                votes = V[i];
                winner = i; 
            }
            V[i] = 0; 
        }
        printf("%d\n", winner);
    }
    return; 
}
int main(){
    B();
    return 0;
}

