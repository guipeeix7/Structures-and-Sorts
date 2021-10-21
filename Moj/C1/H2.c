#include <stdio.h>
#include <string.h>

int H2()
{   
    int correctQuestionsByUser = 0; 
    char userNames[101] = {0}; 
    int loop = 0;
    int instance = 0;
    while(scanf("%d", &loop) != EOF){
        getchar();
        for(int i = 0 ; i < loop ; i++){
            char name[100] = {0};
            int corrects = 0;

            scanf("%s", name);
            scanf("%d", &corrects); 
            
            if(i == 0 || corrects < correctQuestionsByUser){         
                strcpy(userNames,name);
                correctQuestionsByUser = corrects;
            }
            else if(corrects == correctQuestionsByUser){
                if(strcmp(userNames,name) < 0){
                    correctQuestionsByUser = corrects; 
                    strcpy(userNames,name);
                }
            }
        }
        printf("Instancia %d\n", instance+=1);
        printf("%s\n", userNames); 
    }
        

}
int main()
{
    H2();
    return 0;
}