#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef struct{
    int item[MAX];
    int count;
}List;

typedef struct{
    List list;
    int front;
    int rear;
}Queue;

bool arrQisFull(Queue* q){
    return q->list.count == MAX;
}

bool arrQisEmpty(Queue* q){
    return q->list.count == 0;
}

int arrQfront(Queue* q){
    return !arrQisEmpty(q) ? q->list.item[q->front] : - 1;
}

int arrQdequeue(Queue* q){
    if(!arrQisEmpty(q)){
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

void arrQenqueue(Queue* q, int value){
    if(!arrQisFull(q)){
        if(q->rear == MAX - 1){
            q->rear = (q->rear + 1) % MAX;
            q->list.item[(q->rear)] = value;
        }else if(arrQisEmpty(q)){
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

void arrQdisplay(Queue* q){
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

Queue* arrQinitialize(){
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->list.count = 0;
    q->front = -1;
    q->rear  = -1;
    return q;
}

#endif