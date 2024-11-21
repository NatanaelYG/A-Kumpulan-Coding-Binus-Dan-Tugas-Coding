#include <stdio.h>

int main(){
	int t,n,x[100000];
	int i,j,k,l=0,m;
	
	scanf("%d", &t);
	for(i = 1;i <= t;i++){
		int failed = 0;
		scanf("%d", &n);
		for(j = 0; j < n; j++){
			scanf("%d",& x[j]);
		}
		for (j = 0; j < n; j++){
			int temp;
			scanf("%d",& temp);
			if(x[j]<temp) failed++;
		}
	printf("Case #%d: %d\n",i, failed);
	}
}