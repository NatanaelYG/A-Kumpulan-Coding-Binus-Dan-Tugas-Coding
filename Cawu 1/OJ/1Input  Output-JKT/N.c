#include <stdio.h>

int main(){
	int a1, a2;
	char n1[100], n2[100];
	double h1, h2;
	
	scanf("%s %lf %d %s %lf %d", n1, &h1, &a1, n2, &h2, &a2);
	
	printf("Name 1: %s\n", n1);
	printf("Height 1: %.2lf\n", h1);
	printf("Age 1: %d\n", a1);
	printf("Name 2: %s\n", n2);
	printf("Height 2: %.2lf\n", h2);
	printf("Age 2: %d\n", a2);
}
