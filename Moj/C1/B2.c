#include <stdio.h>

void soma_n();

int main(void){
    soma_n();
    return 0; 
};

void soma_n(){
    int loop = 0; 
    int soma = 0; 
    int userInput = 0;
    scanf("%d", &loop);

    
    while(loop){
        scanf("%d", &userInput);
        soma += userInput; 
        loop--; 
    }

    printf("%d\n", soma);
    return;   
}