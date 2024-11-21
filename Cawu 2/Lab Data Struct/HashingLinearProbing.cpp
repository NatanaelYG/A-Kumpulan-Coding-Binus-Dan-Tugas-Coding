#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 26

struct Mhs {
    char name[255];
    int umur;
    float gpa;
} *head[SIZE];

Mhs* createNode(char name[], int umur, float gpa){
    Mhs *node = (Mhs*)malloc(sizeof(Mhs));
    strcpy(node->name, strdup(name));
    node->umur = umur;
    node->gpa = gpa;

    return node;
};

int hash(char nama[]){
    return nama[0] - 'A';
}

void push(char name[], int umur, float gpa){
    int key = hash(name);
    for(int i = 0; i < SIZE;i++){
        if(!head[key]){
            head[key] = createNode(name, umur, gpa);
            return;
        }
        key = (key+1) % SIZE;
    }
    printf("Table Full\n");
}   

void view(){
    for(int i = 0;i < SIZE;i++){
        if(head[i]){
        printf("%d. %s", i ,  head[i]->name);
        } else {
            printf("%d. NULL", i);
        }
        puts("");
    }
}

void search(char name[]){
    int key = hash(name);

    for(int i = 0; i < SIZE;i++){
        if(head[key] && strcmp(head[key]->name, name) == 0){
            printf("Data Found\n");
            return;
        }
        key = (key+1) % SIZE;
    }
    printf("Data Not Found\n");
}

void pop(char name[]){
    int key = hash(name);

    for(int i = 0; i < SIZE;i++){
        if(head[key] && strcmp(head[key]->name, name) == 0){
            free(head[key]);
            head[key] = NULL;
            return;
        }
        key = (key+1) % SIZE;
    }
    printf("Data Not Found\n");
}

int main(){
    push("Andi", 20, 3.5);
    push("Julieta", 31, 4);
    push("Fikri", 20, 3.3);
    view();
    search("Julieta");
    pop("Fikri");

    return 0;
}