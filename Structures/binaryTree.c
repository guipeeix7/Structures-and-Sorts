#include <stdio.h>
#include <stdlib.h> 

typedef struct BinaryTree
{
    struct BinaryTree *right; 
    struct BinaryTree *left;
    int value; 
} BinaryTree;


//Init function makes any sense  ?? 'o.... NO
BinaryTree* init(){
    BinaryTree *root = (BinaryTree*) malloc(sizeof(BinaryTree));
    root->right = NULL;
    root->left = NULL;
    root->value = 0;
    return root; 
}

BinaryTree* insert(BinaryTree *node,int value){
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

BinaryTree* search(BinaryTree *node,int value){
    if(node == NULL) return NULL; 
    
    else if(node->value == value){return node;}   
    else if(node->value < value) search(node->right, value);
    else if(node->value > value) search(node->left, value);
}


BinaryTree* showBinaryTree(BinaryTree *node){
    if(node->left != NULL) showBinaryTree(node->left);
    printf("%d ", node->value); 
    if(node->right != NULL) showBinaryTree(node->right); 
}

int isNotEmpty(BinaryTree *node){
    return (node != NULL) ?  1 : 0;   
}

BinaryTree* deleteNode(BinaryTree *node , int value){
    BinaryTree *finding = search(node, 99);
    if(finding != NULL){
        free(finding);
    }
    else{
        printf("This node isn't exists");
    }
    return finding;
    //This will be a lot more complex my brother
}

int main(){
    BinaryTree *root = NULL; 
    root = searchAndInsert(root , 321); 
    // searchAndInsert(root , 949); 
    // searchAndInsert(root , 524); 
    // searchAndInsert(root , 6); 
    // searchAndInsert(root , 100); 
    // searchAndInsert(root , 838); 

    // showBinaryTree(root);

    // deleteNode(root,15);
    // BinaryTree *finding = search(root, 99);:
    
    showBinaryTree(root);
    

    printf("\n");

}

//This is the BINARY tree
//INSERCTION
//Insert by find the right place.... if the current number is lower then the actual node go to the left, ohterwise go to the right
//when finded the right place to the node, just point the root to the new node

//SEARCH
//If the desired number is lower go to the left node otherwise go to the right node 
//If finded return 1 else 0 
//The node is not finded when i find i null pointer but not the desired number

//Deletion
//This gonne be a challange
//i search for the value in the node and when the value is finded i:
//Save the pointer of root node to the exclude_node.

//if the right pointer of the exclude_node is not null change the ponter from root to exclude_node to the right
//Else change the pointer from ther root node to the exclude_node to the left

//Save the reference of the right and the left node
//if right node of the excluded node is not NULL i go all the way to the left and when i find the NULL ponter i change it to the reference of the left node (; 
//Otherwise i do the oposite

//If the node is the head i do the same steps above but changing the ROOOOOT node (:  

//BALANCE THE BINARY TREE
//This is hard baby (; 
//But i understand harf things ;D

//Ook thuthuthuthut thuchutchu tchutchu thcutchutchu tchu tchu thu thu thu thu thu hthuuuut thu thu (loop) 





