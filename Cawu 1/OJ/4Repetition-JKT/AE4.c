#include <stdio.h>

int main(){
	int i,n;
	double r,t;
	
	scanf("%d",&n);
	for (i = 1; i<=n;i++){
		scanf("%lf %lf", &r, &t);
		printf("Case #%d: %.2lf\n",i ,2*3.14*r*(r+t));
	}
	return 0;
}
