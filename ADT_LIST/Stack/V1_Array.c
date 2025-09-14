#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef struct{
    int items[MAX];
    int top;
}Stack;

bool isFull(Stack *s);
bool isEmpty(Stack *s);
int peek(Stack *s);
void pop(Stack *s);
void push(Stack *s, int value);
void display(Stack *s);
Stack* initialize();

int main(){
    Stack *s = initialize();
    
    printf("Insert/Push in Stack Array\n");
    push(s, 10);
    push(s, 20);
    push(s, 30);
    push(s, 40);
    display(s);

    printf("Delete in Stack Array\n");
    pop(s);
    display(s);

    printf("Peek in Stack Array\n");
    int got = peek(s);
    if(got >= 0){
        printf("The data at the top in the stack array is %d.\n", got);
        display(s);
    }else{
        display(s);
    }
    
    printf("Empty Stack List\n");
    int empty = isEmpty(s);
    if(empty == 1){
        printf("Is it empty? Yes.\n\n");    
    }else{
        printf("Is it empty? No.\n\n");
    }

    printf("Full Stack List\n");
    int full = isFull(s);
    if(full == 1){
        printf("Is it full? Yes.\n\n");    
    }else{
        printf("Is it full? No.\n\n");    
    }

    return 0;
}

Stack* initialize() {
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
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        return -1;
    }
    return s->items[s->top];
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
        s->items[++(s->top)] = value;
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
                sprintf(temp, "%d, ", s->items[i]);
            }else{
                sprintf(temp, "%d]", s->items[i]);
            }
            strcat(buffer, temp);
        }
        printf("%-50s Count: %d\n\n", buffer, s->top + 1);
    }
}