#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int main(){
	srand(time(NULL));
	int menu,i,j,k,l;
	char name[100], type [10]= {"Food", "Beverage", "Cosmetic", "Others"},temp[100],check;
	int price;
	char id[100];
	do {
		printf("1. Create product\n");
		printf("2. Update product\n");
		printf("3. Delete product\n");
		printf("4. Exit\n");
		printf("> \n");
		scanf("%d", &menu);
		
		switch (menu){
			case 1:{
				printf("Product name: ");
				scanf("%s", &name);
				do {
					printf("Product type [Food | Beverage | Cosmetic | Others] : ");
					scanf("%s", &type);
				} while (type == "Food" || type == "Beverage" || type == "Cosmetic" || type == "Others");
				do {
					printf("Product price: ");
					scanf("%d", price);
				} while (price == 0 && price == 'a');
					printf("Create product success!");
				break;
			}
			case 2:{
				printf("| No. | ID | Name | Type | Price |");
					do {
					for(i = 0;i < 10;i++){
						temp[0] = (rand() % ('z' - 'a' + 1)) + 'a';
						temp[1] = (rand() % ('Z' - 'A' + 1)) + 'A';
						temp[2] = (rand() % ('0' - '9' + 1)) + '0';
						check = rand() % 3;
						id[i] = temp[check];
						printf("%c", id[i]);
					}
				} while (id[i] == 10);
				
				
				
				
				break;
			}
			}
			
	} while (menu != 4);
}
