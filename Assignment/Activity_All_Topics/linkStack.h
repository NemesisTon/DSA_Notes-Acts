#ifndef LINKSTACK_H
#define LINKSTACK_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int data;
    struct node *next;
}Node;

typedef struct STACK{
    Node *top;
}STACK;

bool linkisFull(STACK *s){
    return false;
}

bool linkisEmpty(STACK *s){
    return s->top == NULL;
}

int linkpeek(STACK *s){
    int found = - 1;
    if(!linkisEmpty(s)){
        found = s->top->data;
    }else{
        printf("The list is empty.\n\n");
    }

    return found;
}

void linkpop(STACK *s){
    if(!linkisEmpty(s)){
        s->top = s->top->next;
    }else{
        printf("The list is empty.\n");
    }
}

void linkpush(STACK *s, int data){
    if(!linkisFull(s)){
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->data = data;
        newNode->next = s->top;
        s->top = newNode;
    }else{
        printf("The STACK is empty.\n");
    }
}

void linkdisplay(STACK s){
    char buffer[256] = "Elem: [Top Most --> ";
    char temp[20];
    
    Node *trav = s.top;
    int i = 0;
    while(trav != NULL){
        if(trav->next != NULL){
            sprintf(temp, "%d --> ", trav->data);
        }else{
            sprintf(temp, "%d --> NULL]", trav->data);
        }
        strcat(buffer, temp);
        trav = trav->next;
        i++;
    }
    printf("%-75s Count: %d\n\n", buffer, i);
}

STACK* initLinkStack(){
    STACK *s = (STACK *)malloc(sizeof(STACK));
    s->top = NULL;
    return s;
}

#endif