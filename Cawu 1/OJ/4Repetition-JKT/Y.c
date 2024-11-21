#include <stdio.h>

int main(){
	int t,n,m;
	int i,j,k;
	
	scanf("%d", &t);
	for(k = 1;k <= t;k++){
		scanf("%d %d", &n, &m);
		printf("Case #%d:\n",k);
		for(i = 1;i <= n;i++){
			for(j = 1;j <= m;j++){
				if (i == 1 || i == n || j == 1 || j == m){
					printf("#");
				}
				else {
					printf(" ");
				}
			}
			printf("\n");	
		}
	}
}
