#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define enum for courses
typedef enum {
    BSIT,
    BSCE,
    BSEE,
    BSME
} Course;

// Student info only
typedef struct {
    int id;
    char name[50];
    float grade;
    Course course;
    int yearLevel;   // 1 = 1st year, 2 = 2nd year, etc.
} StudType;

// Node of linked list
typedef struct node {
    StudType stud;
    struct node *next;
} Node;

// List structure
typedef struct {
    Node *head;
    int count;
} List;

// Initialize the list
void initList(List *L) {
    L->head = NULL;
    L->count = 0;
}

// Insert student at position
void insertStudent(List *L, StudType newStud, int pos) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->stud = newStud;
    newNode->next = NULL;

    if (L->head == NULL || pos == 0) { // insert at first
        newNode->next = L->head;
        L->head = newNode;
    } else if (pos == -1 || pos >= L->count) { // insert at last
        Node *temp = L->head;
        while (temp->next != NULL) temp = temp->next;
        temp->next = newNode;
    } else { // insert in middle
        Node *temp = L->head;
        for (int i = 0; i < pos - 1 && temp->next != NULL; i++) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    L->count++;
}

// Delete student by ID
void deleteStudent(List *L, int id) {
    if (L->head == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node *temp = L->head, *prev = NULL;
    while (temp != NULL && temp->stud.id != id) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Student with ID %d not found.\n", id);
        return;
    }
    if (prev == NULL) { // deleting head
        L->head = temp->next;
    } else {
        prev->next = temp->next;
    }
    free(temp);
    L->count--;
    printf("Student with ID %d deleted.\n", id);
}

// Sort by year level (ascending)
void sortStudents(List *L) {
    if (L->head == NULL || L->head->next == NULL) return;
    for (Node *i = L->head; i->next != NULL; i = i->next) {
        for (Node *j = i->next; j != NULL; j = j->next) {
            if (i->stud.yearLevel > j->stud.yearLevel) {
                StudType temp = i->stud;
                i->stud = j->stud;
                j->stud = temp;
            }
        }
    }
}

// Search by ID
Node* searchStudent(List *L, int id) {
    Node *temp = L->head;
    while (temp != NULL) {
        if (temp->stud.id == id) return temp;
        temp = temp->next;
    }
    return NULL;
}

// Display all students
void displayStudents(List L) {
    Node *temp = L.head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }
    while (temp != NULL) {
        printf("ID: %d, Name: %s, Grade: %.2f, Course: %s, Year: %d\n",
               temp->stud.id, temp->stud.name, temp->stud.grade,
               courseToString(temp->stud.course), temp->stud.yearLevel);
        temp = temp->next;
    }
}

// Convert enum to string
const char* courseToString(Course c) {
    switch (c) {
        case BSIT: return "BSIT";
        case BSCE: return "BSCE";
        case BSEE: return "BSEE";
        case BSME: return "BSME";
        default: return "Unknown";
    }
}


int main() {
    List L;
    initList(&L); // initialize list

    int choice, pos, id, courseInput;
    StudType tempStud;

    do {
        printf("\n=== Student Linked List Menu ===\n");
        printf("1. Insert Student\n");
        printf("2. Delete Student\n");
        printf("3. Sort Students (by Year Level)\n");
        printf("4. Search Student\n");
        printf("5. Display Students\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter ID: ");
                scanf("%d", &tempStud.id);
                printf("Enter Name: ");
                scanf(" %[^\n]", tempStud.name);
                printf("Enter Grade: ");
                scanf("%f", &tempStud.grade);
                printf("Enter Course (0=BSIT, 1=BSCE, 2=BSEE, 3=BSME): ");
                scanf("%d", &courseInput);
                tempStud.course = (Course) courseInput;
                printf("Enter Year Level (1-4): ");
                scanf("%d", &tempStud.yearLevel);
                printf("Enter Position (0=first, -1=last, n=middle): ");
                scanf("%d", &pos);
                insertStudent(&L, tempStud, pos);
                break;

            case 2:
                printf("Enter ID to delete: ");
                scanf("%d", &id);
                deleteStudent(&L, id);
                break;

            case 3:
                sortStudents(&L);
                printf("List sorted by Year Level.\n");
                break;

            case 4:
                printf("Enter ID to search: ");
                scanf("%d", &id);
                {
                    Node *found = searchStudent(&L, id);
                    if (found != NULL)
                        printf("Found -> ID: %d, Name: %s, Grade: %.2f, Course: %s, Year: %d\n", 
                               found->stud.id, found->stud.name, 
                               found->stud.grade, courseToString(found->stud.course),
                               found->stud.yearLevel);
                    else
                        printf("Student not found.\n");
                }
                break;

            case 5:
                printf("\n=== List of Students ===\n");
                displayStudents(L);
                break;

            case 0:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 0);

    return 0;
}