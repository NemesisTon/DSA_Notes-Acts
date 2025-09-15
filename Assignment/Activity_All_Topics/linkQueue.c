#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef struct node
{
    int data;
    struct node *next;
}Node;

typedef struct Queue{
    Node *front;
    Node *rear;
}Queue;

bool isFull(Queue* q){
    return q->front == (q->rear + 2) % MAX;
}

bool isEmpty(Queue* q){
    return q->front == (q->rear + 1) % MAX;
}

int front(Queue* q){
    int get = 0;
    if(isEmpty(q)){
        printf("The queue is empty.\n");
    }
    get = q->item[q->front];
    return isEmpty(q) ? -1 : get;
}

int dequeue(Queue* q){
    int get = 0;
    if(isEmpty(q)){
        printf("The queue is empty.\n");
    }else{
        get = q->item[q->front];
        q->front = (q->front + 1) % MAX;
    }
    return isEmpty(q) ? -1 : get;
}

void enqueue(Queue* q, int value){
    if(isFull(q)){
        printf("The queue is empty.\n");
    }else{
        q->rear = (q->rear + 1) % MAX;
        q->item[q->rear] = value;
    }
}

void display(Queue* q){
    // if (isEmpty(q)) {
    //     printf("Queue is empty.\n\n");
    // }else{
    //     char buffer[256] = "Elem: [";
    //     char temp[20];

    //     int count;
    //     if (q->rear >= q->front) {
    //         count = q->rear - q->front + 1;
    //     } else {
    //         count = (MAX - q->front) + (q->rear + 1);
    //     }

    //     int i = q->front, j = 0;
    //     while (j < count) {
    //         if (j < count - 1) {
    //             sprintf(temp, "%d, ", q->item[i]);
    //         } else {
    //             sprintf(temp, "%d]", q->item[i]);
    //         }
    //         strcat(buffer, temp);
    //         i = (i + 1) % MAX;
    //         j++;
    //     }

    //     printf("%-50s Count: %d\tFront: %d\tRear: %d\n\n", buffer, count, q->front, q->rear);
    // }
}

Queue* initialize(){
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

int main(){
    Queue *q = initialize();

    // printf("Queue Array\n");
    // enqueue(q, 10);
    // enqueue(q, 20);
    // enqueue(q, 30);
    // enqueue(q, 40);
    // enqueue(q, 50);
    // display(q);

    // printf("Dequeue Array\n");
    // int get = dequeue(q);
    // if(get > 0){
    //     printf("The dequeued number is: %d\n", get);
    // }
    // display(q);

    // printf("Top Queue List\n");
    // int top = front(q);
    // if(top >= 0){
    //     printf("The first in queue is: %d\n", top); 
    //     display(q);
    // }

    printf("Empty Queue List\n");
    int empty = isEmpty(q);
    if(empty == 1){
        printf("Is it empty? Yes.\n\n");    
    }else{
        printf("Is it empty? No.\n\n");
    }

    printf("Full Queue List\n");
    int full = isFull(q);
    if(full == 1){
        printf("Is it full? Yes.\n\n");    
    }else{
        printf("Is it full? No.\n\n");    
    }

    return 0;
}