#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int main(){
	char huruf1,huruf2, name[100][100], status[100], names[100][1000];
	int menu, people;
	int i,j,k,l,number;
	people = 0;
	int customer;
	char waiter[100];
	do {
		printf("\nDine In Order Management\n");			
		printf("========================\n");
		printf("Count of customer(s): %d people\n", people);		
		printf("Menu:\n");			
		printf("1. Accept customer\n");			
		printf("2. Show all customers\n");			
		printf("3. Update customer order status\n");			
		printf("4. Exit\n");			
		printf(">> ");
		scanf("%d", &menu);
		
		switch (menu){
			case 1:{
				srand(time(NULL));
				int num1,num2;
				num1 = rand() %26;				
				num2 = rand() %26;				
				huruf1 = 'A'+num1;
				huruf2 = 'A'+num2;
				name[people][0] = huruf1;
				name[people][1] = huruf2;
				name[people][2]='\0';
				strcpy(status, "Ready to order");
				people++;
				break;
			}
			case 2:{
				if(people == 0){
					printf("\nNo customer yet...\n\n");
				} else {
					printf("| No | Name | Status |\n");
					for(i = 0; i < people;i++){
						printf("\n%d %s %s\n",i+1,name[i],status);
					}
					printf("\n");
				}
				break;
			}
			case 3:{
				if (people == 0){
					printf("\nNo customer yet...");
					getchar();
					getchar();
					break;
				} else {
					printf("| No | Name | Status |\n");
					for(i = 0; i < people;i++){
						strcpy(names, name[i]);
						printf("\n%d %s %s\n",i+1,names,status);
					}
					printf("\n");
					
					printf("Select cutomer that you wan to update his/her status: ");
					scanf("%d", &customer); getchar();
					
					do {
						printf("Enter the waiter name that handles the order: ");
						scanf("%[^\n]", &waiter);
					} while (!(strncmp(waiter, "Mr." ,3) || strncmp(waiter, "Ms.", 3)));
					
					do{
						status = "Taking order";
						printf("| No | Name | Status |\n");
						for(i = 0; i < people;i++){
						strcpy(names, name[i]);
						printf("\n%d %s %s\n, PIC: ",i+1,names,status, waiter);
					}
					printf("\n");
					}
					
				}
				break;
			} 
		}			
		
		
	} while (menu != 4);
}
