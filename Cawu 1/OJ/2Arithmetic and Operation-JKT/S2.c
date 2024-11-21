#include <stdio.h>

int main()
{
	double p, l, t;
	scanf ("%lf %lf %lf", &p, &l, &t);
	
	printf("%.3lf\n", ((p*l)*3)+ ((l*t)*1/2)*2);
}
