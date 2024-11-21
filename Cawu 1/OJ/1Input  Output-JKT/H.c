#include <stdio.h>

int main() {
	char s[100];
	
	scanf("%[^\n]", s);
	
	printf("Congrats \"%s\" for joining the CS department at BINUS.\n", s);	
}
