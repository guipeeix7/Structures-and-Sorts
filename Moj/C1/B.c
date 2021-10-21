#include <stdio.h>

void soma();
int main(void){
    soma();
    return 0; 
}
void soma(){
    int a = 0,b = 0;
    int soma = 0; 
    scanf("%d", &a);
    scanf("%d", &b);
    soma = a+b; 
    printf("%d\n", soma);
    return; 
}