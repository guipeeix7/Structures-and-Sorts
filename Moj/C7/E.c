#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 

typedef struct BinaryTree
{
    struct BinaryTree *right; 
    struct BinaryTree *left;
    int value; 
} BinaryTree;

BinaryTree* insert(int value){
    BinaryTree *newNode = (BinaryTree*) malloc(sizeof(BinaryTree));
    newNode->right = NULL;
    newNode->left = NULL;
    newNode->value = value;
    return newNode; 
}

BinaryTree* searchAndInsert(BinaryTree *node,int value){
    if(node == NULL) return insert(value);
    else if(value > node->value) node->right = searchAndInsert(node->right, value);
    else if(value <= node->value ) node->left = searchAndInsert(node->left, value);
    return node;
}

void showBinaryTreeIn(BinaryTree *node){
    if(node->left != NULL) showBinaryTreeIn(node->left);
    printf("%c ", node->value); 
    if(node->right != NULL) showBinaryTreeIn(node->right); 
}

void showBinaryTreePos(BinaryTree *node){
    if(node->left != NULL) showBinaryTreePos(node->left);
    if(node->right != NULL) showBinaryTreePos(node->right); 
    printf("%c", node->value); 
}

void showBinaryTreePre(BinaryTree *node){
    printf("%c ", node->value); 
    if(node->left != NULL) showBinaryTreePre(node->left);
    if(node->right != NULL) showBinaryTreePre(node->right); 
}

void deleteTree(BinaryTree* node)
{
    if (node == NULL) return;
 
    deleteTree(node->left);
    deleteTree(node->right);
     
    free(node);
}

int main(){
    int loop = 0, num = 0; 
    scanf("%d",  &loop); 

    while(loop--){
        BinaryTree *root = NULL; 

        int size = 0; 
        char pre[2002] = {'\0'};
        char in[2002] = {'\0'};
        for(int i = 0 ; i < 2002 ; i++){
            pre[i] = '\0'; 
            in[i] = '\0'; 
        }

        scanf("%d %[^ ] %s[\n]", &size, pre, in);
        // printf("%s\n", in);
        // continue; 

        for(int i = 0 ; pre[i] != '\0' ; i++){
            if(i == 0){
                root = searchAndInsert(root , (int) pre[i]);
            }
            else{
                searchAndInsert(root , (int) pre[i]);         
            }
        } 
        
        showBinaryTreePos(root); 
        printf("\n");
        // deleteTree(root); 
        
        
        // if(scanf("%d" , &num) == 1){
        //     root = searchAndInsert(root , num); 
        // }

        // while(scanf("%d" , &num) != EOF){
        //     searchAndInsert(root , num); 
        // }
        
        // if(root != NULL){
        //     showBinaryTreePre(root);
        //     printf(".\n");
        //     showBinaryTreeIn(root);
        //     printf(".\n");
        //     showBinaryTreePos(root);
        //     printf(".\n");
        // }
    }


    
}