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
    return false;
}

bool isEmpty(Queue* q){
    return q->front == NULL;
}

int front(Queue* q){
    // int get = 0;
    // if(isEmpty(q)){
    //     printf("The queue is empty.\n");
    // }
    // get = q->item[q->front];
    // return isEmpty(q) ? -1 : get;
}

int dequeue(Queue* q){
    // int get = 0;
    // if(isEmpty(q)){
    //     printf("The queue is empty.\n");
    // }else{
    //     get = q->item[q->front];
    //     q->front = (q->front + 1) % MAX;
    // }
    // return isEmpty(q) ? -1 : get;
}

void enqueue(Queue* q, int value){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    if(isEmpty(q)){
        q->front = newNode;
        newNode->next = NULL;
    }else{
        Node *temp = q->front;
        for(; temp->next != NULL; temp = temp->next){}
        temp->next = newNode;
        newNode->next = NULL;
        q->rear = temp;
    }
}

void display(Queue* q){
    if (isEmpty(q)) {
        printf("The queue is empty.\n\n");
    }else{
        char buffer[256] = "Elem: Front --> ";
        char temp1[20];

        Node *temp = q->front;
        int i = 0;
        for(; temp != NULL; temp = temp->next, i++){
            if(temp->next != NULL){
                sprintf(temp1, "%d --> ", temp->data);
            }else{
                sprintf(temp1, "%d --> Rear", temp->data);
            }
            strcat(buffer, temp1);
        }
        printf("%-75s Count: %d\n\n", buffer, i);
    }
}

Queue* initialize(){
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
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