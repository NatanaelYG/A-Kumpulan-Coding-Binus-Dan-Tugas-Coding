#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
	char name[51];
	char ticket[51];
	Node* next;
}Node;

int queueNum = 0;
Node* head = NULL;
Node* tail = NULL;

Node* createNode(char name[], char ticket[]){
	Node* newNode = (Node*) malloc(sizeof(Node)); //deklarasi sekaligius inisialisasi pointer yang mengarah ke blok memori
	strcpy(newNode->name, name); //kita gunakan panah karena kita mengakses blok memori tersebut melalui pointer, nunjuk
	strcpy(newNode->ticket, ticket);
	newNode->next = NULL;
	return newNode;
}

void insertNode(Node* newNode){
	if(head == NULL){ //kalau queue kosong
		head = tail = newNode;
		return;
	}
	else{
		if(strcmp(newNode->ticket, "REGULER") == 0){ //kalau yangmau diinsert reguler, langsung taro di paling belakang
			tail->next = newNode;
			tail = newNode;
			return;
		}
		else{ //kalau fast_track
			if(strcmp(head->ticket, "REGULER") == 0){
				newNode->next = head;
				head = newNode;
				return;
			}
			else{
				Node* curr = head;
				while(curr->next != NULL && strcmp(curr->next->ticket, "FAST_TRACK") == 0){
					curr = curr->next;
				}
				newNode->next = curr->next;
				curr->next = newNode;
				return;
			}
		}
	}
}

void registerNew(){
	int amt;
	char name[51];
	char ticket[51];
	printf("Enter the amount of passenger: ");
	scanf("%d", &amt); getchar();
	for(int i = 0; i < amt; i++){
		printf("Enter passenger name: ");
		scanf("%s", name); getchar();
		printf("Enter passenger ticket: ");
		scanf("%s", ticket); getchar();
		insertNode(createNode(name, ticket)); //insertNode(newNode);
		queueNum++;
	}
}

void removeNode(char name[]){
		if(strcmp(head->name, name) == 0 && head == tail){
			free(head);
			head = NULL;
			tail = NULL;
			return;
		}
		else if(strcmp(tail->name, name) == 0){
			free(tail);
            tail = NULL;
			return;
		}
		else{
			Node* curr = searchNode(name);
			
			if(curr == NULL){
				printf("Data not found.\n");
				return;
			}
			curr->prev->next = curr->next;
			curr->next->prev = curr->prev;
			free(curr);
			curr = NULL;
			return;
		}
}

Node *searchNode(char name[])
{
	Node *temp = head;
	while(temp)
	{
		if (strcmp(head->name, name) == 0)
		{
			return temp;
		}
		temp = temp->next;
	}
	return NULL;
}

void remove(){
	if(head == NULL){
		printf("No data exists.\n");
		return;
	}
	int amt;
	char name[51];
	printf("Enter amount of passenger to remove: ");
	scanf("%d", &amt); getchar();
	for(int i = 0; i < amt; i++){
		printf("Enter passenger name: ");
		scanf("%s", name); getchar();
		removeNode(name);
		queueNum--;
	}
}

void call(){
	if(head == NULL){
		printf("No data exists.\n");
		return;
	}
	for(int i = 0; i < 4 && head != NULL; i++){
		printf("%s ", head->name);
		removeNode(head->name);
		queueNum--;
	}
	printf("got into the boat.\n");
	printf("%d queues remaining. \n", queueNum);
}

void view(){
	if(head == NULL){
		printf("No data exists.\n");
		return;
	}
	Node* curr = head;
	int i = 0;
	while(curr != NULL){
		printf("%2.02d. %10s - %10s\n", ++i, curr->name, curr->ticket);
		curr = curr->next;
	}
	return;
}

int main(){
	int opt;
	do{
		printf("Istana Boneka\n");
		printf("=============\n");
		printf("1. Register\n");
		printf("2. Remove\n");
		printf("3. Call\n");
		printf("4. View\n");
		printf("5. Exit\n");
		printf(">> ");
		scanf("%d", &opt); getchar();
		switch(opt){
			case 1:{
				registerNew();
				break;
			}
			case 2:{
				remove();
				break;
			}
			case 3:{
				call();
				break;
			}
			case 4:{
				view();
				break;
			}
		}
	}
	while(opt != 5);
	return 0;
}