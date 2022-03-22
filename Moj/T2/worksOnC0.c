/**
 * OBJECTIVE:
 * User needs to conquer the max ammount of area in a infinite matrix given a finite time (rounds), witch has a limit in number of actions
 * 
 * 1 - user start with aleatory eadzin position in a infinity matrix  
 * 2 - each edazin only can search one place by turn (loop)
 *     2A - Check if edazin isnt in map borders if not conquer the place
 *     2B - 
 * 3 - Only one domination is possible for rouns (single decision)
 *  
 * 
 * BEGIN:
 * L - Linha 
 * C - Coluna
 * P - Pontos (points that the edazin begin)
 * T - Turnos
 * 
 * TURNS:
 * sondar L C
 * dominar L C 
 * endturn
 * 
 * RESPONSES:
 * for sondar we receive 1 line with the points
 * for domination we receive the number of points earneds in domination
 * 
 * HINTS:
 * 1 - As said i can use a hash table to save the 'matrix'
 * 2 - Use freaking priority queue to save the points and position of them
 * 
 * OBSERVATIONS: 
 * MojinStackho class
 * Map class
 * to receive arbitro data i use scanf
 * to send arbitro information i use printf 
 * 
*/
typedef int Item;

#define key(A) (A) //key(A) (A.chave)
#define less(A,B) (key(A) < key(B))
#define lesseq(A,B) (key(A) <= key(B))
#define exch(A,B) {Item t = A; A = B; B = t;}
#define cmpexch(A,B) {if(less(A,B)) exch(A,B);}  
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXSIZE 100000
#include <sys/resource.h>


static short int cx[8] = {-1 , 0 , 1, -1, 1, -1 , 0 , 1}; 
static short int cy[8] = {-1, -1 ,-1 , 0, 0,  1 , 1,  1}; 
// (-1,-1) , (0,-1) , (1, -1); 
// (-1, 0) , (0, 0) , (1, 0); 
// (-1, 1) , (0,+1) , (1, 1);

typedef struct Game{
    int numberOfMojins; 
    int round; 
}Game; 

typedef struct MojinStack{
    char areaAvaliable[8];  
    long x; 
    long y; 
    struct MojinStack *prox; 
} MojinStack;

typedef struct pQPoints{
    long points;
    long x; 
    long y;  
}pQPoints;

typedef struct BinaryTree{ // THIS IS PART OF MAP STRUCTURE
    long x; 
    long y; 
    int state; 
    long points; 

    long value; //The hash (:

    struct BinaryTree *right; 
    struct BinaryTree *left;
} BinaryTree;

typedef struct LinkedHash{ // THIS IS ALSO PART OF MAP STRUCTURE
    long value; 
    short flag; 
    struct BinaryTree *BtsV; 
}LinkedHash;


typedef struct PriorityQueue
{
    int n;  //Size of priority queue
    struct pQPoints *pQ;  
} PriorityQueue;

/**time to the big ones*/
//BEGIN STRUCTURE TO USER ACTIONS
    MojinStack *initMojinStack(){
        MojinStack *headNode = (MojinStack*) malloc(sizeof(MojinStack));
        for(int i = 0 ; i < 8 ; i++){
            headNode->areaAvaliable[i] = '0';
        }  
        headNode->x = 0; 
        headNode->y = 0; 
        headNode->prox = NULL; 
        return headNode; 
    }
    void insertMojinStack(MojinStack *headNode, long x , long y){
        MojinStack *newNode = (MojinStack*) malloc(sizeof(MojinStack));
        newNode->x = x; 
        newNode->y = y; 
        newNode->prox = NULL; 
        for(int i = 0 ; i < 8 ; i++){
            newNode->areaAvaliable[i] = 0;
        }  


        if(headNode->prox == NULL){
            headNode->prox = newNode;
            return;  
        }

        newNode->prox = headNode->prox; 
        headNode->prox = newNode; 
        return; 
    }
    int isEmptyMojinStack(MojinStack *headNode){
        if(headNode->prox == NULL){
            printf("MojinStack is empty!\n");
            return 1; 
        } 
        return 0;
    }
    void popTopMojinStack(MojinStack *headNode){
        if(isEmptyMojinStack(headNode)) return; 
        MojinStack *topNode = headNode->prox; 
        headNode->prox = topNode->prox; 
        free(topNode);
        return;  
    }     
    void showMojinStack(MojinStack *headNode){
        MojinStack *temp = headNode->prox; 
        
        while(temp != NULL){
            printf("{x: %ld y: %ld}\n", temp->x, temp->y);
            temp = temp->prox; 
        }
        return; 
    }

//END STRUCTURE TO USER ACTIONS

//BEGIN of PRIORITY QUEUE POINTS  
    PriorityQueue *pQInit(int size){
        PriorityQueue *pQItem = (PriorityQueue *) malloc((size+1)*sizeof(PriorityQueue));
        pQItem->pQ = (pQPoints *) malloc((size+1)*sizeof(pQPoints));
        pQItem->n = 0;
        return pQItem; 
    }
    void fixUp(pQPoints *V, int k){
        while(k > 1 && less(V[k/2].points , V[k].points)){
            pQPoints aux = V[k/2]; 
            V[k/2] = V[k];
            V[k] = aux;
            k=k/2;  
        } 
    }
    void fixDown(pQPoints *V, int k, int n){
        int j; 
        while(2*k <= n){
                j = 2*k; 
                if(j < n && less(V[j].points, V[j+1].points)) j++; 
                if(!less(V[k].points, V[j].points)) break; 
                // exch(V[k].points, V[j].points);

                pQPoints aux = V[k]; 
                V[k] = V[j];
                V[j] = aux;
                k = j ; 
        } 
    }
    int pQempty(PriorityQueue *pq){
        return pq->n == 0; 
    }
    void pQinsert(PriorityQueue *pQItem, long x, long y, long points){
        pQItem->pQ[++pQItem->n].points = points;
        pQItem->pQ[pQItem->n].x = x;
        pQItem->pQ[pQItem->n].y = y;


        fixUp(pQItem->pQ, pQItem->n);
        return; 
    }
    void showInterval(int l, int r, pQPoints *pQ){
        for(int i = l ; i <= r ; i++){
            if(pQ[i].points != 0){
                printf("[(%ld, %ld)  %ld]; ", pQ[i].x ,pQ[i].y, pQ[i].points);
            }
        }
        printf("\n");
    }
    int pQDelMaxPriority(PriorityQueue *pQItem){
        pQPoints aux = pQItem->pQ[1]; 
        pQItem->pQ[1] = pQItem->pQ[pQItem->n];
        pQItem->pQ[pQItem->n] = aux;


        fixDown(pQItem->pQ, 1 , --pQItem->n);
        return pQItem->pQ[pQItem->n+1].points;
    }
//END of PRIORITY QUEUE POINTS

//BEGIN OF MAP STRUCTURE
    BinaryTree* insertBt(int btHash, long x, long y, long points){
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
    BinaryTree* searchAndInsertBt(BinaryTree *node,int BTHash, long x, long y, long points){
        if(node == NULL) return insertBt(BTHash, x, y, points);
        else if(BTHash > node->value) node->right = searchAndInsertBt(node->right, BTHash, x, y, points);
        else if(BTHash <= node->value ) node->left = searchAndInsertBt(node->left, BTHash, x, y , points);
        return node;
    }
    void showBinaryTreeIn(BinaryTree *node){
        if(node->left != NULL) showBinaryTreeIn(node->left);
        printf("[%ld (%ld, %ld) pt: %ld ]", node->value, node->x, node->y, node->points); 
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
    int btHash(long x, long y){
        return ((((x<0) ?-x:x)%MAXSIZE)+(((y<0) ?-y:y)/MAXSIZE))/2; 
    }
    int isEmptyLinkedHash(LinkedHash *headNode){
        if(headNode->BtsV == NULL){
            printf("LinkedHash is empty!\n");
            return 1; 
        } 
        return 0;
    }
    BinaryTree* searchBT(BinaryTree *node, int value, long x, long y){ //THIS FUNTION CULD NEED A REPAIR
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
    LinkedHash *mapInsert(LinkedHash *V, long x, long y, long points){ 
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
//END OF MAP STRUCTURE

//BEGIN OF GAME STRUCT
    Game *gameInit(){
        Game *gameInstance = (Game*) malloc((1)*sizeof(Game));
        gameInstance->numberOfMojins = 0; 
        gameInstance->round = 0;
        return gameInstance; 
    }
//END OF GAME STRUCT


/// BEGIN OF BRUTAL LOGIN

    int existsInMap(LinkedHash *VMap, long x, long y){
        // searchBT(bt , btHash(x , y), x , y);
        if(VMap[hash(y)].flag != -1){
            BinaryTree *bt = VMap[hash(y)].BtsV;
            BinaryTree *varReturn = searchBT(bt , btHash(x , y), x , y);
            if(varReturn != NULL){
                // printf("\nFinded: %d (%d , %d)\n", varReturn->value , varReturn->x, varReturn->y);
                return 1;
            }
            else{
                // printf("not finded!\n\n");
                return 0;
            }
        }
        else{
            return 0; 
        }
    }
    int exploreSpace(long x, long y,LinkedHash *VMap,MojinStack *mojinsStack,PriorityQueue *VpQ,Game *gameInstance){
        MojinStack *aux = mojinsStack->prox; 
        while(aux != NULL){
            if(aux->prox == NULL) return 0; 
            for(int i = 0; i < 8  ; i++){
                if(aux->areaAvaliable[i] == 0){ //I can only add into map if the area do not exist                    
                    if(existsInMap(VMap , aux->x+cx[i] ,aux->y+cy[i])){
                        aux->areaAvaliable[i] = 1;
                        continue;
                    }
                    
                    long points = 5; 
                    long bunda;
                    char bundinha[20]; 
                    printf("sondar %ld %ld\n", (aux->x+cx[i]), (aux->y+cy[i]));


                    // scanf(" %*s %*ld %*ld %*ld",  bundinha , &bunda, &bunda,&points); 
                    //REMOVE THIIIIIS
                    // points = (1 + rand() % (50)); 
                    
                    mapInsert(VMap, aux->x+cx[i], aux->y+cy[i], points); //Inserted the points in pq   
                    pQinsert(VpQ, aux->x+cx[i], aux->y+cy[i], points); //Inserted the points in pq
                    
                    break;
                }
            }
            if(aux->areaAvaliable[7] == '1'){
                popTopMojinStack(mojinsStack);
                gameInstance->numberOfMojins--;
            }
            aux = aux->prox; 
        }
        return 1; 
    }
    int dominate(MojinStack *mojinStackHead, PriorityQueue *VpQ, Game *gameInstance){
        printf("dominar %ld %ld\n",VpQ->pQ[1].x,VpQ->pQ[1].y);
        
        // scanf(" %*s %*ld");
        insertMojinStack(mojinStackHead, VpQ->pQ[1].x,VpQ->pQ[1].y);
        gameInstance->numberOfMojins++;

        pQDelMaxPriority(VpQ); 


        return 1; 
    }
/// END OF BRUTAL LOGIC
/** End of the big ones */
void letTheGameBegin(){

    PriorityQueue *VpQ = pQInit(50000);
    LinkedHash *VMap = initLH(MAXSIZE);
    MojinStack *mojinStackHead = initMojinStack();
    Game *gameInstance = gameInit();



    long x = 0, y = 0, points = 0, turns = 0;
    scanf("%ld %ld %ld %ld",&x,&y,&points,&turns);
    
    
    mapInsert(VMap, x, y, points); //Inserted the points in map
    insertMojinStack(mojinStackHead, x,y);

    printf("sondar %ld %ld\n", x-1, y-1);
    mapInsert(VMap,  (x-1), (y-1), points); //Inserted the points in pq   


    printf("fimturno\n");
    fflush(stdout);

    

    scanf(" %*s %*ld %*ld %*ld");

    gameInstance->numberOfMojins++;

    pQinsert(VpQ, x-1, y-1, points); //Inserted the points in pq
    gameInstance->round++;
    turns--;
    //Round 2
    // gameInstance->round++;
    // scanf("%s", queriaDormir);

    //Round 3
    // return;
    
        // showInterval(0, VpQ->n, VpQ->pQ);
        // return; 
        // printf("PointsPq: \n");
        // showInterval(0, VpQ->n, VpQ->pQ);
        // printf("BinaryTree: \n");
        // showLinkedList(VMap, 25);
        // printf("mojinStack: \n");
        // showMojinStack(mojinStackHead); 
        // printf("%d\n", gameInstance->round);


    while(turns--){
        gameInstance->round++;
        
        dominate(mojinStackHead,VpQ, gameInstance);
        exploreSpace(x, y, VMap, mojinStackHead, VpQ, gameInstance);
        printf("fimturno\n");
        fflush(stdout);
        
        scanf(" %*s %*ld");
        scanf(" %*s %*ld %*ld %*ld");
    }


    printf("\n%d\n",gameInstance->numberOfMojins);
    return; 
}

int main(){
    letTheGameBegin(); 
}

