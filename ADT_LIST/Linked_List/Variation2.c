#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}Node;

typedef struct{
    Node *head;
    int count;
}List;

List* initialize();
void empty(List *list);
void insertFirst(List *list, int data);
void insertLast(List *list, int data);
void insertPos(List *list, int data, int index);
void insertSort(List *list, int data);
void sortList(List *list);
void deleteStart(List *list);
void deleteLast(List *list);
void deletePos(List *list, int index);
int retrieve(List *list, int index);
int locate(List *list, int data);
void display(List *list);

int main(){
    List *L;

    L = initialize();

    printf("Insert First\n");
    insertFirst(L, 22);
    insertFirst(L, 33);
    insertFirst(L, 11);
    insertFirst(L, 44);
    sortList(L);
    display(L);

    printf("Insert Last\n");
    insertLast(L, 99);
    display(L);

    printf("Insert Position\n");
    insertPos(L, 10, 1);
    display(L);

    printf("Insert Sorted\n");
    insertSort(L, 5);
    display(L);

    printf("Delete First\n");
    deleteStart(L);
    display(L);

    printf("Delete Last\n");
    deleteLast(L);
    display(L);

    printf("Delete Position\n");
    deletePos(L, 2);
    display(L);

    printf("Retrieve Data\n");
    int res = retrieve(L, 0);
    if(res > 0){
        printf("The data retrieve from that position is %d.\n", res);
        display(L);
    }else{
        display(L);
    }

    printf("Locate Data\n");
    int got = locate(L, 33);
    if(got > 0){
        printf("The data is located in position %d.\n", got);
        display(L);
    }else{
        printf("The data did not exist in the list.\n");
        display(L);
    }

    empty(L);
    return 0;
}

int locate(List *list, int data){
    int got = 0;
    
    Node *trav = list->head;
    for(int i = 0; trav != NULL; trav = trav->next, i++){
        if(trav->data == data){
            got = i;
        }
    }
    
    return got >= 0 ? got : -1;
}

int retrieve(List *list, int index){
    int res = 0;
    if(index >= list->count){
        printf("The index should be less than to count.\n");
    }else{
        Node *trav = list->head;
        for(int i = 0; i < index; i++){
            trav = trav->next;
        }
        res = trav->data;
    }
    return res > 0 ? res : -1;
}

void deletePos(List *list, int index){
    if(index > list->count){
        printf("The index should be less than or equal to count.\n");
    }else if(index == 0){
        deleteStart(list);
    }else if(index == list->count){
        deleteLast(list);
    }else{
        Node *trav, *curr, * prev;
        
        trav = list->head;
        prev = trav;
        for(int i = 0; i < index; i++){
            trav = trav->next;
           if(i < index - 1){
               prev = trav;
           }
       }
       curr = trav->next;
       free(trav);
       prev->next = curr;
       list->count--;
    }
}

void deleteLast(List *list){
    Node *trav, *curr;

    for(trav = list->head; trav->next != NULL; trav = trav->next){
        curr = trav;
    }
    trav = curr->next;
    free(trav);
    curr->next = NULL;

    list->count--;
}

void deleteStart(List *list){
    Node *trav;

    trav = list->head;
    list->head = trav->next;
    free(trav);
    list->count--;
}

void empty(List *list){
    Node *trav, *nextNode;
    for(trav = list->head; trav != NULL;){
        nextNode = trav->next;
        free(trav);
        list->head = nextNode;
        trav = nextNode;
    }
    list->head = NULL;
    list->count = 0;
}

void sortList(List *list){
    if(list->head == NULL) printf("The list is empty");

    for(Node *tempI = list->head; tempI->next != NULL; tempI = tempI->next){
        for(Node *tempJ = tempI->next; tempJ != NULL; tempJ = tempJ->next){
            if(tempI->data > tempJ->data){
                int temp = tempI->data;
                tempI->data = tempJ->data;
                tempJ->data = temp;
            }
        }
    }
}

void insertSort(List *list, int data){
    if(list->head->data > data){
        insertFirst(list, data);
    }else{
        Node *trav = list->head, *prev;

        Node *newNode = (Node *)malloc(sizeof(Node));
        if(newNode == NULL)printf("Memory allocation failed.\n");
        newNode->data = data;

        int pos = 0;
        prev = trav;
        trav = trav->next;
        for(int i = 0; trav != NULL; trav = trav->next, prev = prev->next, i++){
            if(data < trav->data && data > prev->data){
                pos = i;
            }else if(data > trav->data){
                pos = i + 1;
            }
        }

        trav = list->head;
        prev = trav;
        trav = trav->next;
        for(int i = 0; i < pos; trav = trav->next, prev = prev->next, i++){}
        prev->next = newNode;
        newNode->next = trav;
        list->count++;
    }
}

void insertPos(List *list, int data, int index){
    if(index > list->count){
        printf("Invalid index it should be less than or equal to count.\n");
    }else if(list->head == NULL || index == 0){
        insertFirst(list, data);
    }else if(list->count == index){
        insertLast(list, data);
    }else{
        Node *trav, *prev;

        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->data = data;
        
        trav = list->head;
        for(int i = 0; i < index - 1; i++){
            trav = trav->next;
        }
        prev = trav->next;
        trav->next = newNode;
        newNode->next = prev;
        list->count++;
    }
    
}

void insertLast(List *list, int data){
    Node *trav;

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if(list->head == NULL){
        list->head = newNode;    
    }else{
        for(trav = list->head; trav->next != NULL; trav = trav->next){}
        trav->next = newNode;
    }
    list->count++;
}
    
void insertFirst(List *list, int data){
    Node *newNode = (Node *)malloc(sizeof(Node));
    if(newNode == NULL)printf("Memory allocation failed.\n");
    
    newNode->data = data;
    newNode->next = list->head;

    list->head = newNode;
    list->count++;
}

void display(List *list){
    printf("Linked List Elem: [");
    Node *trav;
    if(list->count == 1){
        printf("%d]\n\n", list->head->data);
    }else{
        for(trav = list->head; trav->next != NULL; trav = trav->next){
            printf("%d, ", trav->data);
            if(trav->next->next == NULL){
                printf("%d]\n\n", trav->next->data);
            }
        }    
    }
}

List* initialize(){
    List *L = (List *)malloc(sizeof(List));
    if(L == NULL){
        printf("Memory allocation failed.");
    }
    L->head = NULL;
    L->count = 0;
}