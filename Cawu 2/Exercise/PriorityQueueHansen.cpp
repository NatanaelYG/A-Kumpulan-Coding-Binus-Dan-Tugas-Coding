/*
    Postfix
    1)	String				Stack
        554*2/+				+/
    2)	String				Stack
        7622^*15+			(+
    3)	String				Stack
        64412*+*3+42^+		+^

    Prefix
    1)	String				Stack
        25^21+25^/ 715-++	)++-(
        ++-157/^52+12^52
    2)	String				Stack
        35^96+35^3*++		++*
        ++*3^53+69^53
    3)	String				Stack
        7103	5**23^+-
        -+^32**53107			
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data{
    char nama[10];
    char stat[5];
    int umur;
    struct data *next;
    struct data *prev;
}*h, *t, *c;

void push(char nama[], int umur, char stat[]){
    c = (struct data *) malloc(sizeof(struct data));
    strcpy(c->nama, nama);
    c->umur = umur;
    strcpy(c->stat, stat);
    c->next = NULL;
    c->prev = NULL;

    if(!h) h = t = c;
    else if(strcmp(c->stat, "High") == 0){
        c->next = h;
        h->prev = c;
        h = c;
    }
    else if(strcmp(c->stat, "Low") == 0){
        t->next = c;
        c->prev = t;
        t = c;
    } else {
        struct data *temp = h;
        while(strcmp(temp->next->stat, "Low") > 0) temp = temp->next;
        c->next = temp->next;
        temp->next->prev = c;
        c->prev = temp;
        temp->next = c;
    }
}

void dequeue() {
    // dequeue = pophead;
    struct data *temp = h;
    h = h->next;
    h->prev = NULL;
    free(temp);
    return;
}

void display(){
    struct data *temp = h;
    if(!h){
        printf("There is no data\n");
        return;
    }
    while(temp != NULL){
        printf("Nama: %s, ", temp->nama);
        printf("Umur: %d, ", temp->umur);
        if(strcmp(temp->stat, "High") == 0) printf("Status: 1\n");
        if(strcmp(temp->stat, "Mid") == 0) printf("Status: 2\n");
        if(strcmp(temp->stat, "Low") == 0) printf("Status: 3\n");
        temp = temp->next;
    }
    return;
}

int main(){    
    push("Rizki", 33, "Low");
    push("Richard", 26, "Low");
    push("Andi", 16, "High");
    push("Nur", 74, "Mid");
    push("Coki", 66, "Low");

    printf("Linked List after entering data:\n");
    display();
    
    dequeue();
    dequeue();
    dequeue();

    printf("Linked List after dequeue:\n");
    display();

    return 0;
}
