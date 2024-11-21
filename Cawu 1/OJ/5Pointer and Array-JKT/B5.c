#include <stdio.h>

int main()
{
	int i,j,k,l;
	int t, n;
	int bahan[1000];
	int milik[1000];
	int total = 0;
	
	scanf("%d", &t);
	for (i = 1;i <= t;i++){
		scanf("%d", &n);
		for (j = 1; j <= n;j++){
			scanf("%d", &bahan[j]);
		}
		for (j = 1; j <= n;j++){
			scanf("%d", &milik[j]);
		}
			printf("Case #%d: ", i);
			for (k = 1;k <= n;k++){
				total = 0;
				total = bahan[k] - milik[k];
				k == n ? printf("%d\n", total):printf("%d ", total);
//				if (k == n){
//					printf("%d\n", total);
//				} else {
//					printf("%d ", total);
//				}
			}
		}
	}


