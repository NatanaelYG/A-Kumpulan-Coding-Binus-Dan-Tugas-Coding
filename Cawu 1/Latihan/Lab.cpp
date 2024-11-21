//#include <stdio.h>
//
//void menusatu();
//void menudua();
//
//int main(){
//	int menu;
//	scanf("%d", &menu);
//		switch (menu){
//			case 1:
//				menusatu();
//				break;
//			case 2: 
//				menudua();
//				break;
//		}
//	
//	return 0;
//}
//
//void menusatu(){
//	printf("Session 8\n");
//	printf("1. Creat\n");
//	printf("2. Read\n");
//	printf(">> ");
//}
//
//void menudua(){
//	printf("Hahahaha\n");
//}

#include <stdio.h>
#include <stdbool.h>

int addition();
bool check();

int main(){
     int a = addition();
     printf("a = %d\n", a);

    if(check()){
        printf("Valid\n");
    } else {
        printf("Not Valid\n");
    }
}

int addition(int a, int b){
    int tes = a + b;

    printf("%d\n", tes);
    return tes;
}

bool check(){
    int a = 10;
    int b = 12;
    bool valid = a > b;
    return valid;
}
