#include <stdio.h>

int main()
{
	int x[1001],y;
	int t,n;
	int i,j,k,l;
	
	scanf("%d", &t);
	for(i = 1; i <= t;i++){
		scanf("%d", &n);
		for(j = 1;j <= n;j++){
			scanf("%d", &x[j]);
		}
		printf("Case #%d: ",i);
		for(j = n;j > 0;j--){
			if (j == 1){
				printf("%d\n", x[j]);
			} else{
				printf("%d ", x[j]);
			}
		}
	}
	return 0;
}
