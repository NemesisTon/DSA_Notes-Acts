#include <stdio.h>
#include "arrStack.h"
#include "arrQueue.h"
#include "linkStack.h"

int main(){
    char data; 
    
    Stack *s = initArrStack(); /*function from Array Stack header file*/
    STACK *L = initLinkStack(); /*function from Linked List Stack header file*/
    Queue *q = arrQinitialize(); /*function from Queue header file*/
    
    printf("-------------------Array Stack-------------------\n");

    printf("Push\n");
    push(s, 10);
    push(s, 20);
    push(s, 30);
    push(s, 40);
    push(s, 50);
    display(s);

    printf("Pop\n");
    pop(s);
    display(s);

    printf("Top element: %d\n", peek(s));

    printf("\n-------------------Link Stack-------------------\n");

    printf("Push Stack List\n");
    linkpush(L, 10);
    linkpush(L, 20);
    linkpush(L, 30);
    linkpush(L, 40);
    linkdisplay(*L);

    printf("Pop Stack List\n");
    linkpop(L);
    linkdisplay(*L);

    printf("Peek Stack List\n");
    int got = linkpeek(L);
    if(got > 0){
        printf("The top most Stack is %d.\n", got); 
        linkdisplay(*L);   
    }

    printf("Empty Stack List\n");
    int emptyArr = linkisEmpty(L);
    if(emptyArr == 1){
        printf("Is it empty? Yes.\n\n");    
    }else{
        printf("Is it empty? No.\n\n");
    }

    printf("Full Stack List\n");
    int fullArr = linkisFull(L);
    if(fullArr == 1){
        printf("Is it full? Yes.\n\n");    
    }else{
        printf("Is it full? No.\n\n");    
    }

    printf("\n-------------------Array Queue-------------------\n");

    printf("Queue Array\n");
    arrQenqueue(q, 10);
    arrQenqueue(q, 20);
    arrQenqueue(q, 30);
    arrQenqueue(q, 40);
    arrQenqueue(q, 50);
    arrQdisplay(q);

    printf("Dequeue Array\n");
    arrQdequeue(q);
    arrQdisplay(q);

    printf("Top Queue List\n");
    int top = arrQfront(q);
    if(top >= 0){
        printf("The first in queue is: %d\n", top); 
        arrQdisplay(q);
    }

    printf("Empty Queue List\n");
    int emptyList = arrQisEmpty(q);
    if(emptyList == 1){
        printf("Is it empty? Yes.\n\n");    
    }else{
        printf("Is it empty? No.\n\n");
    }

    printf("Full Queue List\n");
    int fullList = arrQisFull(q);
    if(fullList == 1){
        printf("Is it full? Yes.\n\n");    
    }else{
        printf("Is it full? No.\n\n");    
    }

    // VirtualHeap VH; CBlist L;


    // /*array and linkedlist*/
    // pushUnique(S,data); // push if unique
    // enqueueUnique(Q,data); // enqueue if unique

    // displayStack(S); /*function from Stack header file*/
    // displayQueue(Q); /*function from Queue header file*/

    // popUnique(S,data); //given a data, pop the entry
    // dequeueUnique(Q,data); //given a data, dequeue the entry

    // displayStack(S); /*function from Stack header file*/
    // displayQueue(Q); /*function from Queue header file*/


    /*cursor-based*/
    // L=initVHeap(VH);

    // CBinitStack(S);
    // CBinitQueue(Q);

    // CBpushUnique(VH,L,data);
    // CBenqueueUnique(VH,L,data);

    // CBpopUnique(VH,L,data);
    // CBdequeueUnique(VH,L,data);

    // CBdisplayStack(S);
    // CBdisplayQueue(Q);

    return 0;
}