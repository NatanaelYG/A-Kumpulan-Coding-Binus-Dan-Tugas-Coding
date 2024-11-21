#include <stdio.h>

int main()
{
	int t,n,m;
	int i,j,even,odd;
	
	scanf("%d", &t);
	for(i = 1;i <= t;i++){
		scanf("%d", &n);
			odd = 0;
			even = 0;
		for(j = 1;j <= n;j++){
			scanf("%d", &m);
			if(m % 2 == 0){
				even++;
			} else {
				odd++;
			}
		}
			printf("Odd group : %d integer(s).\n", odd);
			printf("Even group : %d integer(s).\n", even);
			if (j == n){
				printf("\n");
			} else {
				printf("");
			}
			printf("\n");
	}
	
}
