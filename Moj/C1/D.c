#include <stdio.h>
void triagem();

int main(){
    triagem(); 
    return 0;
}
// quando o paciente responde a sim a duas ou mais perguntas ele faz uma triagem.
/**
* Logo o número de triagens pode ocorrer 
    1 - Sim duas vezes incremente em 1
    2 - Sim a partir de duas vezes, a cada novo sim incrementa em 1
    3 - Dois sim retorna 1
*
**/
void triagem(){
    int a = 0;
    int count = 0;
    char blau;
    int result = 0; 

    while(scanf(" %c", &blau) != EOF) { 
        if(blau == 's'){
            count++; 
            // if(count >= 2){
            //     count = 0;  
            //     result +=1;
            // }
            // if(count >= 2){  
            //     result +=1;
            // }
            if(count == 2){  
                result +=1;
            }
        }
    }

    printf("%d\n", result);
    return; 
}