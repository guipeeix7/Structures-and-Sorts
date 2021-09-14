#include "header.h"

int main(){
    Item *headNode = init();
    orderedInserction(0,2,headNode);
    orderedInserction(0,1,headNode);
    orderedInserction(10,3, headNode);


    orderedInserction(50,5, headNode);
    orderedInserction(50,4, headNode);

    // printf("%d\n", );
    searchAndDelete(1, headNode);
    searchAndDelete(1, headNode);
    orderedInserction(10,5, headNode);
    // searchAndDelete(2, headNode);
    orderedInserction(10,0, headNode);
    // searchAndDelete(20, headNode);

    // orderedInserction(2,40, headNode);

    showList(headNode);
    printf("==================\n");
    showReveseList(headNode);
}