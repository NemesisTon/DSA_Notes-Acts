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
    return get >= 0 ? get : get;
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
    if(isEmpty(s)){
        printf("The stack is empty.\n\n");
    }else{
        printf("Elem: [");
        for(int i = 0; i <= s->top; i++){
            if(i < s->top){
                printf("%d, ", s->items[i]);
            }else{
                printf("%d]\n\n", s->items[i]);
            }
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
        printf("--- Warehouse Inventory Management System ---\n");
        printf("1. Push a container\n");
        printf("2. Pop a container\n");
        printf("3. Check if a container exists\n");
        printf("4. Display all stacks\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                int value = 0;
                printf("Enter container ID to push: ");
                scanf("%d", &value);
                if(!isFull(&s[0])){
                    push(&s[0], value);
                    printf("Container %d pushed successfully.\n", value);
                }else if(!isFull(&s[1])){
                    push(&s[1], value);
                    printf("Container %d pushed successfully.\n", value);
                }else{
                    push(&s[2], value);
                    printf("Container %d pushed successfully.\n", value);
                }
                break;
            case 2:
                if(!isFull(&s[0])){
                    int get = pop(&s[0]);
                    printf("Container %d popped successfully\n", get);
                }else if(!isFull(&s[1])){
                    int get = pop(&s[1]);
                    printf("Container %d popped successfully\n", get);
                }else{
                    int get = pop(&s[2]);
                    printf("Container %d popped successfully\n", get);
                }
                break;
            case 3:
                int value1 = 0,  check = 0, getStack = 0;
                printf("Enter container ID to check: ");
                scanf("%d", &value1);
                Stack temp[3];
                for(int i = 0; i < 3; i++){
                    temp[i] = s[i];
                }

                for(int i = 0; i < 3 && check == 0; i++){
                    int k = temp[i].top;
                    for(int j = i, a = 0; a < k + 1; a++){
                        if(value1 == peek(&temp[j])){
                            check = 1;
                            getStack = i;
                        }else{
                            pop(&temp[j]);
                        }
                    }
                }
                if(check == 1){
                    printf("Container %d exist in stack %d\n", value1, getStack + 1);
                }else{
                    printf("Container %d did not exist in any stack.\n", value1);
                }
                break;
            case 4:
                for(int i = 0, a = 1; i < 3; i++, a++){
                    printf("---Stack %d---\n", a);
                    display(&s[i]);
                }
                break;
            case 5:
                flag = 0;
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("The number you input is invalid.\n");
                break;
        }
        printf("\n");
    }
    return 0;
}