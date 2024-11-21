#include <stdio.h>

int main()
{
	int angka = 500, angka2 = 800;
	int *ptr = &angka;
	
	printf("%d\n", angka);
	printf("%d\n", &angka);
	
	printf("%d\n", ptr);
	printf("%d\n", &ptr);
	printf("%d", *ptr);
	
	*ptr = 450;
	printf("%d\n", angka);
	printf("%d\n", &angka);
	
	printf("%d\n", ptr);
	printf("%d\n", &ptr);
	printf("%d", *ptr);
	
	ptr = &angka2;
	printf("%d\n", angka);
	printf("%d\n", &angka);
	
	printf("%d\n", ptr);
	printf("%d\n", &ptr);
	printf("%d", *ptr);
	return 0;
}


