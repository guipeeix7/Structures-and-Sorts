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
#define MAXSIZE 10 


typedef struct MojinStack{
    char areaAvaliable[8]; 
    int x; 
    int y; 
    struct MojinStack *prox; 
} MojinStack;

typedef struct pQPoints{
    int points;
    int x; 
    int y;  
}pQPoints;

typedef struct  mapStruct{
    int x; 
    int y; 
    int state; 
    int points; 
}mapStruct;


typedef struct PriorityQueue
{
    int n;  //Size of priority queue
    struct pQPoints *pQ;  
} PriorityQueue;

/**time to the big ones*/
//BEGIN STRUCTURE TO USER ACTIONS
    MojinStack *initMojinStack(){
        MojinStack *headNode = (MojinStack*) malloc(sizeof(MojinStack));  
        headNode->x = 0; 
        headNode->y = 0; 
        headNode->prox = NULL; 
        return headNode; 
    }
    void insertMojinStack(int *value, MojinStack *headNode){
        MojinStack *newNode = (MojinStack*) malloc(sizeof(MojinStack));
        newNode->x = value[0]; 
        newNode->y = value[1]; 
        newNode->prox = NULL; 
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
            printf("value: %d %d\n", temp->x, temp->y);
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
                exch(V[k].points, V[j].points); 
                k = j ; 
        } 
    }
    int pQempty(PriorityQueue *pq){
        return pq->n == 0; 
    }
    void pQinsert(PriorityQueue *pQItem, int points, int x, int y){
        pQItem->pQ[++pQItem->n].points = points;
        pQItem->pQ[pQItem->n].x = x;
        pQItem->pQ[pQItem->n].y = y;
        fixUp(pQItem->pQ, pQItem->n);
        return; 
    }
    void showInterval(int l, int r, pQPoints *pQ){
        for(int i = l ; i <= r ; i++){
            if(pQ[i].points != 0){
                printf("%d ", pQ[i].points);
            }
        }
        printf("\n");
    }
    int pQDelMaxPriority(PriorityQueue *pQItem){
        exch(pQItem->pQ[1].points, pQItem->pQ[pQItem->n].points); 
        fixDown(pQItem->pQ, 1 , --pQItem->n);
        return pQItem->pQ[pQItem->n+1].points;
    }
//END of PRIORITY QUEUE POINTS

//BEGIN OF MAP STRUCTURE
    int Hash(int hKey){
        return hKey%101; 
    }
    typedef struct LinkedHash{
        /* data */
        int key; 
        char value[102]; 
        short flag; 
        struct LinkedHash *prox; 
    }LinkedHash;
    int hKey(char *key){
        int hKey = 0; 
        for(int i = 0 ; key[i] != '\0' ; i++){
            hKey+=((int) key[i]*(i+1));
        }   
        return Hash(19*hKey); 
    }
    LinkedHash *insertLinked(char *value, LinkedHash *headNode, int hkey){

        LinkedHash *newNode = (LinkedHash*) malloc(sizeof(LinkedHash));
        strcpy(headNode[hkey].value, value);
        headNode[hkey].key = hkey;
        newNode->prox = headNode; 

        return newNode; 
    }
    int insert(char *value, LinkedHash *V){ 
        int hkey = hKey(value); 
        int inserctions = 0;
        
        if(V[hkey].flag == 1){
            return 0; 
            // V[hkey].prox = insertLinked(value, V[hKey(value)].prox, hkey);
        }
        else{
            strcpy(V[hkey].value, value); 
            V[hkey].key = hkey;
            V[hkey].flag = 1; 
            return 1; 
        }
        // It means already used space

    }
    int isEmptyLinkedHash(LinkedHash *headNode){
        if(headNode->prox == NULL){
            return 1; 
        } 
        return 0;
    }
    int popTopLinkedHash(LinkedHash *headNode){
        // printf("I POOPED"); 
        int returnNum = 0; 
        if(headNode->flag == 1 && headNode->prox == NULL){
            headNode->flag = -1; 
            headNode->key = -1; 
            strcpy(headNode->value,"\0");
            headNode->prox = NULL;
            // return 1;
            returnNum = 1;
            return 1;  
        }
        if(isEmptyLinkedHash(headNode)) return 0; 
        LinkedHash *headPointer = headNode->prox; 

        LinkedHash *topNode = headNode->prox; 
        headNode->prox = topNode->prox; 
        strcpy(headNode->value,topNode->value);

        free(topNode);
        return returnNum;
    }
    void showStack(LinkedHash *headNode){
        LinkedHash *temp = headNode; 
        
        while(temp != NULL){
            printf(" -> %d", temp->value);
            temp = temp->prox; 
        }
        return; 
    }

//END OF MAP STRUCTURE

/** End of the big ones */
void letTheGameBegin(){
    int x = 0, y = 0, points = 0, turns = 0;
    scanf("%d %d %d %d", &x, &y, &points, &turns);
    fflush(stdout);

    PriorityQueue *VpQ = pQInit(1000);
    pQinsert(VpQ, points, x, y); 
    
       
    showInterval(0, VpQ->n, VpQ->pQ); 


    return; 
}

int main(){
    letTheGameBegin(); 
}

