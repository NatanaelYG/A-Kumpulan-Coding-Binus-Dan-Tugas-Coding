#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main(){
	srand(time(NULL));
	int menu;
	char name[100],dst[100],type[100],date[100];
	int qty,count = 0,price,i;
	do {
		printf("=================\n");
		printf("|Bluejack Pillow|\n");
		printf("=================\n");
		printf("1. Order Pillow\n");
		printf("2. View Order\n");
		printf("3. Remove Order\n");
		printf("4. Exit\n");
		printf(">> ");
		scanf("%d", &menu); getchar();
		
		switch(menu){
			case 1:{
				price = 0;
				do {
					printf("\nInput Receiver Name [5 - 25 characters]: ");
					scanf("%[^\n]", &name); getchar();
				} while (strlen(name) <= 5 || strlen(name) > 25);
				
				do {
					printf("Input Destination [Can only contain Alphanumeric and Space][Cannot start or end with space]: ");
					scanf("%[^\n]", &dst); getchar();
				} while (strlen(dst) == 0);
				
				do {
					printf("Input Pillow Type [Microfiber|Latex|Feather]: ");
					scanf("%s", &type); getchar();
				} while ((strcmp(type, "Microfiber")) && (strcmp(type, "Latex")) && (strcmp(type, "Feather")));
				
				do {
					printf("Input Quantity[Must be between 1 and 10]: ");
					scanf("%d", &qty);
				} while (qty <= 1 || qty >= 10);
				
				do {
					printf("Input Order Date [Must be a valid date in dd/mm/yyyy format]: ");
					scanf("%s", &date);
				} while (date == 0);
				
				printf("\nThank you for your order...");
				
				printf("\nCongratulations, %d was deducted from your purchase!\n");
				printf("Amount to be paid: %d\n", price);
				printf("Press any key to continue...\n");
				getchar();
				getchar();
				count++;
				break;
			}
			
			case 2:{
				if (order == 0){
					printf("\nOrder is empty...\n");
					printf("Please make an order first!\n");
				} else {
					printf("|No. |Receiver Name |Destination |Pillow Type |Quantity |Order Date |Total Price |\n\n");
					for (i = 0;i < order;i++){
						printf("%d %s %s %s %d %s %d\n\n", i+1, name,dst,type,qty,date,price);
					}	
				}	
				break;
			}
			case 3:{
				
				break;
			}
		} 
	} while(menu != 4);
}
