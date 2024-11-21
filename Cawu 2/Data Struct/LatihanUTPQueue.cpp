#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct node{
    char name[100];
    int stat;
    struct node *next;
}*h, *t, *c;

void push(const char* name, int stat){
    c = (struct node*)malloc(sizeof(struct node));
    c->stat = stat;
    strcpy(c->name, name);
    c->next = NULL;
    if(!h){
        h=t=c;
    } else if(h->stat > stat){
        c->next = h;
        h = c;
    } else if(t->stat < stat){
        t->next = c;
        t = c;
    } else {
        struct node *temp;
        temp = h;
        while(temp->next && stat > temp->next->stat){
            temp = temp->next;
        } 
        c->next = temp->next;
        temp->next = c;
    }
}

void serveOne(){
    if(h){
        struct node* temp = h;
        printf("Serving %s\n", temp->name);
        h = h->next;
        free(temp);
    } else {
        printf("Queue is empty\n");
    }
}

void serveAll(){
    while (h) {
        serveOne();
    }
}

void dismissQueue() {
    while(h) {
        struct node* temp = h;
        h = h->next;
        free(temp);
    }
    t = NULL;
}

void showAll(){
    struct node* temp = h;
    int i = 1;
    while (temp != NULL) {
        printf("%d. %s\n", i++, temp->name);
        temp = temp->next;
    }
}

int main() {
    int option;
    char name[100];
    char status[100];
    int iStat;

    do {
        printf("============================\n");
        printf("SUNIB Restaurant Reservation\n");
        printf("============================\n");
        printf("\n");
        printf("Waiting Line:\n");
        if (!h)
            printf("Queue is empty\n");
        else
            showAll();
        printf("\n");
        printf("1. Add Customer to Queue\n");
        printf("2. Serve One\n");
        printf("3. Serve All\n");
        printf("4. Dismiss Queue\n");
        printf("0. Exit\n");
        printf("Input Menu Number: ");
        scanf("%d", &option);
        getchar();

        if (option == 1) {
            scanf("%s %s", status, name);
            if (strcmp(status, "VVIP") == 0)
                iStat = 1;
            else if (strcmp(status, "VIP") == 0)
                iStat = 2;
            else if (strcmp(status, "Member") == 0)
                iStat = 3;
            else if (strcmp(status, "Guest") == 0)
                iStat = 4;
            push(name, iStat);
        } else if (option == 2) {
            serveOne();
        } else if (option == 3) {
            serveAll();
        } else if (option == 4) {
            dismissQueue();
            printf("End of the day!\n");
        }
    } while (option != 0);
    return 0;
}