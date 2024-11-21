#include<stdio.h>

int main()
{
	puts("Simple Input\\Output Program");
	puts("===========================");
	puts("Welcome to \"Algorithm and Programming\"!\n");
	
	char name[101];
	int age;
	printf("Enter your name: ");
	scanf("%[^\n]", name );
	getchar();
	printf("Enter your age: ");
	scanf("%d", &age );
	getchar();
	printf("Hi, %s\n", name);
	
	double firstnumber, secondnumber;
	
	printf("Enter first number: ");
	scanf("%lf", &firstnumber);
	printf("Enter second number: ");
	scanf("%lf", &secondnumber);
	getchar();
	printf("Arithmetic Calculation Result:\n");
	printf("%lf + %lf = %.2lf\n", firstnumber, secondnumber, firstnumber + secondnumber);
	printf("%lf - %lf = %.2lf\n", firstnumber, secondnumber, firstnumber - secondnumber);
	printf("%lf * %lf = %.2lf\n", firstnumber, secondnumber, firstnumber * secondnumber);
	printf("%lf / %lf = %.2lf\n", firstnumber, secondnumber, firstnumber / secondnumber);
	
	// cara mengubah double jadi integer
	// int first = (int) firstnumber

	int first,second;
	printf("Number Checking Result:\n");
	printf("\t First Number: ", firstnumber);
	scanf("%d", &first);
	getchar();
	printf("\t Second Number: ", secondnumber);	
	scanf("%d", &second);
	getchar();
	
	if ( first % 2 == 0)
	{
		printf("\t First Number is Odd Number : 0\n");
		printf("\t First Number is Even Number : 1\n");
	} else {
		printf("\t First Number is Odd Number : 1\n");
		printf("\t First Number is Even Number : 0\n");
	}
	if ( second % 2 == 0)
	{
		printf("\t Second Number is Odd Number : 0\n");
		printf("\t Second Number is Even Number : 1\n");
	} else {
		printf("\t Second Number is Odd Number : 1\n");
		printf("\t Second Number is Even Number : 0\n");
	}
	
	return 0;
}
