#include <stdio.h>
#include <string.h>

int main(){
	int menu,i,panjang,cek,num = 1;
	char keyword[100];
	char userid[5][20] = {"christ0208", "jordywa", "haku", "elior", "cleo"};
	char name[5][20] = {"Christopher", "Jordy", "Haku", "Eleanor", "Cleo Deus"};
	char email[5][20] = {"chris@gmail.com", "jordy@gmail.com", "haku@gmail.com", "el@gmail.com", "cleo@gmail.com"};
	
	do {
		printf("Friendster CLI\n");
		printf("==============\n");
		printf("1. Add New Friend\n");
		printf("2. Unfriend\n");
		printf("3. Exit\n");
		printf(">> ");
		scanf("%d", &menu); getchar();
		
		switch (menu){
			case 1:{
				do {
					printf("Enter keyword to search a friend: ");
					scanf("%[^\n]", &keyword);
					cek = strcmp(keyword == userid);
					num++;
					printf("%d | %s | %s | %s |", num,userid[i],name[i],email[i]);
				} while (strlen(keyword)== 0);
				
				break;
			}
		}
	} while (menu != 3);
}
