#include <stdio.h>

int main()
{
	double n, m;
	scanf("%d", &n);
	for (int i = 1; i <= 3; i++){
		scanf("%lf %lf", &n, &m);
		printf("%.2lf\n", (n/100)*m);
	}
	return 0;
}
