#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 100

typedef struct Data {
    char name[100];
    char tlp[50];
    char email[101];
    struct Data *next;
}Data;

typedef struct {
    Data *head, *tail;
}Table;
Table *table[SIZE] = {NULL};

Data *createNode(const char *name, const char *tlp, const char *email) {
    Data newNode = (Data)malloc(sizeof(Data));
    strcpy(newNode->name, name);
    strcpy(newNode->tlp, tlp);
    strcpy(newNode->email, email);
    
    newNode->next = newNode->prev = NULL;
    return newNode;
}

void initializeTable() {
    for(int i = 0; i < SIZE; i++) {
        table[i] = (Table*)malloc(sizeof(Table));
        table[i]->head = table[i]->tail = NULL;
    }
    return;
}

void view() {
    for (int i = 0; i < SIZE; i++) {
       	Data *curr = table[i]->head;
        //printf("%d ", i);
        while (curr) {
            printf("%s %s %s\n", curr->name, curr->tlp, curr->email);
            curr = curr->next;
        }
        //printf("\n");
    }
    return;
}

int hash(const char *name) {
    char firstChar = name[0];
    if(firstChar >= 'a' && firstChar <= 'z') {
        return (firstChar - 'a') % SIZE;
    }
    else if (firstChar >= 'A' && firstChar <= 'Z') {
        return (firstChar - 'A') % SIZE;
    }
    else {
        return firstChar % SIZE;
    }
}

void pushTail(int key, Data* newNode) {
    if (table[key]->head == NULL) {
        table[key]->head = table[key]->tail = newNode;
    }
    else {
        newNode->prev = table[key]->tail;
        table[key]->tail->next = newNode;
        table[key]->tail = newNode;
    }
    return;
}

void insert(const char *name, const char *tlp, const char *email) {
    int key = hash(name);
    Data* newNode = createNode(name, tlp, email);
    if (table[key]->head == NULL || strcmp(name, table[key]->head->name) < 0) {
        pushHead(key, newNode);
    }
    else if (strcmp(name, table[key]->tail->name) >= 0) {
        pushTail(key, newNode);
    }
    else {
        pushSort(key, newNode);
    }
}

void popTail(int key) {
    if (table[key]->head == NULL) return;
    else if (table[key]->head == table[key]->tail) {
        free(table[key]->head);
        table[key]->head = table[key]->tail = NULL;
    }
    else {
        struct Data* temp = table[key]->tail;
        table[key]->tail = table[key]->tail->prev;
        free(temp);
        table[key]->tail->next = NULL;
    }
    return;
}



void deleteByName(const char *name) {
    int key = hash(name);
    if (table[key] == NULL) {
        printf("The data you want to delete isn't there\n");
        return;
    }
    else if (strcmp(name, table[key]->head->name) == 0) {
        popHead(key);
    }
    else if (strcmp(name, table[key]->tail->name) == 0) {
        popTail(key);
    }
    else {
        popMid(key, name);
    }
    return;
}

int main() {
    initializeTable();
    insert("Ayam", "08155123045", "ayam@email.com");
    insert("Babi", "08999044793", "hehe@email.com");
    insert("Cici", "087777962153", "sipi@email.com");
    //insert("Ayam", "08155123045", "ayam@email.com");
    
    //deleteByName("Bibi");

    view();
    return 0;
}