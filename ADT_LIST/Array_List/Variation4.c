#include <stdio.h>
#include <stdlib.h>

#define LENGTH 10

typedef struct 
{
    int *elemPtr;
    int count;
    int max; 
}List;

void initialize(List *L);
void insertPos(List *L, int data, int position);
void deletePos(List *L, int position);
int locate(List *L, int data);
int retrieve(List *L, int position);
void insertSorted(List *L, int data);
void display(List *L);
void resize(List *L);
void makeNULL(List *L);

int main(){
    List insideList;
    List *L = &insideList;

    initialize(L);
    L->elemPtr[0] = 11;
    L->elemPtr[1] = 22;
    L->elemPtr[2] = 33;
    L->elemPtr[3] = 44;
    L->elemPtr[4] = 55;
    L->count = 5;

    printf("1. Insert #99 in position 2.\n");
    insertPos(L, 99, 2);
    display(L);

    printf("\n\n");

    printf("2. Delete position 2.\n");
    deletePos(L, 2);
    display(L);

    printf("\n\n");

    printf("3. Locate #22.\n");
    int res = locate(L, 22);
    if(res > 0){
        printf("The location of the number is in position %d.\n", res);
        display(L);
    }else{
        printf("The data did not exist.\n");
        display(L);
    }

    printf("\n\n");

    printf("4. Retrieve the number in position 3.");
    int got = retrieve(L, 3);
    if(got > 0){
        printf("\nThe element in position 3 is %d.\n", got);
        display(L);
    }
    
    printf("\n\n");

    printf("5. Insert #40 in sorted order.\n");
    insertSorted(L, 40);
    display(L);

    printf("\n\n");

    makeNULL(L);
    return 0;
}

void initialize(List *L){
    L->elemPtr = (int*)malloc(LENGTH * sizeof(int));
    L->max = LENGTH;
    L->count = 0;
}

void insertPos(List *L, int data, int position){
    if(position > L->count){
        printf("Position should be less than or equal to count.\n");
        // exit(1);
    }else if(L->count == L->max){
        resize(L);
    }

    for(int i = L->count; i >= position - 1; i--){
        L->elemPtr[i] = L->elemPtr[i - 1];
    }
    L->elemPtr[position - 1] = data;
    L->count++;
}

void deletePos(List *L, int position){
    if(position > L->count){
        printf("Position should be less than or equal to count.\n");
        // exit(1);
    }else{
        for(int i = position - 1; i < L->count; i++){
            L->elemPtr[i] = L->elemPtr[i + 1];
        }
        L->count--;
    }    
}

int locate(List *L, int data){
    int i;
    for(i = 0 ; i < L->count && L->elemPtr[i] != data; i++){}
    return i > (L->count - 1) ? -1 : i + 1;
}

int retrieve(List *L, int position){
    int i = 0;
    if(position > L->count){
        printf("\nThe position should be less than or equal to count.\n");
        return -1;
    }else{
        i = L->elemPtr[position - 1];
        return i;
    }
}

void insertSorted(List *L, int data){
    if(L->count >= L->max){
        resize(L);
    }

    int pos = 0;
    for(int i = 0; i < L->count; i++){
        if(L->elemPtr[i] > data && L->elemPtr[i - 1] < data){
            pos = i;
        }else if(data > L->elemPtr[i]){
            pos = i + 1;
        }
    }

    for(int i = L->count; i >= pos; i--){
        L->elemPtr[i] = L->elemPtr[i - 1];
        if(pos == i){
            L->elemPtr[i] = data;
        }
    }
    L->count++;
}

void resize(List *L){
    L->max = L->max * 2;
    L->elemPtr = realloc(L->elemPtr, L->max * sizeof(int));
    if(L->elemPtr == NULL){
        printf("Memory allocation failed during resize.\n");
        exit(1);
    }
}

void display(List *L){
    printf("Elem: [");
    for(int i = 0; i < L->count - 1; i++){
        printf("%d, ", L->elemPtr[i]);
    }
    printf("%d]", L->elemPtr[L->count - 1]);
}

void makeNULL(List *L){
    free(L->elemPtr);
}