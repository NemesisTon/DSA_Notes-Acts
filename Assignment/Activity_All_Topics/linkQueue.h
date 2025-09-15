#ifndef LINKQUEUE_H
#define LINKQUEUE_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

typedef struct QueueL {
    Node *front;
    Node *rear;
} QueueL;

bool linkQisFull(QueueL* q) {
    return false;
}

bool linkQisEmpty(QueueL* q) {
    return q->front == NULL;
}

int linkQfront(QueueL* q) {
    return linkQisEmpty(q) ? -1 : q->front->data;
}

int deQueueL(QueueL* q) {
    int get = -1;
    if (linkQisEmpty(q)) {

    }else{
        get = q->front->data;
        Node *temp = q->front;
        q->front = q->front->next;
        if (q->front == NULL) q->rear = NULL;
        free(temp);
    }
    
    return linkQisEmpty(q) ? -1 : get;
}

void linkQueueL(QueueL* q, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    if (linkQisEmpty(q)) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

void linkQdisplay(QueueL* q) {
    if (linkQisEmpty(q)) {
        printf("The queue is empty.\n\n");
    }else{
        char buffer[256] = "Elem: Front --> ";
        char temp1[20];

        Node *temp = q->front;
        int i = 0;
        while (temp != NULL) {
            if (temp->next != NULL) {
                sprintf(temp1, "%d --> ", temp->data);
            } else {
                sprintf(temp1, "%d --> Rear", temp->data);
            }
            strcat(buffer, temp1);
            temp = temp->next;
            i++;
        }
        printf("%-75s Count: %d\n\n", buffer, i);
    }
}

QueueL* linkQinitialize() {
    QueueL *q = (QueueL *)malloc(sizeof(QueueL));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

#endif