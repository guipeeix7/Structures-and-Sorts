//Diga-me a frequência


#include <stdio.h>
#include <stdlib.h>
typedef int Item;

#define key(A) (A) //key(A) (A.chave)
#define less(A,B) (key(A) < key(B))
#define lesseq(A,B) (key(A) <= key(B))
#define exch(A,B) {Item t = A; A = B; B = t;}
#define cmpexch(A,B) {if(less(A,B)) exch(A,B);}  

typedef struct Ascii{
    int code;
    int reps;
}Ascii; 

void merge(Ascii *V, int l, int middle, int r)
{
    Ascii *VAux = (Ascii *)malloc((r-l+1) * sizeof(Ascii)); 
    int k = 0, i = l, j = middle+1;
    while ((i <= middle) && (j <= r)){
        if (lesseq(V[i].reps ,V[j].reps)){
            VAux[k++] = V[i++];
        }
        else{
            VAux[k++] = V[j++];
        }
    }
    while (i <= middle){
        VAux[k++] = V[i++];
    }
    while (j<=r){
        VAux[k++] = V[j++];        
    }
    k = 0;
    while((l + k) <= r){
        V[l + k] = VAux[k];
        k++;
    }
    free(VAux); //Free nao funciona em arrays de uma posição
}

void mergeSort(Ascii *V, int l, int r)
{
    if (l >= r)
        return;
    int middle = (r + l) / 2;
    mergeSort(V, l, middle);
    mergeSort(V, middle + 1, r);
    merge(V, l, middle, r);
}


int showVector(Ascii *vector, int lenght){
    
    for(int i = 0 ; i < lenght ; i++){
        if(vector[i].reps != 0){
            printf("%d" , vector[i].code);
            printf(" %d " , vector[i].reps);
            vector[i].reps = 0;
            vector[i].code = 0;
            printf("\n");
        }
    } 
    return 0;
}

void clearTheArray(Ascii *V, int sizeOfThatArray){
    for(int i = 0 ; i <= sizeOfThatArray ; i++){
        V[i].reps = 0; 
        V[i].code = 0; 

    }
    return; 
}


int B(){
    char V[1001] = {"/0"};
    Ascii *VAscii = (Ascii*) malloc(128*sizeof(Ascii)); 
    clearTheArray(VAscii, 128);


    while(scanf("%s", V) != EOF){
        getchar();
        // printf("%s\n", V);
        for(int i = 0 ; V[i] != '\0' ; i++){
            VAscii[(int) V[i]].reps++; 
            VAscii[(int) (V[i])].code = (int) V[i]; 
        }
        mergeSort(VAscii, 0, 127);
        // for(int i = 0 ; i < 128 ; i++){
        //     printf("%d " , VAscii[i]);
        //     VAscii[i] = 0 ;
        // }


        // for(int i = 0 ; V[i] != '\0' ; i++){
        //     VAscii[(int) V[i]]++; 
        //     // printf("%d ", VAscii[V[i]]);

        // }
        
        printf("\n");
        showVector(VAscii, 128); 
    }

}

int main(){
    B();
}











//Problema:
// Diga-me a frequência
// Dada uma linha de texto, você deve encontrar as frequências de cada um dos caracteres presentes nela. As linhas fornecidas não conterão nenhum dos primeiros 32 ou dos últimos 128 caracteres da tabela ASCII. É claro que não estamos levando em conta o caracter de fim de linha.

// Entrada
// A entrada contém vários casos de teste. Cada caso de teste é composto por uma única linha de texto com até 1000 caracteres.

// Saída
// Imprima o valor ASCII de todos os caracteres presentes e a sua frequência de acordo com o formato abaixo. Uma linha em branco deverá separar 2 conjuntos de saída (deixe uma linha em branco após o último conjunto de testes também). Imprima os caracteres ASCII em ordem ascendente de frequência. Se dois caracteres estiverem presentes com a mesma quantidade de frequência, imprima primeiro o caracter que tem valor ASCII menor. A entrada é terminada por final de arquivo (EOF).

// Exemplos
// Exemplo de entrada
// AAABBC
// 122333
// EDA2rlz
// Saída para o exemplo de entrada
// 67 1
// 66 2
// 65 3

// 49 1
// 50 2
// 51 3

// 50 1
// 65 1
// 68 1
// 69 1
// 108 1
// 114 1
// 122 1