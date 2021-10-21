#include <stdio.h> 

void *getInput(){
    int num = 0; 
    while(scanf("%d", &num) != EOF){
        if(num == 42){
            break;
        }
        printf("%d\n", num); 
    }

    while(scanf("%d", &num) != EOF); //It could be a mistake
    return;  
}
void C(){
    getInput(); 
    return;
}

int main(){
    C();
}