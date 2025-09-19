#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX 10

typedef struct {
    int items[MAX];
    int count;
} List;

typedef struct {
    List list;
    int front;
    int rear;
} Queue;

Queue* initialize(){
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = 1;
    q->rear = 0;
    q->list.count = 0;

    return q;
}

bool isFull(Queue* q){
    return q->front == (q->rear + 2) % MAX;
}

bool isEmpty(Queue* q){
    return q->front == (q->rear + 1) % MAX;
}

void enqueue(Queue* q, int value){
    if(!isFull(q)){
        q->rear = (q->rear + 1) % MAX;
        q->list.items[q->rear] = value;
        q->list.count++;
    }else{
        printf("The list is full.\n");
    }
}

int dequeue(Queue* q){
    int get = 0;
    if(!isEmpty(q)){
        get = q->list.items[q->front];
        q->front = (q->front + 1) % MAX;
        q->list.count--;
    }else{
        printf("The list is empty.\n");
    }
    return get;
}

void display(Queue* q){
    if(isEmpty(q)){
        printf(" The queue is empty.\n");
    }else{
        int trav, i;
        for(i = q->front, trav = 0; trav < q->list.count; i = ((i + 1) % MAX), trav++) {
            printf("%d ", q->list.items[i]);
        }
        printf("\n");
    }
}

int main(){
    Queue *q[2];
    for(int i = 0; i < 2; i++){
        q[i] = initialize();
    }
    
    int flag = 1, choice = 0, qq = 1;
    while(flag){
        printf("--- Pharmacy Queueing System ---\n");
        printf("1. Enter Regular Queue\n");
        printf("2. Enter Priority Queue\n");
        printf("3. Call Next Customer\n");
        printf("4. Display Queues\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                if(!isFull(q[0])){
                    enqueue(q[0], qq);
                    printf("You have entered Regular queue. Your number is %d.\n", qq++);
                }                
                break;
            case 2:
                if(!isFull(q[1])){  
                    enqueue(q[1], qq);
                    printf("You have entered Priority queue. Your number is %d.\n", qq++);
                }
                break;
            case 3:
                if(!isEmpty(q[1])){
                    printf("Calling next customer from Priority Queue. Customer number: %d\n", dequeue(q[1]));
                }else{
                    printf("Calling next customer from Regular Queue. Customer number: %d\n", dequeue(q[0]));
                }
                break;
            case 4:
                printf("-- Current Queue Status --\n");
                printf("Regular Queue:");
                display(q[0]);
                printf("Priority Queue:");
                display(q[1]);
                break;
            case 5:
                printf("Exiting Queueing System.\n");
                flag = 0;
                break;
            default:
                printf("Invalid input.\n");
                break;
        }
        printf("\n");
    }
    

    return 0;
}