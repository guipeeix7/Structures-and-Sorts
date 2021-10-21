#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 1048583 

int hash(int num){
    return num%MAXSIZE;
}

void displayMessage(char *V){
    for(int i = 0 ; i < (MAXSIZE+1) ; i++){
        if(V[i] == '\0') continue; 
        
        printf("%c", V[i]);
    }
    printf("\n");
    return;
}

void B(){
    int number = 0; 
    char message = {'0'}; 
    char *V = (char*) malloc((MAXSIZE+1) * sizeof(char));
    for(int i = 0 ; i < (MAXSIZE+1) ; i++){
        V[i] = '\0';
    }   
    
    int biggestNum = 0; 
    while(scanf("%d %c" , &number, &message) != EOF){
        V[hash(number)] = message;
    };
    // return;
    displayMessage(V);

    return; 
}
int main(){
    B();
    return 0;
}

