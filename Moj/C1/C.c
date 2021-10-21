#include <stdio.h>
void eofDetect();

int main(){
    eofDetect(); 
    return 0;
}

void eofDetect(){
    int a = 0;
    int count = 0; 
    while(scanf("%d", &a) != EOF) { count++; }

    printf("%d\n", count);
    return; 
}