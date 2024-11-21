#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//List Ticket yang digunakan
char TicketList[2][10] = {"FAST_TRACK", "REGULER"};

//struct berisi nama dan ticket;
typedef struct user{
	char name[10];
	int ticket;
	struct user *next;
}user;

user *h = NULL, *t = NULL;

//membuat node baru 
user *createNode(char name[], int ticket){
    user *newNode = (user*)malloc(sizeof(user));
	newNode->ticket = ticket;
	strcpy(newNode->name, name);
	newNode->next = NULL;
	return newNode;
}

// memasukan data node 
void enqueue(char name[], int ticket){
	user *c = createNode(name, ticket);
	if(!h){
//		puts("INSERT CASE 1");
		h = t = c;
	} else if(h->ticket > ticket){
		c->next = h;
		h = c;
	} else{
		user *temp = h;
		while(temp != t && temp->next->ticket <= ticket){
			temp = temp->next;
		}
		if(temp == t){
			t->next = c;
			t = c;
		} else {
			c->next = temp->next;
			temp->next = c;
		}
	}
}

//menampilkan list yang terdapat nama dan tiket yang dimiliki
void displayQueue(){
	user *curr = h;
	int i = 1;
    printf("No   Name           Ticket\n");
	while(curr){
		printf("%d %-10s %-30s\n", i++, curr->name, curr->ticket);
		curr = curr->next;
	}
}

//mengubah ticket yang tadinya dari angkan menjadi FAST_TRACK dan REGULER
int convertStatus(char tickets[]){
	for(int i = 0; i < 2; i++){
		if(strcmp(tickets, TicketList[i]) == 0){
			return i;//Found
		}
	}
	return -1;//invalid
}

// menu untuk menambah user dengan mengimput jumlah yang ingin register lalu mengisi nama dan ticket yang dipilih
void addCustomer(){
	char name[10], tickets[10];
	int ticket;
    int totalTicket;
    int fastTicket = 0;
    int regularTicket = 0;
	do{
		printf("REGISTER ");
        scanf("%d", &totalTicket);
        for(int i = 0; i < totalTicket; i++){
            scanf("%s %s", name, tickets);
            getchar();
            if(strcmp(tickets, "FAST_TRACK") == 0){
                fastTicket++;
            } else if(strcmp(tickets, "REGULER") == 0){
                regularTicket++;
            }
		    ticket = convertStatus(tickets);
        }
		if(strlen(name) == 0) puts("Name must not empty");
		if(ticket == -1) puts("Invalid Ticket!");
	}while(strlen(name) == 0 || ticket == -1);
	enqueue(name, ticket);
}

//memanggil semua yang memiliki (1) FAST_TRACK dan (2) Untuk memnaggil Ticket Reguler
void call(){
    while(h){
        user *c = h;
        int totalTicket = 0;
        int fastTicket = 0;
        int regulerTicket = 0;
        int calling = 1;
        if(calling == 1){
            for(int i = 0; i < fastTicket;i++){
                printf("%s ", c->name);
                calling++;
            }
            printf("got into the boat.\n");
            printf("%d queues remaining.", totalTicket-fastTicket);
        } else if(calling == 2){
            for(int i = 0; i < regulerTicket;i++){
                printf("%s ", c->name);
            }
            printf("got into the boat.\n");
            printf("%d queues remaining.", totalTicket-regulerTicket);
        }
        if(h->next == NULL){
            h = NULL;
        } else {
            h = c->next;
        }
        free(c);
    }
}

//Menghapus user dengan mengisi name user
void dismiss(){
	user *c;
	while(h){
		c = h;
		h = c->next;
		free(c);
	}
	h = NULL;
	t = NULL;
}

// Tampilan main menu
void showMenu(int *menu){
	puts("===================");
	puts("   Ticket Track");
	puts("===================");
    displayQueue();
	
	puts("");
	puts("1. Register");
	puts("2. Remove");
	puts("3. Call");
	puts("0. Exit");
	printf("Input Menu Number: ");
	scanf("%d", &*menu); getchar();
}

//menu utama
int main(){
	int menu;
	do{
		showMenu(&menu);
		if(menu == 1){
			addCustomer();
		} else if(menu == 2){
			if(h){
				displayQueue();		
			} else {
				puts("\nList Empty!!!\n");
			}
		} else if(menu == 3){
			if(h){
				call();	
			} else {
				puts("\nList Empty!!!\n");
			}
		}
	}while(menu != 0);
	return 0;
}