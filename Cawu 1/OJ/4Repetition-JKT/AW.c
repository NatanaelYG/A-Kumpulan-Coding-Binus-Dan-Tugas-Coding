#include <stdio.h>

int main(){
	int t,n,a,i,j,k;
	int hasil,max;
	
	scanf("%d",&t);
	for (i = 1;i <= t;i++){
		scanf("%d", &n);
		max = 0;
		for (j = 1;j <= n;j++){
			scanf("%d", &a);
			
			if (a > max){
				max = a;
				hasil = 1;
			} else if (max == a){
				hasil++;
			}
		}
		printf("Case #%d: %d\n",i,hasil);
	}
}
