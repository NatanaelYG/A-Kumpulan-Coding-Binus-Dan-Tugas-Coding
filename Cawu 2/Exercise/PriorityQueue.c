#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int umur;
    char nama[100];
    char status[10];
    struct node *next;
    struct node *prev;
}*h,*t,*c;

void pushMiddle(char nama[], int umur,char status[]){
    c = (struct node*) malloc(sizeof(struct node));
    strcpy(c->nama, nama);
    strcpy(c->status, status);
    c->umur = umur;
    c->next = NULL;
    c->prev = NULL;

    if(!h){
        h=t=c;
    }
    else if (strcmp(c->status, "High") == 0){
        c->next = h;
        h->prev = c;
        h = c;
    }
    else if (strcmp(c->status, "Low") == 0){
        t->next = c;
        c->prev = t;
        t=c;
    } else{
        struct node *temp = h;
        while(strcmp(temp->next->status, "Low") > 0)
            temp=temp->next;
        c->next = temp->next;
        temp->next->prev = c;
        c->prev = temp;
        temp->next = c;
    }
}

void dequeue(){
    // dequeue = pophead
    struct node *temp = h;
    h = h->next;
    free(temp);
    return;
}

void PrintallNext(){
    struct node *temp = h;
    if(!h){
        printf("There is no data\n");
        return;
    }

    while (temp!=NULL){
        printf("Nama : %s, Umur : %d, ", temp->nama,temp->umur);
        if(strcmp(temp->status, "High") == 0) printf("Status : 1\n");
        if(strcmp(temp->status, "Mid") == 0) printf("Status : 2\n");
        if(strcmp(temp->status, "Low") == 0) printf("Status : 3\n");
        temp=temp->next;
    }
    return;
}

int main() {
    pushMiddle("Rizki", 33, "Low");
    pushMiddle("Richard", 26, "Low");
    pushMiddle("Andi", 16, "High");
    pushMiddle("Nur", 74, "Mid");
    pushMiddle("Coki", 66, "Low");

    printf("Linked List After Entering Data\n\n");
    PrintallNext();

    dequeue();
    dequeue();
    dequeue();
    
    printf("\nLinked List after dequeue\n\n");
    PrintallNext();

    return 0;
}