#include <stdio.h>
#include <stdlib.h>
#define LENGTH 10

typedef struct 
{
    int *elemPtr;
    int count;
    int max;
}List;

List initialize(List L);
List insertPos(List L, int data, int position);
List deletePos(List L, int position);
int locate(List L, int data);
List  insertSorted(List L, int data);
void display(List L);
List resize(List L);

int main(){
    List L;

    L = initialize(L);
    L.elemPtr[0] = 11;
    L.elemPtr[1] = 22;
    L.elemPtr[2] = 33;
    L.elemPtr[3] = 44;
    L.elemPtr[4] = 55;
    L.count = 5;

    printf("1. Insert #99 in position 2.\n");
    L = insertPos(L, 99, 2);
    display(L); 

    printf("\n\n");

    printf("2. Delete position 2.\n");
    L = deletePos(L, 2);
    display(L); 

    printf("\n\n");

    printf("3. Locate #33.\n");
    int res = locate(L, 33);
    if(res > 0){
        printf("The #33 is located in this position of the array %d.", res);
    }else{
        printf("The data did not exist.");
    }

    printf("\n\n");

    printf("4. Insert #10 in the array.\n");
    L = insertSorted(L, 10);
    display(L); 

    return 0;
}

List initialize(List L){
    L.elemPtr = (int*)malloc(LENGTH * sizeof(int));
    if(L.elemPtr == NULL){
        printf("Dynamically Allocations Failed.");
    }
    L.max = LENGTH;
    L.count = 0;

    return L;
}

List insertPos(List L, int data, int position){
    if(position > L.count){
        printf("Position should be less than or equal to count.\n");
        return L;
    }else if(L.count >= L.max){
        L = resize(L);
    }

    for(int i = L.count; i >= position; i--){
        L.elemPtr[i] = L.elemPtr[i - 1];
        if(i == position){
            L.elemPtr[i - 1] = data;
        }
    }
    L.count++;

    return L;
}

List resize(List L){
    L.elemPtr = realloc(L.elemPtr, (LENGTH * 2) * sizeof(int));
    L.max = L.max * 2;

    return L;
}

List deletePos(List L, int position){
    if(position > L.count){
        printf("Position should be less than or equal than count.\n");
        return L;
    }

    for(int i = position - 1; i < L.count; i++){
        L.elemPtr[i] = L.elemPtr[i + 1];
    }
    L.count--;

    return L;
}

int locate(List L, int data){
    int i;
    for(i = 0; i < L.count && L.elemPtr[i] != data; i++){}

    return i > L.count - 1 ? -1 : (i + 1);  
}

List  insertSorted(List L, int data){
    if(L.count >= L.max){
        L = resize(L);
    }

    int pos = 0;
    for(int i = 0; i < L.count; i++){
        if(L.elemPtr[i] > data && L.elemPtr[i - 1] < data){
            pos = i;
        }else if(data > L.elemPtr[i]){
            pos = i + 1;
        }
    }

    for(int i = L.count; i >= pos; i--){
        L.elemPtr[i + 1] = L.elemPtr[i];
        if(i == pos){
            L.elemPtr[i] = data;
        }
    }
    L.count++;

    return L;
}

void display(List L){
    printf("Elem: [");
    for(int i = 0; i < L.count - 1; i++){
        printf("%d, ", L.elemPtr[i]);
    }
    printf("%d]", L.elemPtr[L.count - 1]);
}