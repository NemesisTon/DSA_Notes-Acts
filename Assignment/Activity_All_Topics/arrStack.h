#ifndef ARRSTACK_H
#define ARRSTACK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 10

typedef struct {
    int arr[MAX];
    int top;
} Stack;

Stack* initArrStack() {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->top = -1;
    return s;    
}

bool isFull(Stack *s) {
    return s->top == (MAX - 1) ? true : false;
}

bool isEmpty(Stack *s) {
    return s->top == - 1 ? true : false;
}

int peek(Stack *s) {
    return (isEmpty(s)) ? -1 : s->arr[s->top];   
}

void pop(Stack *s) {
    if(!isEmpty(s)){
        s->top--;
    }else{
        printf("The array is empty.\n");
    }
}

void push(Stack *s, int value) {
    if(!isFull(s)){
        s->arr[++(s->top)] = value;
    }else{
        printf("The array is full.\n");
    }
}

void pushUnique(Stack *s, int data){
    if(!isFull(s)){
        Stack temp;
        temp.top = -1;
        int flag = 0;

        while (!isEmpty(s)) {
            int val = peek(s);
            if (val == data) {
                flag = 1;
            }
            pop(s);
            push(&temp, val);
        }

        while (!isEmpty(&temp)) {
            int val = peek(&temp);
            pop(&temp);
            push(s, val);
        }

        if (!flag) {
            push(s, data);
        } else {
            printf("Not Unique.\n");
        }
    }else{
        printf("The array is full.\n");
    }
}

void display(Stack *s) {
    if(!isEmpty(s)){
        char buffer[256] = "Elem: [";
        char temp[20];
        
        for(int i = 0; i <= s->top; i++){
            if(i < s->top){
                sprintf(temp, "%d, ", s->arr[i]);
            }else{
                sprintf(temp, "%d]", s->arr[i]);
            }
            strcat(buffer, temp);
        }
        printf("%-50s Count: %d\n\n", buffer, s->top + 1);
    }
}

#endif
