#include <stdio.h>

int main(){
	int t,n,x[1005],i,j;
	int kurang,min;
	
	scanf("%d", &t);
	for(i = 1;i <= t;i++){
//		kurang = 0;
//		min = 0;
		scanf("%d", &n);
		for(j = 0;j < n;j++){
			scanf("%d", &x[j]); getchar();
		}
			
//		min = x[1]-x[0];
		min = 2000000000;
		for(j = 0;j < n-1;j++){
			kurang = x[j+1] - x[j];
			if (kurang < 0){
				kurang = kurang*(-1);
			}
			if (kurang < min){
				min = kurang;
			}
		}
		printf("Case #%d: %d\n", i, min);
	}
}
