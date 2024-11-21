#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

void menusatu();
void menudua();
void menutiga();

	int menu;
	char name[100];
	char type[100], id[100];
	char names[100][100], types[100][100], ids[100][100];
	int price = 0, count = 0 , prices[100];
	int i, j, k, l;
	int select;

int main(){
	do {
		printf("\nLowson\n");
		if(count == 0){
			printf("\nNo product...\n\n");
		} else {
			printf("\n| No. | ID | Name | Type | Price |\n");
			for(j = 0; j < count;j++){
			printf("%.03d %s %s %s IDR %d\n", j+1, ids[j],names[j], types[j], prices[j]);
			}
		}
		printf("1. Create product\n");
		printf("2. Update product\n");
		printf("3. Delete product\n");
		printf("4. Exit\n");
		printf("> ");
		scanf("%d", &menu);
		
		switch(menu){
			case 1:
				menusatu();
				break;
			case 2:
				menudua();
				break;
			case 3:
				menutiga();
				break;
		}
	} while (menu != 4);
}

void menusatu(){
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
}

void menudua(){
		printf("\nUpdate Menu\n\n");
	
		printf("\n| No. | ID | Name | Type | Price |\n");
		for(j = 0; j < count;j++){
		printf("%.03d %s %s %s IDR %d\n", j+1, ids[j],names[j], types[j], prices[j]);
	}
	
	do {
		printf("Input product number [1..%d]: ",count);
		scanf("%d", &select);
	} while (select <= 0 && select > count);
	
	do {
		printf("Product name: ");
		scanf("%s", name);
	} while (strlen(name) == 0);
	do {
		printf("Product type [Food | Beverage | Cosmetic | Others]: ");
		scanf("%s", type);
	} while (strcmp(type, "Food") != 0 && strcmp(type, "Beverage") == 0 && strcmp(type, "Cosmetic") == 0 && strcmp(type, "Others") == 0);
	do {
		printf("Product price: ");
		scanf("%d", &price);
	} while (price <= 0);
	printf("Update product success!\n\n");
	
	strcpy(names[select-1],name);
	strcpy(types[select-1],type);
	prices[select-1] = price;
}

void menutiga(){
	printf("\nDelete Menu\n\n");
	
		printf("\n| No. | ID | Name | Type | Price |\n");
		for(j = 0; j < count;j++){
		printf("%.03d %s %s %s IDR %d\n", j+1, ids[j],names[j], types[j], prices[j]);
		}
		
		do {
		printf("Input product number [1..%d]: ",count);
		scanf("%d", &select);
		} while (select <= 0 && select > count);
		
		for(k=select-1;k < count;k++)\
		strcpy(ids[k],ids[k+1]);
		strcpy(names[k],names[k+1]);
		strcpy(types[k],types[k+1]);
		prices[k] = prices[k+1];
		}
		count--;
}
