#include <stdio.h>
#include <stdlib.h>

struct tnode {
	int valueNode;
    int coeff;
	struct tnode *next;
}*h, *t, *c;

void pushMiddle(int value, int cof){
	c = (struct tnode*) malloc(sizeof(struct tnode));
	c->valueNode = value;
    c->coeff = cof;
	c->next = NULL;
	if(!h){
		h=t=c;
	} else if(h->valueNode > value){
		c->next = h;
		h = c;		
	} else if(t->valueNode < value){
		t->next = c;
		t = c;
	} else {
		struct tnode *temp;
		temp = h;
		while(value > temp->next->valueNode)
			temp=temp->next;
		c->next = temp->next;
		temp->next = c;
	}
}

void popMiddle(int value,int cof){
	if (h == NULL) return;
	
	struct tnode *temp = h;
	
	while (temp->valueNode != value){
		temp = temp->next;
		if(temp == NULL)
			break;
	}
	
	if (temp == NULL) return;
	
	if (temp->valueNode == h->valueNode){
		h = h->next;
		free(temp);
	}
	
	else if (temp->valueNode == t->valueNode){
		struct tnode *temp = h;
		while (temp->next->valueNode != t->valueNode) {
			temp = temp->next;
		}
		free(t);
		t = temp;
		t->next = NULL;
	}
	
	else {
		struct tnode *temp = h;
		while (temp->next->valueNode != value){
			temp = temp->next;
		}
		struct tnode *curr;
		curr = temp->next;
		temp->next = curr->next;
		free(curr);
	}
}

void PrintAll(){
	struct tnode *temp = h;
	while (temp != NULL){
		printf("%dx^%d ", temp->valueNode, temp->coeff);
		temp = temp->next;
	}
	printf("\n");
}

int main(int argc, const char * argv[]) {
	
	pushMiddle(6,3);
	pushMiddle(9,2);
	pushMiddle(7,1);
	pushMiddle(1,0);
	PrintAll();
	popMiddle(9,2);
	
	PrintAll();
	return 0;
}
