#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef struct{
    int item[MAX];
    int front;
    int rear;
}Queue;

bool isFull(Queue* q){
    return q->list.count == MAX;
}

bool isEmpty(Queue* q){
    return q->list.count == 0;
}

int front(Queue* q){
    return !isEmpty(q) ? q->list.item[q->front] : - 1;
}

int dequeue(Queue* q){
    if(!isEmpty(q)){
        if(q->front == MAX - 1){
            q->front = (q->front + 1) % MAX;
        }else{
            q->front++;
        }
        q->list.count--;
    }else{
        printf("The array is empty.\n");
    }
}

void enqueue(Queue* q, int value){
    if(!isFull(q)){
        if(q->rear == MAX - 1){
            q->rear = (q->rear + 1) % MAX;
            q->list.item[(q->rear)] = value;
        }else if(isEmpty(q)){
            q->front = MAX - 1;
            q->rear = 8;
            q->list.item[++(q->rear)] = value;
        }else{
            q->list.item[++(q->rear)] = value;
        }
        q->list.count++;
    }else{
        printf("The queue is empty.\n");
    }
}

void display(Queue* q){
    char buffer[256] = "Elem: [";
    char temp[20];

    int i = q->front, j = 0;
    while(j < q->list.count){
        if(j < q->list.count - 1){
            sprintf(temp, "%d, ", q->list.item[i]);
        }else{
            sprintf(temp, "%d]", q->list.item[i]);
        }
        strcat(buffer, temp);
        j++;
        if(i == 9){
            i = (i + 1) % MAX;
            continue;
        }
        i++;
    }
    printf("%-50s Count: %d\tFront: %d\tRear: %d\n\n", buffer, q->list.count, q->front, q->rear);
}

Queue* initialize(){
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->list.count = 0;
    q->front = -1;
    q->rear  = -1;
    return q;
}

int main(){
    Queue *q = initialize();

    printf("Queue Array\n");
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);
    display(q);

    printf("Dequeue Array\n");
    dequeue(q);
    display(q);

    printf("Top Queue List\n");
    int top = front(q);
    if(top >= 0){
        printf("The first in queue is: %d\n", top); 
        display(q);
    }

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