#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 5

typedef struct {
    int items[MAX];
    int top;
} Stack;

void initialize(Stack *s){
    s->top = -1;
}

bool isFull(Stack *s){
    return s->top == MAX - 1;
}

bool isEmpty(Stack *s){
    return s->top == - 1;
}

void push(Stack *s, int value){
    if(!isFull(s)){
        s->items[++s->top] = value;
    }else{
        printf("The stack is full.\n");
    }
}

int pop(Stack *s){
    int get = 0;
    if(!isEmpty(s)){
        get = s->items[s->top--];
    }
    return get >= 0 ? get : -1;
}

int peek(Stack *s){
    int get = 0;
    if(!isEmpty(s)){
        get = s->items[s->top];
    }
    return get >= 0 ? get : -1;
}

int top(Stack *s){
    int get = 0;
    if(!isEmpty(s)){
        get = s->top;
    }
    return get >= 0 ? get : -1;
}

void display(Stack* s){
    if(!isEmpty(s)){
        printf("The stack is empty.\n\n");
    }
    printf("Elem: [");
    for(int i = 0; i < s->top; i++){
        if(i < s->top - 1){
            printf("%d, ", s->items[i]);
        }else{
            printf("%d]", s->items[i]);
        }
    }
}

int main(){
    Stack s[3];
    for(int i = 0; i < 3; i++){
        initialize(&s[i]);
    }

    int choice, flag = 1;
    while (flag) {
        printf("\n--- Warehouse Inventory Management System ---\n");
        printf("1. Push a container\n");
        printf("2. Pop a container\n");
        printf("3. Check if a container exists\n");
        printf("4. Display all stacks\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Push operation selected.\n");
                break;
            case 2:
                printf("Pop operation selected.\n");
                break;
            case 3:
                printf("Check operation selected.\n");
                break;
            case 4:
                printf("Display operation selected.\n");
                break;
            case 5:
                flag = 0;
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("The number you input is invalid.\n");
                break;
        }
    }
    return 0;
}