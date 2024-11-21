#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char name[100];
    int age;
    char nim[100];
    struct node *next;
} Node;

Node *head = NULL, *tail = NULL;

Node *createNode(const char* name, const char* nim,int age){
    Node *newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    strcpy(newNode->nim, nim);
    newNode->age = age;
    newNode->next = NULL;

    return newNode;
}

void pushHead(const char* name, const char* nim,int age){
    Node *newNode = createNode(name, nim, age);
    if(!head){
        head = tail = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
}

void pushTail(const char* name, const char* nim,int age){
    Node *newNode = createNode(name, name, age);

    if(!head){
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

void pushMid(const char* name, const char* nim,int age){
    Node *newNode = createNode(name,nim,age);
    if(!head){
        head = tail = newNode;
    } else if(strcmp(name, head->name) < 0){
        pushHead(name, nim, age);
    } else if(strcmp(name, tail->name) >= 0){
        pushTail(name, nim, age);
    } else {
        Node *curr = head;
        while(curr->next != NULL && strcmp(name, curr->next->name) >= 0){
            curr = curr->next;
        }

        newNode->next = curr->next;
        curr->next = newNode;
    }
}

Node *searching(const char* nim){
    Node *curr = head;
    while(curr != NULL & strcmp(nim, curr->nim) != 0){
        curr = curr->next;
    }
    return curr;
}

void popHead(){
    if(head == NULL){
        puts("Data is empty.");
        return;
    } 

    Node *temp = head;
    head = head->next;
    free(temp);
    temp = NULL;
}

void popTail(){
    if(head == NULL){
        puts("Data is empty.");
        return;
    } 

    Node *curr = head;
    while(curr->next != tail){
        curr = curr->next;
    }
    // Node *temp = tail;
    // free(temp);
    // temp = NULL;
    // tail = curr;
    // tail->next = NULL;

    free(curr->next);
    curr->next = NULL;
    tail = curr;
}

void popMid(const char *nim){
    if(!head){
        printf("Data is empty.\n");
        return;
    } else if(strcmp(nim, head->nim) == 0){
        popHead();
    } else if(strcmp(nim, tail->nim) == 0){
        popTail();
    } else {
        Node *curr = head;
        while(curr->next != NULL && strcmp(nim, curr->nim) != 0){
            curr = curr->next;
        } 
    if(curr->next == NULL){
        puts("Data not found.");
        return;
    }
        Node *temp = curr->next;
        curr->next = temp->next;
        free(temp);
        temp = NULL;
    }
}

void PrintAll(){
    if(head == NULL){
        printf("Data is empty.\n");
        return;
    } 
    Node *curr = head;
    while(curr != NULL){
        printf("Name: %s\n", curr->name);
        printf("Nim: %s\n", curr->nim);
        printf("Age: %d\n", curr->age);
        puts("==================");
        curr = curr->next;
    }
}

int main(){
    pushMid("Niel", "123123", 19);
    pushMid("Jojo", "762537", 20);
    pushMid("Fred", "989898", 20);
    //PrintAll();

    puts("Before");
    PrintAll();
    puts("==================");

    popMid("123123");

    puts("After");
    PrintAll();
    puts("==================");

    // Node *toFind = searching("123123");
    // if(toFind != NULL){
    //     puts("Data found");
    //     printf("Name: %s\n", toFind->name);
    //     printf("Nim: %s\n", toFind->nim);
    //     printf("Age: %d\n", toFind->age);
    //     puts("==================");
    // } else {
    //     printf("Data not found.\n");
    // }

    return 0;
}