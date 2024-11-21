#include <stdio.h>

int main()
{
	int t,n,angka, sum;
	int i,j;
	
	scanf("%d", &t);
	for (i = 1;i <= t;i++){
		scanf("%d", &n); getchar;
		printf("Case %d: ",i);
		angka = 0;
		sum = 1;
		for(j = 1;j <= n;j++){
			sum += angka++;
			if (j == n){
				printf("%d\n", sum);
			} else {
				printf("%d ", sum);
			}
		}
	}
}
