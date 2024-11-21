#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    char *name;
    char *ticket;
    struct node *next;
    struct node *prev;
} node;

int cout = 0;
node *head = NULL;
node *tail = NULL;

node *createNode(char *name){
    node *newNode = (node*)malloc(sizeof(node));
    newNode->name = strdup(name);
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insert(node* newNode, char *name){
    if(!head){
        head = tail = newNode;
        return; 
    } else{
        if(strcmp(newNode->name, name) > 0){
            tail->name = newNode;
            tail = newNode;
            return;
        } else {
            node* temp = head;
            while(temp->next != NULL && strcmp(temp->next->name, name) == 0){
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
            return;
        }
    }
}

void remove(char *name){
    if(strcmp(head->name, name) == 0 && head == tail){
        free(head);
        tail = NULL;
        head = NULL;
        return;
    } else if (strcmp(tail->name, name) == 0){
        free(tail);
        tail = NULL;
        return;
    } else {
        node* temp = head;
        while(temp != NULL && strcmp(temp->name, name) != 0){
            temp = temp->next;
        } if(temp == NULL) {
            printf("data not found");
            return;
        }
        temp->prev->next = temp->next;
        temp->prev->next = temp->prev;
        free(temp);
        temp = NULL;
        return;
    }
}