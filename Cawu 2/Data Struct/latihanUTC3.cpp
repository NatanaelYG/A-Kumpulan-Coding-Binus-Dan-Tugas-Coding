#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    char *name;
    int umur;
    struct node *next, *prev;
} node;

int count = 0;
node *head = NULL;
node *tail = NULL;

node *createNode(char *name, int umur){
    node* newNode = (node*)malloc(sizeof(node));

    newNode->name = strdup(name);
    newNode->umur = umur;
    newNode->next = newNode->prev = NULL;
    return newNode;
}

node *insert(node *curr){
    if(!head){
        head = tail = curr;
    } else if (curr->umur < head->umur){
        curr->next = head;
        head->prev = curr;
        head = curr;
    } else if (curr->umur >= tail->umur){
        tail->next = curr;
        curr->prev = tail;
        tail = curr;
    } else {
        node *temp = head;
        while (temp->next != NULL && curr->umur >= temp->next->umur){
            temp = temp->next;
        }
        curr->prev = temp;
        curr->next = temp->next;
        temp->next = curr;
        curr->next->prev = curr;
    }
}

void rem(int umur){
    if(!head){
        return;
    } else if(umur == head->umur){
        node *temp = head;
        head = head->next;
        free(temp);
    } else if (umur == tail->umur){
        tail = tail->prev;
        free(tail->next);
        tail->next = NULL;
    } else {
        node *temp = head;
        while(temp->next != NULL && umur != temp->next->umur){
            temp = temp->next;
        } 
        if(temp->next == NULL){
            return;
        } else {
            node *rem = temp->next;
            temp->next = rem->next;
            rem->next->prev = temp;
            free(rem);
        }
    }
}

void input(){
    char* name = (char*)malloc(sizeof(50));
    int umur;
    
    printf("Masukkan Nama: ");
    scanf("%s", name); getchar();

    printf("Masukkan Umur: ");
    scanf("%d", &umur); getchar();

    insert(createNode(name, umur));
    count++;
}

void remove(){
    int umur;

    printf("Input umur to remove: ");
    scanf("%d", &umur); getchar();

    rem(umur);
    count--;
}

void viewAll(){
    if(head == NULL){
        printf("No Data..\n");
    }
    node *curr = head;
    while(curr){
        printf("Nama : %s\nUmur : %d\n\n", curr->name, curr->umur);
        curr = curr->next;
    }
    return;
}

int main(){
    int opt;

    do {
        printf("1. Insert Data\n");
        printf("2. Remove Data\n");
        printf("3. View Data\n");
        printf("4. Exit\n");
        printf(">> ");
        scanf("%d", &opt);

        switch (opt){
            case 1:
                input();
                break;
            case 2:
                remove();
                break;
            case 3:
                viewAll();
                break;
        }
    } while (opt != 4);
}