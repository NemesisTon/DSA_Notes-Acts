#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int data;
    struct node *next;
}Node;

typedef struct{
    Node *head;
    int count;
}List;

int retrieve(List list, int index);
int locate(List list, int data);
List empty(List list);
List sortList(List list);
List deleteStart(List list);
List deleteLast(List list);
List deletePos(List list, int index);
List insertSort(List list, int data);
List insertPos(List list, int data, int index);
List insertLast(List list, int data);
List insertFirst(List list, int data);
void display(List list);
List initialize(List list);

int main(){
    List L;

    L = initialize(L);

    printf("Insert First\n");
    L = insertFirst(L, 11);
    L = insertFirst(L, 44);
    L = insertFirst(L, 22);
    L = insertFirst(L, 33);
    display(L);

    printf("Sorted List\n");
    L = sortList(L);
    display(L);

    printf("Insert Last\n");
    L = insertLast(L, 99);
    display(L);

    printf("Insert Position\n");
    L = insertPos(L, 10, 0);
    display(L);

    printf("Insert Sorted\n");
    L = insertSort(L, 150);
    display(L);

    printf("Delete First\n");
    L = deleteStart(L);
    display(L);

    printf("Delete Last\n");
    L = deleteLast(L);
    display(L);

    printf("Delete Position\n");
    L = deletePos(L, 2);
    display(L);

    printf("Retrieve Data\n");
    int res = retrieve(L, 2);
    if(res > 0){
        printf("The data retrieve from that position is %d.\n", res);
        display(L);
    }else{
        display(L);
    }

    printf("Locate Data\n");
    int got = locate(L, 11);
    if(got >= 0){
        printf("The data is located in position %d.\n", got);
        display(L);
    }else{
        printf("The data did not exist in the list.\n");
        display(L);
    }

    L = empty(L);
    return 0;
}

int locate(List list, int data){
    int got = -1;

    Node *trav = list.head;
    for(int i = 0; trav != NULL; trav = trav->next, i++){
        if(trav->data == data){
            got = i;
        }
    }

    return got >= 0 ? got : - 1;
}

int retrieve(List list, int index){
    int got = -1;
    if(index >= list.count){
        printf("The index should be less than or equal to count.\n");
    }else{
        Node *trav = list.head;
        for(int i = 0; i < index + 1; trav = trav->next, i++){
            got = trav->data;
        }
    }
    return got > 0 ? got : - 1;
}

List empty(List list){
    Node *trav = list.head;

    for(; trav != NULL; trav = list.head){
        list.head = trav->next;
        free(trav);
        list.count--;
    }
    list.head = NULL;

    return list;
}

List sortList(List list){
    for(Node *tempI = list.head; tempI->next != NULL; tempI = tempI->next){
        for(Node *tempJ = tempI->next; tempJ != NULL; tempJ = tempJ->next){
            if(tempI->data > tempJ->data){
                int temp = tempI->data;
                tempI->data = tempJ->data;
                tempJ->data = temp;
            }
        }
    }
    return list;
}

List deletePos(List list, int index){
    if(index > list.count){
        printf("The index should be less than or equal to count.\n");
    }else if(index == 0){
        list = deleteStart(list);
    }else if(index == list.count){
        list = deleteLast(list);
    }else{
        Node *trav = list.head, *curr = trav;

        trav = trav->next;
        for(int i = 0; i < index - 1; trav = trav->next, curr = curr->next, i++){}
        Node *prev = curr;
        trav = trav->next;
        free(prev);
        curr->next = trav;

        list.count--;
    }
    return list;
}

List deleteLast(List list){
    Node *trav, *curr;

    for(trav = list.head; trav->next != NULL; trav = trav->next){
        curr = trav;
    }
    trav = curr->next;
    free(trav);
    curr->next = NULL;
    list.count--;

    return list;
}

List deleteStart(List list){
    Node *trav = list.head;
    list.head = trav->next;
    free(trav);
    list.count--;

    return list;
}

List insertSort(List list, int data){
    if(list.head == NULL){
        list = insertFirst(list, data);
    }else{
        Node *trav = list.head, *prev = trav;
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->data = data;

        int pos = 0;
        trav = trav->next;
        for(int i = 0; trav != NULL; prev = prev->next, trav = trav->next, i++){
            if(data < trav->data && prev->data < data){
                pos = i;
            }else if(data > trav->data){
                pos = i + 1;
            }
        }
        
        if(pos == 0){
            list = insertFirst(list, data);
        }else{
            trav = list.head;
            prev = trav;
            trav = trav->next;
            for(int i = 0; i < pos; prev = prev->next, trav = trav->next, i++){}
            newNode->next = trav;
            prev->next = newNode;

            list.count++;
        }
    }
    return list;
}

List insertPos(List list, int data, int index){
    if(index > list.count){
        printf("The index/position should be less than or equal to count.\n");
    }else if(list.head == NULL || index == 0){
        list = insertFirst(list, data);
    }else if(list.count == index){
        list = insertLast(list, data);
    }else{
        Node *newNode = (Node *)malloc(sizeof(Node));
        if(newNode == NULL){printf("Memory Allocation Failed.\n");}
        newNode->data = data;

        Node *trav = list.head;
        for(int i = 0; i < index - 1; i++){
            trav = trav->next;
        }
        Node *prev = trav;
        newNode->next = trav->next;
        prev->next = newNode;

        list.count++;
    }
    
    return list;
}

List insertLast(List list, int data){
    if(list.head == NULL){
        list = insertFirst(list, data);
    }else{
        Node *newNode = (Node *)malloc(sizeof(Node));
        if(newNode == NULL){printf("Memory Allocation Failed.\n");}
        newNode->data = data;

        Node *trav = list.head;
        for(; trav->next != NULL; trav = trav->next){} //WHY DAFAQ IT WILL NOT WORK IF ITS (trav != NULL) but will work if its (trav->next != NULL)
        trav->next = newNode;
        newNode->next = NULL;

        list.count++;
    }

    return list;
}
    
List insertFirst(List list, int data){
    Node *newNode = (Node *)malloc(sizeof(Node));
    if(newNode == NULL){printf("Memory Allocation Failed.\n");}
    newNode->data = data;
    newNode->next = list.head;
    
    list.head = newNode;
    list.count++;

    return list;
}

void display(List list){
    char buffer[256] = "Elem: [";
    char temp[20];

    Node *trav = list.head;
    while(trav != NULL){
        if(trav->next != NULL){
            sprintf(temp, "%d, ", trav->data);
        }else{
            sprintf(temp, "%d]", trav->data);
        }
        strcat(buffer, temp);
        trav = trav->next;
    }
    printf("%-50s Count: %d\n\n", buffer, list.count);
}

List initialize(List list){
    list.head = NULL;
    list.count = 0;

    return list;
}