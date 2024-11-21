#include <stdio.h>
#include <stdlib.h>

struct node {
    int valueNode;
    struct node *next;
    struct node *prev;
}*h, *t, *c;

void pushMiddle(int value){
    c= (struct node*) malloc(sizeof(struct node));
    c->valueNode = value;
    c->next = NULL;
    c->prev = NULL;
    if(!h){
        h=t=c;
    } else if(h->valueNode > value){
        c->next = h;
        h->prev = c;
        h = c;
    } else if(t->valueNode < value){
        t->next = c;
        c->prev = t;
        t = c;
    } else {
        struct node *temp;
        temp = h;
        while(value > temp->next->valueNode)
            temp = temp->next;
        c->next = temp->next;
        temp->next->prev = c;
        c->prev = temp;
        temp->next = c;
    }
}


void popHead(){
	if(h == NULL) return;
	struct node *temp = h;
	h = h->next;
	free(temp);
}

void popTail(){
	if (t == NULL) return;
	struct node *temp = h;
	
	while (temp->next->valueNode != t->valueNode){
        temp = temp->next;
        if(temp == NULL)
            break;
    } 
    t = temp;
    struct node *curr;
    curr = temp->next;
    temp->next = NULL;
    free(curr);
}

void pop(int value){
    struct node *temp = h;

    if(!h) return;

    while(temp->valueNode != value){
        temp = temp->next;
        if (temp == NULL) break;
    }
    
    if (temp == NULL) return;

    if (temp == h) {
        h = h->next;
        if (h) h->prev = NULL;
        free(temp);
    } else if (temp == t) {
        t = t->prev;
        if (t) t->next = NULL;
        free(temp);
    } else {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
    }
}

void PrintAllNext(){
    struct node *temp = h;
    while (temp != NULL){
        printf("%d ", temp->valueNode);
        temp = temp->next;
    }
    printf("\n");
}

void PrintAllPrev(){
	struct node *temp = t;
	while(temp != NULL){
		printf("%d ", temp->valueNode);
		temp = temp->prev;
	}
	printf("\n");
}

int main(int argc, const char * argv[]) {
    // insert code here...
    pushMiddle(3);
    pushMiddle(5);
    pushMiddle(9);
    pushMiddle(1);
    PrintAllNext();
    pop(3);
    PrintAllNext();
    
    return 0;
}
