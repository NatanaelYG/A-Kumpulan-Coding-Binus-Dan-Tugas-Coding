#include <stdio.h>

int main()
{
	int i,j,k,l;
	int t,n;
	int m[1005][1005];
	int z[1005];
	
	scanf("%d", &t);
	for(i = 1;i <= t;i++){
		scanf("%d", &n);
		for(j = 0;j < n;j++){
			for(k = 0;k < n;k++){
				scanf("%d", &m[j][k]);
			}
		}
		printf("Case #%d: ", i);
		for(j = 0;j < n;j++){
			for(k=0;k<n;k++){
				z[j] += m[j][k];
			}
			if (i == t){
			printf("%d\n",z[j]);
		} else {
			printf("%d ",z[j]);
		}
		}
	}
	
	return 0;
}
