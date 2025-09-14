#include <stdio.h>
#include <stdlib.h>
#define size 30

typedef struct 
{
    char Lname[16];
    char Fname[24];
    char Mi;
}Nametype;

typedef struct 
{
    Nametype name;
    unsigned int ID;
    char Course[8];
    int YrLvl;
}Studtype, *StudPtr;

typedef struct {
    Studtype StudArray[size];
    int count;
} StudList, *ArrListPtr;

typedef struct node
{
    Studtype data;
    struct node *next;
}Node, *NodePtr;

typedef struct 
{
    NodePtr head;
}List, *ListPtr;

void initList(List *L) {
    L->head = NULL;
}

void insertEnd(List *L, Studtype s) {
    NodePtr newNode = (NodePtr) malloc(sizeof(Node));
    newNode->data = s;
    newNode->next = NULL;

    if (L->head == NULL) {
        L->head = newNode;
    } else {
        NodePtr temp = L->head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void deleteId(List *L, unsigned int id) {
    NodePtr temp = L->head, prev = NULL;

    while (temp != NULL && temp->data.ID != id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Student with ID %u not found.\n", id);
        return;
    }else{
        if (prev == NULL) {
            L->head = temp->next;
        } else {
            prev->next = temp->next;
        }

        free(temp);
        printf("Deleted student with ID %u\n", id);
    }
}

void display(List L) {
    NodePtr temp = L.head;
    printf("List of Students:\n");
    while (temp != NULL) {
        printf("Name: %s %c. %s\n",
               temp->data.name.Fname,
               temp->data.name.Mi,
               temp->data.name.Lname);
        printf("ID: %u\n", temp->data.ID);
        printf("Course: %s\n", temp->data.Course);
        printf("Year Level: %d\n\n", temp->data.YrLvl);
        temp = temp->next;
        printf("------------------------------\n");
    }
}

int main(){
    Studtype students[] = {
        {{"Flores", "Christian", 'A'}, 1111, "IT", 2},
        {{"Magdadaro", "Veny", 'C'}, 2222, "CS", 3},
        {{"Tan", "Kevin", 'Z'}, 3333, "IT", 1},
        {{"Durango", "Perez", 'D'}, 4444, "IS", 4},
        {{"Capoy", "Nicezel", 'P'}, 5555, "CS", 2},
    };

    List L;
    initList(&L);

    for (int i = 0; i < 5; i++) {
        insertEnd(&L, students[i]);
    }

    display(L);

    deleteId(&L, 3333);

    printf("------------------------NEW LIST!------------------------\n");
    display(L);
    
    return 0;
}