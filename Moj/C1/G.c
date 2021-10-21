#include <stdio.h>

int minimallySurpasses(int *v ,int minimal,int currentVal, int pos){
    if(v[pos] == 0){
        return 0; 
    }
    else if(v[pos] >  minimal || v[pos]+currentVal > minimal){
        currentVal = 0; 
        minimallySurpasses(v, minimal, currentVal, pos+1); 
        printf("%d\n" ,v[pos]);
        return 0; 
    }
    else{
        minimallySurpasses(v, minimal, currentVal+v[pos], pos+1); 
        return 0;
    }
}
int G(){
    int v[10000] = {0};
    int i = 0;
    while(1){
        scanf("%d", &v[i]);
        if(v[i] == 0) break;
        i++; 
    }
    int minimal = 0;
    getchar();
    scanf("%d", &minimal);
    getchar();
    minimallySurpasses(v , minimal, 0 , 0); 
    return 0;

}


int main(){
    G(); 
    return 0;
}
