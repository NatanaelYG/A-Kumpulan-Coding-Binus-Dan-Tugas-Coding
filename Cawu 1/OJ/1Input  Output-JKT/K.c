#include <stdio.h>

int main(){
	char name[100], a[100];
	int u;
	scanf("%[^\n]", name);
	scanf("%s %d", a, &u);
	
	printf("Name: %s\n", name);
	printf("NIS: %s\n", a);
	printf("Age: %d\n", u);
}
