#include <stdio.h>
void F(void);
int thisIsNotAloop(char*, int,int);

// quando o paciente responde a sim a duas ou mais perguntas ele faz uma triagem.
/**
* Logo o número de triagens pode ocorrer 
    1 - Sim duas vezes incremente em 1
    2 - Sim a partir de duas vezes, a cada novo sim incrementa em 1
    3 - Dois sim retorna 1
*
**/

void F(){
    char text[1000] = {0};
    scanf("%s", text);
    int pos = thisIsNotAloop(text , 0, 0);
    printf("%d\n" , pos);
    return; 
}

int thisIsNotAloop(char *a ,int val, int pos){
    if(a[pos] == 0) return val;
    if(a[pos] == '7'){
        thisIsNotAloop(a, val+1 ,pos+1);
    } 
    else thisIsNotAloop(a, val ,pos+1);
}

int main(){
    F(); 
    return 0;
}