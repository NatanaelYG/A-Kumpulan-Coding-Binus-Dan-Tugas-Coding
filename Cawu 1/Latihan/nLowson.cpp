#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

int main(){
	int i,j,k,l;
	int menu;
	//case 1
	char name[100], type[1000];
	int price,panjang,number;
	//case 2
	srand(time(NULL));
	char temp[1000],cek,id[100];
	int prices,numbers;
	char names[100], types[100];
	
	do {
		printf("1. Create product\n");
		printf("2. Update product\n");
		printf("3. Delete product\n");
		printf("4. Exit\n");
		printf("> ");
		scanf("%d", &menu);
		
		switch(menu){
			case 1:{
					do {
						printf("\nlProduct name [not empty]: ");
						scanf("%s", &name); getchar();
					} while (strlen(name) == 0);
					
					do {
						printf("Product type [Food | Beverage | Cosmetic | Others] : ");
						scanf("%s", type); getchar();
					} while (strcmp(type,"Food") != 0 && strcmp(type,"Beverage") != 0 && strcmp(type,"Cosmetic") != 0 && strcmp(type,"Others") != 0);
					
					do {
						printf("Product price [more than 0] : ");
						scanf("%d", &price); getchar();
					} while (price <= 0);
					printf("Create product success!\n\n");	
					number++;
				break;
			}
			
			case 2:{
				do {
					for(i = 0;i <= 10;i++){
						temp[0] = (rand() % ('z' - 'a' + 1)) + 'a';
						temp[1] = (rand() % ('Z' - 'A' + 1)) + 'A';
						temp[2] = (rand() % ('0' - '9' + 1)) + '0';
						cek = rand() % 3;
						id[i] = cek;
					}
				} while (i != 10);
				numbers = number;
				strcpy(names,name);
				strcpy(types,type);
				prices = price;
				
				printf("| No. | ID | Name | Type | Price |\n");
				printf("%d %s %s %s %d",numbers, id[i], names, types, prices);
					
				break;
			}
			
			
			
		}
		
		
		
		
	} while (menu != 4);
	return 0;
}
