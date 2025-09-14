#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct 
{
    int elem[MAX];
    int count;
}Etype, *Eptr;

void initialize(Eptr L);
void insertPos(Eptr L, int data, int position);
void deletePos(Eptr L, int position);
int locate(Eptr L, int data);
int retrieve(Eptr L, int position);
void insertSorted(Eptr L, int data);
void display(Eptr L);
void makeNULL(Eptr L);

int main(){
    Eptr L = (Eptr)malloc(sizeof(Etype));
    if(L == NULL){
        printf("Memory allocation failed.");
        return 1;
    }
    
    initialize(L);
    L->elem[0] = 11;
    L->elem[1] = 22;
    L->elem[2] = 33;
    L->elem[3] = 44;
    L->elem[4] = 55;
    L->count = 5;

    printf("1. Insert #25 in position 3.\n");
    insertPos(L, 25, 3);
    display(L);

    printf("\n\n");

    printf("2. Delete position 3.\n");
    deletePos(L, 3);
    display(L);

    printf("\n\n");

    printf("3. Locate #33.\n");
    int res = locate(L, 33);
    if(res > 0){
        printf("The #33 is found in the array and its located in position %d.\n", res);
        display(L);
    }else{
        printf("The value did not exist in the array.\n");
        display(L);
    }

    printf("\n\n");

    printf("4. Retrieve the number in position 1.\n");
    int get = retrieve(L, 1);
    if(get > 0){
        printf("In the position 1 the value is %d.\n", get);
        display(L);
    }

    printf("\n\n");

    printf("5. Insert #25 in the sorted order.\n");
    insertSorted(L, 88);
    display(L);

    printf("\n\n");

    printf("6. Freeing the memory allocated list.\n");
    makeNULL(L);

    return 0;
}

void initialize(Eptr L){
    L->count = 0;
}

void insertPos(Eptr L, int data, int position){
    if(position > L->count){
        printf("The position is invalid since its greater than count.\n");
    }else if (L->count > MAX){
        printf("The array is full.\n");
    }

    for(int i = L->count; i >= position - 1; i--){
        L->elem[i] = L->elem[i - 1];
        if(i == position - 1){
            L->elem[i] = data;
        }
    }
    L->count++;
}

void deletePos(Eptr L, int position){
    if(position > L->count){
        printf("The position is invalid since its greater than count.\n");
    }

    for(int i = position; i < L->count; i++){
        L->elem[i - 1] = L->elem[i];
    }
    L->count--;
}

int locate(Eptr L, int data){
    int found = 0;
    for(found = 0; found < L->count && L->elem[found] != data; found++){}

    return found + 1 > L->count ? -1 : (found + 1);
}

int retrieve(Eptr L, int position){
    if(position > L->count){
        printf("The position should be less than or equal to count.");
        return -1;
    }
    
    int i = position - 1, get = 0;
    get = L->elem[i];

    return get;   
}

void insertSorted(Eptr L, int data){
    int pos = 0;
    for(int i = 0; i < L->count; i++){
        if(L->elem[i] > data && L->elem[i - 1] < data){
            pos = i;
        }else if(data > L->elem[i]){
            pos = i + 1;
        }
    }

    for(int i = L->count; i >= pos; i--){
        L->elem[i] = L->elem[i - 1];
        if(pos == i){
            L->elem[i] = data;
        }
    }
    L->count++;
}

void makeNULL(Eptr L){
    free(L);
}

void display(Eptr L){
    printf("Elem: [");
    for(int i = 0; i < L->count; i++){
        if(i + 1 < L->count){
            printf("%d, ", L->elem[i]);
        }else{
            printf("%d]", L->elem[i]);
        }
    }
}