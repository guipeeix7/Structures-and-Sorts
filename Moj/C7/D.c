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
    printf("%d ", node->value); 
    if(node->right != NULL) showBinaryTreeIn(node->right); 
}

void showBinaryTreePos(BinaryTree *node){
    if(node->left != NULL) showBinaryTreePos(node->left);
    if(node->right != NULL) showBinaryTreePos(node->right); 
    printf("%d ", node->value); 
}

void showBinaryTreePre(BinaryTree *node){
    printf("%d ", node->value); 
    if(node->left != NULL) showBinaryTreePre(node->left);
    if(node->right != NULL) showBinaryTreePre(node->right); 
}

int main(){
    BinaryTree *root = NULL; 
    int num = 0; 

    if(scanf("%d" , &num) == 1){
        root = searchAndInsert(root , num); 
    }

    while(scanf("%d" , &num) != EOF){
        searchAndInsert(root , num); 
    }
    
    if(root != NULL){
        showBinaryTreePre(root);
        printf(".\n");
        showBinaryTreeIn(root);
        printf(".\n");
        showBinaryTreePos(root);
        printf(".\n");
    }
}