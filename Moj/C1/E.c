#include <stdio.h>
#include <stdlib.h>

void cursorEditor();

int main(){
    cursorEditor(); 
    return 0;
}

void cursorEditor(){
    int lines = 0; 
    scanf("%d", &lines);    

    char** text = (char**) calloc(lines+1, sizeof(char**)); 
    for(int i = 0; i <= lines ; i++ ){
        text[i] = (char*) calloc(1001 ,sizeof(char)); 
    }

    int i = 1; 
    getchar();
    while(i <= lines){
        scanf("%[^\n]", text[i]);
        getchar();
        i++;
    }
    
    int C_I = 0, C_J = 0;
    scanf("%d%d", &C_I, &C_J); 

    char cmd;
    getchar();
    
    while(scanf("%c", &cmd) != EOF){
        getchar();
        int currentPosition = C_J; 
        if(cmd == 'j' && C_I < lines){
            C_I++; 
        }
        else if(cmd == 'k' && C_I > 1){
            C_I--;
        }
        int i = 0; 

        while(text[C_I][i] != 0){
            if(currentPosition == i){
                break;
            }
            i++;
        }
        printf("%d %d %c\n",C_I, i, text[C_I][i-1]); 
    }
}