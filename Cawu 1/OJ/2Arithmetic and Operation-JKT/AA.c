#include <stdio.h>

int main() {
	double t,u,a;
	scanf("%lf %lf %lf", &t, &u, &a);
	double result = (((t*20/100)+(u*30/100)+(a*50/100)));
	printf("%.2lf\n", result);
	return 0;
}