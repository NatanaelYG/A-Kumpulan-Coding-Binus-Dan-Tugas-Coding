#include <stdio.h>

int main()
{
	char a, b ,c;
	
	scanf("%c %c %c", &a, &b, &c);
	
	if (a < b && a < c){
		if (b<c)
		{
			printf("1 2 3\n");
		} else
		{
			printf("1 3 2\n");
		}
	}
	if (b<c && b<a){
		if(c<a){
			printf("2 3 1\n");
		} else {
			printf("2 1 3\n");
		}
	}
	if (c<a && c<b){
		if (a<b){
			printf("3 1 2\n");
		} else {
			printf("3 2 1\n");
		}
	}
}
