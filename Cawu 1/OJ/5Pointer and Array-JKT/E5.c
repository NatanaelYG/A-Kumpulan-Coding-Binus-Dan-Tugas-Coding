#include <stdio.h>

int main()
{
	int i,j,k,l,m;
	int t,x;
	int a[101][101];
	int b[100];
	
	scanf("%d", &t);
	for(i = 1;i <= t;i++){
		scanf("%d", &x);
		for(j = 1;j <= x;j++){
			for (k = 1;k <= x;k++){
				scanf("%d", &a[j][k]);
			}	
		}
		printf("Case #%d: ",i);
		for(l = 1;l <= x;l++){
			for(m = 1;m <= x;m++){
			b[l] += a[m][l];
			}
			if (l == x){
				printf("%d\n", b[l]);
			} else {
				printf("%d ", b[l]);
			}
			b[l] = 0;
		}
	}
}
