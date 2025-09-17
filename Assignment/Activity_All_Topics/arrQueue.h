#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H

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

bool arrQisFull(Queue* q){
    return q->front == (q->rear + 2) % MAX;
}

bool arrQisEmpty(Queue* q){
    return q->front == (q->rear + 1) % MAX;
}

int arrQfront(Queue* q){
    int get = 0;
    if(arrQisEmpty(q)){
        printf("The queue is empty.\n");
    }
    get = q->item[q->front];
    return arrQisEmpty(q) ? -1 : get;
}

int arrQdequeue(Queue* q){
    int get = 0;
    if(arrQisEmpty(q)){
        printf("The queue is empty.\n");
    }else{
        get = q->item[q->front];
        q->front = (q->front + 1) % MAX;
    }
    return arrQisEmpty(q) ? -1 : get;
}

void arrQenqueue(Queue* q, int value){
    if(arrQisFull(q)){
        printf("The queue is empty.\n");
    }else{
        q->rear = (q->rear + 1) % MAX;
        q->item[q->rear] = value;
    }
}

void dequeueUnique(Queue *q, int data){
    if (arrQisEmpty(q)) {
        printf("Queue is empty. Cannot dequeue %d.\n", data);
    }else{
        int i = q->front, flag = 0;
        while (i != (q->rear + 1) % MAX) {
            if (q->item[i] == data) {
                flag = 1;
                printf("Not Unique\n");
            }
            i = (i + 1) % MAX;
        }

        if(!flag){
            int removed = q->item[q->front];
            q->front = (q->front + 1) % MAX;
        }
    }    
}

void enqueueUnique(Queue *q, int data){
    if (arrQisFull(q)) {
        printf("Queue is full. Cannot enqueue %d.\n", data);
    }else{
        int i = q->front, flag = 0;
        while (i != (q->rear + 1) % MAX) {
            if (q->item[i] == data) {
                flag = 1;
            }
            i = (i + 1) % MAX;
        }

        if(!flag){
            q->rear = (q->rear + 1) % MAX;
            q->item[q->rear] = data;
        }else{
            printf("Not Unique.\n");
        }

    }
}

void arrQdisplay(Queue* q){
    if (arrQisEmpty(q)) {
        printf("Queue is empty.\n\n");
    }else{
        char buffer[256] = "Elem: [";
        char temp[20];

        int count;
        if (q->rear >= q->front) {
            count = q->rear - q->front + 1;
        } else {
            count = (MAX - q->front) + (q->rear + 1);
        }

        int i = q->front, j = 0;
        while (j < count) {
            if (j < count - 1) {
                sprintf(temp, "%d, ", q->item[i]);
            } else {
                sprintf(temp, "%d]", q->item[i]);
            }
            strcat(buffer, temp);
            i = (i + 1) % MAX;
            j++;
        }

        printf("%-50s Count: %d\tFront: %d\tRear: %d\n\n", buffer, count, q->front, q->rear);
    }
}

Queue* arrQinitialize(){
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = 1;
    q->rear = 0;
    return q;
}

#endif