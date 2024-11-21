#include <stdio.h>

int main()
{
	double a, b, c, d;
	
	scanf("%lf", &a);
	for (int i = 1; i <= 3; i++){
		scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
		printf("%.2lf\n", (a/1)*2+(b/2)*4+(c/3)*4+(d/4)*2);
	}
}
