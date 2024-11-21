#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(){
	char names[100][100], 
		 types[100][100],
		 ids[100][100];
	int prices[100], count = 0, menu,i,j,k,l;
	
	do {
			printf("1. Create product\n");
			printf("2. Update product\n");
			printf("3. Delete product\n");
			printf("4. Exit\n");
			printf("> ");
			scanf("%d", &menu);
			
			switch(menu){
				case 1:{
					char name[100], type[100], id[100];
					int price;
					do {
			printf("Product name: ");
			scanf("%s", name);
		} while (strlen(name) == 0);
		do {
			printf("Product type [Food | Beverage | Cosmetic | Others]: ");
			scanf("%s", type);
		} while (strcmp(type, "Food") != 0 && strcmp(type, "Beverage") != 0 && strcmp(type, "Cosmetic") != 0 && strcmp(type, "Others") != 0);
		do {
			printf("Product price: ");
			scanf("%d", &price);
		} while (price <= 0);
		printf("Creat product success!\n\n");
		
		srand(time(NULL));
		
		char temp[100];
		int upper = 0;
		int lower = 0;
		int num = 0;
		int cek;
		
		do {
			for(i = 0;i < 10;i++){
				cek = rand() % 3;
	
				if(cek == 0){
					temp[i] = rand()%26 + 'A';
					upper = 1;
				}else if(cek == 1){
					temp[i] = rand()%26 + 'a';
					lower = 1;
				}else if(cek == 2){
					temp[i] = rand()%10 + '0';
					num = 1;
				}
			}
		} while (upper == 0 || lower == 0 || num == 0);
		
		strcpy(ids[count],temp);
		strcpy(names[count],name);
		strcpy(types[count],type);
		prices[count] = price;
		count++;
				break;
			}
			case 2:{
				int select;
				char name[100],type[100]; 
				int price;
				printf("\nUpdate Menu\n\n");
					printf("\n| No. | ID | Name | Type | Price |\n");
				for(j = 0; j < count;j++){
					printf("%.03d %s %s %s IDR %d\n", j+1, ids[j],names[j], types[j], prices[j]);
				}
				
				do {
					printf("Input product number [1..%d]: ", count);
					scanf("%d", &select);
				} while (select <= 0 && select > count);
				
				do {
					printf("Product name: ");
					scanf("%s", name);
					getchar();
				} while (strlen(name) == 0);
				
				do {
						printf("Product type [Food | Beverage | Cosmetic | Others]: ");
						scanf("%s", type);
						getchar();
				} while (strcmp(type, "Food") != 0 && strcmp(type, "Beverage") != 0 && strcmp(type, "Cosmetic") != 0 && strcmp(type, "Others") != 0);
				do {
						printf("Product price: ");
						scanf("%d", &price);
				} while (price <= 0);
				printf("Update product success!\n\n");
				
				
	
					strcpy(names[select-1],name);
					strcpy(types[select-1],type);
					prices[select-1] = price;
				break;
			}
			case 3:{
				int select;
				printf("\nDelete Menu\n\n");
				
				printf("\n| No. | ID | Name | Type | Price |\n");
				for(j = 0; j < count;j++){
					printf("%.03d %s %s %s IDR %d\n", j+1, ids[j],names[j], types[j], prices[j]);
				}
				
				printf("Input product number [1..%d]: ", count);
				scanf("%d", &select);
				
				for(k = select-1;k < count;k++){
					strcpy(ids[k],ids[k+1]);
					strcpy(names[k],names[k+1]);
					strcpy(types[k],types[k+1]);
					prices[k] = prices[k+1];
				}
				count--;
				
				printf("Delete product success!\n");
				break;
			}
		}
		
		
		
	} while (menu != 4);
	return 0;
}
