#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char contacts[100][256];
int contactslenght = 0;

int binarysearch(int left, int right, char *search){
	if (left > right) return -1;
	
	int mid = left + (right - left) / 2;
	if (strcmp(contacts[mid],search) == 0) return mid;
	
	else if (strcmp(contacts[mid],search) > 0) {
		return binarysearch(left,mid - 1,search);
	} else {
		return binarysearch(mid + 1,right,search);
	}
}

void binary(){
	char search[256];
	printf("========================================\n");
	printf("Enter the contact name to search: ");
	scanf("%[^\n]", search); getchar();
	printf("========================================\n");
	
	int foundidx = binarysearch(0, contactslenght - 1,search);
	
	if(foundidx == -1){
		printf("Not found\n");
	} else {
		printf("Found at index %d\n", foundidx);
	}
	printf("========================================\n\n");
}

int part(char arr[][256], int left, int right){
	int pivot = right;
	int last = left;
	
	for(int i = left; i < pivot; i++){
		if (strcmp(arr[i], arr[pivot]) < 0){
			char temp[256];
			strcpy(temp, arr[i]);
			strcpy(arr[i], arr[last]);
			strcpy(arr[last], temp);
			
			last++;
		}
	}
	char temp[256];
	strcpy(temp, arr[pivot]);
	strcpy(arr[pivot], arr[last]);
	strcpy(arr[last], temp);
	
	return last;
}

void qs(char arr[][256], int left, int right){
	if(left >= right) return;
	
	int pivot = part(arr,left,right);
	
	qs(arr,left,pivot-1);
	qs(arr,pivot+1,right); 
}

int linearsearch(char *search){
	for(int i = 0;i < contactslenght;i++){
		if(strcmp(contacts[i],search) == 0){
			return i;
		}
	}
	
	return -1;
}

void menu1();
void menu2();
void menu3();
void menu4();
void menu5();
void mainmenu();
void hapuslayar();

int main(){
	
    mainmenu();
    return 0;
}

void hapuslayar(){
	int i;
	for(i = 1;i <= 50;i++){
		printf("\n");
	}
}

void mainmenu(){
    int menu = 0;
    hapuslayar();
   
    do{
        printf("Phonebook Menu:\n");
        printf("1. Add Contact\n");
        printf("2. Search Contact (Linear)\n");
        printf("3. Search Contact (Binary)\n");
        printf("4. Search Contact (Interpolation)\n");
        printf("5. Display Contacts\n");
        printf("6. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &menu); getchar();

        switch(menu){
            case 1:
            	menu1();
				hapuslayar();
                break;
            case 2:
            	hapuslayar();
            	menu2();
                break;
            case 3:
            	hapuslayar();
            	menu3;
            	qs(contacts, 0, contactslenght - 1);
            	binary();
                break;
            case 4:
            	hapuslayar();
                break;
            case 5:
            	hapuslayar();
            	menu5();
                break;
        }
    } while(menu != 6);
}

void menu1(){
	char name[256];
	
	printf("Enter the contact name : ");
	scanf("%[^\n]", name); getchar();
	
	strcpy(contacts[contactslenght],name);
	contactslenght++;
}

void menu2(){
	char search[256];
	printf("========================================\n");
	printf("Enter the contact name to search: ");
	scanf("%[^\n]", search); getchar();
	printf("========================================\n");
	int foundindex = linearsearch(search);
	
	if(foundindex == -1){
		printf("Not found\n");
	} else {
		printf("Found at index %d\n", foundindex);
	}
	printf("========================================\n\n");
}

void menu5(){
	printf("==============\n");
	printf("Daftar Contact\n");
	printf("========================================\n");
	for(int i = 0; i < contactslenght; i++){
		printf("%d. %s\n", i+1,contacts[i]);
	}
	printf("========================================\n\n");
}
