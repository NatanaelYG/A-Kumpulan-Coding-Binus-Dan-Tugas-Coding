#include <stdio.h>

int main()
{
	double n,m;
	scanf("%lf", &n);
	for (int i = 1; i <= 3; i++){
		scanf("%lf %lf", &n, &m);
		printf("%.2lf\n", n*m/360);
	}
	return 0;
}
