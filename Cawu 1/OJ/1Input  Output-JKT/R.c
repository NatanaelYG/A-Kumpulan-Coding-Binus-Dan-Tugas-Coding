#include <stdio.h>

int main() {
	char s[11];
	char n[101];
	char c;
	int o;
	
	scanf("%s %[^\n] %c %d", s, n, &c, &o);
	
	printf("Id    : %s\n", s);
	printf("Name  : %s\n", n);
	printf("Class : %c\n", c);
	printf("Num   : %d\n", o);
}
