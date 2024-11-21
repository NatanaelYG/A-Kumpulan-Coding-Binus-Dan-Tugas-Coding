#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char *name;
    char *ticket;
    struct node *next;
    struct node *prev;
}*h, *t, *c;

void pushMid(char *name, char *ticket){
    c = (struct node*)malloc(sizeof(struct node));
    c->name = strdup(name);
    c->ticket = strdup(ticket);
    c->next = c->prev = NULL;
    if(!h){
        h=t=c;
    } else if (strcmp(h->name, name) > 0){
        c->next = h;
        h->prev = c;
        h = c;
    } else if (strcmp(h->name, name) < 0){
        t->name = c;
        c->prev = t;
        t = c;
    } else {
        struct node *temp;
        temp = h;
        while(name > temp->next->name){
            temp = temp->next;
        }
        c->next = temp->next;
        temp->next->prev = c;
        c->prev = temp;
        temp->next = c;
    }
}