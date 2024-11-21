#include <stdio.h>

int main(){
	double n, t;
	
	scanf("%lf", &t);
	for(int i = 1; i <= 3; i++){
		scanf("%lf", &n);
		printf("%.2lf %.2lf %.2lf\n", (0.8*n), ((1.8*n)+32), (n+273));
	}
}
