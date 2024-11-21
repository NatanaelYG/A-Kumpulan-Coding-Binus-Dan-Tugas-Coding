#include <stdio.h>

int main(){
	int t = 3,m,n,d;
	int i,j;
	
	scanf("%lld", &t);
	for(i = 0;i < t;i++){
		scanf("%d %d", &m, &n);
		for(j = 0;j <= n;j++){
			d = m % 2;
			m = m / 2;
		}
		printf("%d\n", d);
	}
	
}
