#include <stdio.h>

#define MAX 10

typedef struct 
{
    char elem[MAX];
    int top;
}STACK;

void push(STACK *s, char data){
    if(s->top != MAX){
        s->elem[s->top] = data;
        s->top++;
    }else{
        printf("The array is full.\n");
    }
}

void pop(STACK *s){
    if(s->top != 0){
        s->top--;
    }else{
        printf("The stack is empty.\n");
    }
}

char peek(STACK s){
    if(s.top != 0){
    }else{
        printf("The stack is empty.\n");
    }
    
    return s.elem[s.top - 1];
}

void display(STACK s){
    printf("Stack: ");
    for(int i = 0; i < s.top; i++){
        printf("%c \t", s.elem[i]);
    }
}

void initialize(STACK *s){
    s->top = 0;
}

void isUnique(STACK *s, char data){
    // STACK temp = *s;
    // int exist = 0;
    // if(temp.top != 0){
    //     for(; temp.top > 0; temp.top--){
    //         char a = peek(temp);
    //         if(data == a){
    //             exist = 1;
    //         }
    //     }
        
    // }
    // if(exist == 0){
    //     push(s, data);
    // }

    STACK temp = *s;

    int flag = 0;
    while(temp.top != 0 && flag != 1){
        if(peek(temp) == data){
            flag = 1;
        }
        pop(&temp);
    }
    (flag == 1) ? printf("Match Found") : push(s, data);
}

int main(){
    STACK S;

    initialize(&S);
    push(&S, 'A');
    push(&S, 'C');
    push(&S, 'F');
    isUnique(&S, 'G');
    isUnique(&S, 'F');

    // pop(&S);
    // char a = peek(S); 
    // printf("%c\n", a);

    printf("\n");
    display(S);

    return 0;
}