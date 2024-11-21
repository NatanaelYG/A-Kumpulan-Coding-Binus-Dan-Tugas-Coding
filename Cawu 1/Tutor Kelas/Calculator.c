#include <stdio.h>

int main(){
	
	while (1){
	printf("======================================\n");
	printf("Selamat Datang Di Program Calculator\n");
	printf("======================================\n\n");
	
	printf("1. Addition\n");	
	printf("2. Subtraction\n");	
	printf("3. Multiplication\n");	
	printf("4. Division\n");
	printf("5. Exit\n");
	printf(">> ");	
	
	int input;
	scanf("%d", &input);
	getchar ();
	
	if (input == 5){
		break;
	}
	
	if (input < 1 || input > 4){
		continue;
	}
	int num1, num2;
	printf("Enter two numbers : ");
	scanf("%d %d", &num1, &num2);
	getchar ();
	
	int result;
	if (input == 1) {
		result = num1 + num2;
	} else if (input == 2) {
		result = num1 - num2;
	} else if (input == 3) {
		result = num1 * num2;
	} else if (input == 4) {
		result = num1 / num2;
	}
	
	printf("Result : %d\n", result);
	
	}
}
