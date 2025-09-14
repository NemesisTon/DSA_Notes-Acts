#include <stdio.h>

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

typedef struct 
{
    Studtype StudArray[size];
    int count;
}StudList, *ListPtr;

void deleteId(ListPtr List, int id){
    int got = 0;
    for(int i = 0; i < List->count; i++){
        if(List->StudArray[i].ID == id){
            got = i;
        }
    }
    
    if(got > 0){
        for(int i = got; i < List->count; i++){
            List->StudArray[i] = List->StudArray[i + 1]; 
        }
        List->count--;
        printf("ID: %d is successfully deleted.\n\n", id);
    }else{
        printf("ID: %d is not found in the list.\n\n", id);
    }
    
}

void display(StudList List){
    printf("List of Students:\n");
    for(int i = 0; i < List.count; i++){
        printf("Name: %s %c. %s\n", 
            List.StudArray[i].name.Fname, 
            List.StudArray[i].name.Mi, 
            List.StudArray[i].name.Lname);
        printf("ID: %d\n", List.StudArray[i].ID);
        printf("Course: %s\n", List.StudArray[i].Course);
        printf("Year Level: %d\n\n", List.StudArray[i].YrLvl);
        printf("------------------------------\n");
    }
}

int main(){
    StudList List = {
        {
            {{"Flores", "Christian", 'A'}, 1111, "IT", 2},
            {{"Magdadaro", "Veny", 'C'}, 2222, "CS", 3},
            {{"Tan", "Kevin", 'Z'}, 3333, "IT", 1},
            {{"Durango", "Perez", 'D'}, 4444, "IS", 4},
            {{"Capoy", "Nicezel", 'P'}, 5555, "CS", 2},
        },
        5
    };
    display(List);

    int same = List.count;
    deleteId(&List, 3333);
    if(List.count != same){
        printf("------------------------NEW LIST!------------------------\n");
        display(List);
    }else{
        printf("------------------------LIST!------------------------\n");
        display(List);
    }
    
    return 0;
}