#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 26

struct Data {
    char name[100];
    char tlp[50];
    char email[101];
    Data* next;
    Data* prev;
};

typedef struct {
    Data *head, *tail;
}Table;
Table *table[SIZE] = {NULL};

Data *createNode(const char *name, const char *tlp, const char *email) {
    Data *newNode = (Data*)malloc(sizeof(Data));
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
            printf("%s - %s - %s\n", curr->name, curr->tlp, curr->email);
            curr = curr->next;
        }
        //printf("\n");
    }
    return;
}

int hash(const char *name) {
    int firstChar = name[0];
    int square = firstChar * firstChar / 2;
    int middleDigits = (square/100) % 100; // dua digit
    return middleDigits % SIZE;
    /*
    if(firstChar >= 'a' && firstChar <= 'z') {
        return (firstChar - 'a') % SIZE;
    }
    else if (firstChar >= 'A' && firstChar <= 'Z') {
        return (firstChar - 'A') % SIZE;
    }*/
    // 12345/100 123 % 100 = 23
    // 12345678 -> 123456 - > 56
    
    //12345
    //3
    
    
}

void pushHead(int key, Data* newNode) {
    if (table[key]->head == NULL) {
        table[key]->head = table[key]->tail = newNode;
    }
    else {
        newNode->next = table[key]->head;
        table[key]->head->prev = newNode;
        table[key]->head = newNode;
    }
    return;
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

void pushSort(int key, Data* newNode) {
    Data* curr = table[key]->head;
    while (curr != NULL && strcmp(newNode->name, curr->next->name) >= 0) {
        curr = curr->next;
    }
    newNode->next = curr->next;
    newNode->prev = curr;
    curr->next->prev = newNode;
    curr->next = newNode;
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

void popHead(int key) {
    if (table[key]->head == NULL) return;
    else if (table[key]->head == table[key]->tail) {
        free(table[key]->head);
        table[key]->head = table[key]->tail = NULL;
    }
    else {
        Data* temp = table[key]->head;
        table[key]->head = table[key]->head->next;
        free(temp);
        table[key]->head->prev = NULL;
    }
    return;
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

void popMid(int key, const char *name) {
    Data* curr = table[key]->head;
    while (curr != NULL && strcmp(name, curr->name) != 0) {
        curr = curr->next;
    }
    if (curr == NULL) {
        printf("The data you want to delete isn't there\n");
        return;
    }
    else {
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        free(curr);
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

Data* search(const char *name) {
    int key = hash(name);
    Data* current = table[key]->head;

    while (current != NULL) {
        if (strcmp(name, current->name) == 0) {
        	printf("%s : Data found!\n\n", name);
            return current; // Found the data
            current = current->next;
        }
    }
    printf("Data not found!\n");
    return NULL; // Data not found

    
}


int main() {
    initializeTable();
    insert("Ayam", "08155123045", "ayam@email.com");
    insert("Babi", "08999044793", "hehe@email.com");
    insert("Abe", "087766543521", "hehe@email.com");
    insert("Cici", "087777962153", "sipi@email.com");
    insert("Aku", "08999088987", "hoahoe@email.com");
    
    deleteByName("Babi");
    search("putri");
    search("Cici");

    view();
    return 0;
}
