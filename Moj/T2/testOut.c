//Faço um vetor linear 
//Faço o link de uma linked list com o endereço desse vetor
//Insiro no rabico do vetor adosdkoka
//Lets rush
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <unistd.h> // notice this! you need it!


#define MAXSIZE 10000 

// typedef struct  mapStruct{
//     int x; 
//     int y; 
//     int state; 
//     int points; 
// }mapStruct;

typedef struct BinaryTree
{
    int x; 
    int y; 
    int state; 
    int points; 

    int value; //The hash (:

    struct BinaryTree *right; 
    struct BinaryTree *left;
} BinaryTree;

typedef struct LinkedHash{
    int value; 
    short flag; 
    struct BinaryTree *BtsV; 
}LinkedHash;


BinaryTree* insertBt(int btHash, int x, int y, int points){
    BinaryTree *newNode = (BinaryTree*) malloc(sizeof(BinaryTree));
    newNode->right = NULL;
    newNode->left = NULL;
    newNode->value = btHash;
    newNode->x = x;
    newNode->y = y;
    newNode->points = points;
    newNode->state = 0;

    return newNode; 
}

BinaryTree* searchAndInsertBt(BinaryTree *node,int BTHash, int x, int y, int points){
    if(node == NULL) return insertBt(BTHash, x, y, points);
    else if(BTHash > node->value) node->right = searchAndInsertBt(node->right, BTHash, x, y, points);
    else if(BTHash <= node->value ) node->left = searchAndInsertBt(node->left, BTHash, x, y , points);
    return node;
}

void showBinaryTreeIn(BinaryTree *node){
    if(node->left != NULL) showBinaryTreeIn(node->left);
    printf("[%d (%d, %d) pt: %d ]", node->value, node->x, node->y, node->points); 
    if(node->right != NULL) showBinaryTreeIn(node->right); 
}

void deleteTree(BinaryTree* node)
{
    if (node == NULL) return;
 
    deleteTree(node->left);
    deleteTree(node->right);
     
    free(node);
}

LinkedHash *initLH(int sizeVector){
    LinkedHash *V = (LinkedHash*) malloc((sizeVector+1)*sizeof(LinkedHash));
     
    for(int i = 0 ; i < sizeVector ; i++){
        V[i].value = 0; 
        V[i].flag = -1; 
        V[i].BtsV = NULL; 
    }   
    return V; 
}

int hash(int num){
    return (((num<0) ?-num:num)%MAXSIZE);
}

int btHash(int x, int y){
    return ((((x<0) ?-x:x)%MAXSIZE)+(((y<0) ?-y:y)/MAXSIZE))/2; 
}


int isEmptyLinkedHash(LinkedHash *headNode){
    if(headNode->BtsV == NULL){
        printf("LinkedHash is empty!\n");
        return 1; 
    } 
    return 0;
}

BinaryTree* searchBT(BinaryTree *node, int value, int x, int y){ //THIS FUNTION CULD NEED A REPAIR
    if(node == NULL) return NULL; 
    else if(node->value == value){
        if(node->x == x && node->y == y){
            return node;
        }
        return searchBT(node->left, value, x, y);
    }
    
    else if(node->value < value) return searchBT(node->right, value, x, y);
    else if(node->value > value) return searchBT(node->left, value, x, y);
    return node;
}

void showLinkedList(LinkedHash *V, int size){
    for(int i = 0 ; i < size ; i++){
        printf("%d: ", V[i].value);
        if(V[i].BtsV != NULL){
            showBinaryTreeIn(V[i].BtsV);   
        } 
        printf("\n");
    }
    return; 
}

// LinkedHash *insertLinked(int value, LinkedHash *headNode){
//     LinkedHash *newNode = (LinkedHash*) malloc(sizeof(LinkedHash));
//     newNode->value = value; 
//     newNode->prox = headNode; 

//     return newNode; 
// }

LinkedHash *insert(LinkedHash *V, int x, int y, int points){ 
    if(V[hash(y)].BtsV == NULL){
        V[hash(y)].BtsV = searchAndInsertBt(V[hash(y)].BtsV, btHash(x, y), x, y, points);
    }
    else{
        searchAndInsertBt(V[hash(y)].BtsV, btHash(x, y) , x, y, points);
    }
    
    if(V[hash(y)].flag == -1){
        V[hash(y)].value = hash(y);
    }

    V[hash(y)].flag = 1; 

    return V;
}

int linkedHash(){
    int sizeVector = MAXSIZE;
    LinkedHash *V = initLH(sizeVector);

    //  for(int i = 0 ; i < sizeVector ; i++){
    //     V[i].value = 0; 
    //     V[i].flag = -1; 
    //     V[i].prox = NULL; 
    //     printf("%d", V[i].flag);
    // }   
    // LinkedHash *V, int value, int x, int y, int points
    
    // insert(V, x, y, points);
    // insert(V, 10, 20, 300);
    // insert(V, 23, 12, 32);

    // insert(V, 325, 5345, 543);
    // insert(V, 324, 5355, 543);
    int x, y , points; 
    while(scanf("%d %d %d", &x, &y, &points ) != EOF){
        insert(V, x, y, points);
    }
    // insert(V, 321, 5375, 564);
    
    // insert(V, 21, 323, 4345);
    // insert(V, 12, 3, 434);
    // insert(V, 12, 43, 435);
    // insert(14, V);
    // insert(24, V);
    // insert(34, V);
    // insert(8, V);
    // insert(8, V);
    // insert(9, V);
    // insert(18, V);
    // insert(18, V);
    // insert(28, V);
    // insert(38, V);
    // // insert(8, V);
    // // popTopLinkedHash(V, hash(8));
    // // popTopLinkedHash(V, hash(8));
    // // popTopLinkedHash(V, hash(8));
    // // popTopLinkedHash(V, hash(8));
    // // insert(65, V);
    // insert(65, V);
    // insert(75, V);
    // insert(85, V);
    // insert(25, V);
    // insert(15, V);

    // insert(28, V);
    
    showLinkedList(V, sizeVector);
    // [4679 (219324, 349995) pt: 416839 ]
    if(V[hash(349995)].flag != -1){
        BinaryTree *bt = V[hash(349995)].BtsV;

        printf("Searching: (%d , %d)\n" , 219324 , 349995 ); 
        BinaryTree *varReturn = searchBT(bt , btHash(219324 , 349995), 219324 , 349995);
        if(varReturn != NULL){
            printf("\nFinded: %d (%d , %d)\n", varReturn->value , varReturn->x, varReturn->y);
        }
        else{
            printf("not finded!\n\n");
        }
    }
    // popTopLinkedHash(&V[hash(8)]);
    // popTopLinkedHash(&V[hash(8)]);
    // popTopLinkedHash(&V[hash(8)]);
    // popTopLinkedHash(&V[hash(8)]);
    // popTopLinkedHash(&V[hash(8)]);
    // popTopLinkedHash(&V[hash(8)]);
    // popTopLinkedHash(&V[hash(8)]);
    // searchNode(10, V);
    // insert(6, V);
    // popTopLinkedHash(&V[hash(4)]);
    // popTopLinkedHash(&V[hash(4)]);
    // popTopLinkedHash(&V[hash(4)]);
    // popTopLinkedHash(&V[hash(4)]);

    // insert(4, V);
    // insert(4, V);
    // insert(7, V);
    // insert(5, V);

    // showLinkedList(V, sizeVector);
    
    free(V);
    return 0; 
}


int main(){
    linkedHash(10);
}