#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 26

struct Mhs {
	char nama[255];
	int umur;
	float gpa;
	Mhs *next;
}*head[SIZE], *tail[SIZE];

Mhs* createNode(const char* nama, int umur, float gpa){
	Mhs *node = (Mhs*)malloc(sizeof(Mhs));
	strcpy(node->nama, nama);
	node->umur = umur;
	node->gpa =  gpa;
	node->next = NULL;
	return node;
}

int hash(const char* nama){
	return nama[0] - 'A';
}

void push(const char* nama, int umur, float gpa){
	int key = hash(nama);
	Mhs* node = createNode(nama, umur, gpa);
	if(!head[key]){
		head[key] = tail[key] = node;
	} else {
		tail[key]->next = node;
		tail[key] = node;
	}
}


void search(const char* nama){
	int key = hash(nama);
	if(!head[key]){
		printf("Ga ketemu\n");
		return;
	}
	Mhs* curr = head[key];
	while(curr){
		if(strcmp(curr->nama, nama) == 0){
			printf("Ketemu\n");
			printf("Data ada pada index: %d \nNama: %s, Umur: %d, GPA: %0.2f\n", curr, curr->nama, curr->umur, curr->gpa);
			return;
		}
		curr = curr->next;
	}
//	printf("\nGa ketemu\n");
}

void pop(const char* nama){
	int key = hash(nama);
	if(!head[key]){
	printf("Ga ketemu\n");
		return;
	}
	if(strcmp(head[key]->nama, nama) == 0){
		if(head[key] == tail[key]){
			free(head[key]);
			head[key] = tail[key] = NULL;
		} else {
			Mhs* nextHead = head[key]->next;
			free(head[key]);
			head[key] = nextHead;
		}
	} else if(strcmp(tail[key]->nama, nama) == 0){
		Mhs *curr = head[key];
		while(curr->next != tail[key]){
			curr = curr->next;
		}
		free(tail[key]);
		curr->next = NULL;
		tail[key] = curr;
	} else {
		Mhs *curr = head[key];
		while(curr->next && strcmp(curr->next->nama, nama) != 0){
			curr = curr->next;
		}
		if(curr == tail[key]){
			printf("Ga ketemu\n");
			return;
		}
		Mhs* toDel = curr->next;
		curr->next = toDel->next;
		free(toDel);
	}
	//printf("Ga ketemu\n");
}

void view(){
	for(int i = 0; i < SIZE; i++){
		if(!head[i]){
			printf("%d. NULL\n", i);
			continue;
		}
		Mhs *curr = head[i];
		while(curr){
		printf("%d. Nama: %s, Umur: %d, GPA: %0.2f -> ", i, curr->nama, curr->umur, curr->gpa);
			curr = curr->next;
		}
		puts("NULL");
		}
	}

int main(){
	
	 push("Andi", 10, 3.5);
	 push("Zoro", 12, 3.75);
	 push("Shibal", 12, 3.75);
	 push("Juliet", 12, 3.75);
	 push("Jamal", 12, 3.9);
	 push("Jimat", 12, 3.9);
	 view();
	 search("Andi");
	 search("Zoro");
	 search("Kocak");
	 pop("Andi");
	 pop("Juliet");
	 view();

	return 0;
}