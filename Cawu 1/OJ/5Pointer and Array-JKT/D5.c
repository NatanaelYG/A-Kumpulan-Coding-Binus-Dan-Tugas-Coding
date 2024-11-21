#include <stdio.h>

int main()
{
	int i,j,k,l,m;
	int x,y,z;
	int a[101][101];
	int b,c,d;
	
	
	scanf("%d %d", &x, &y);
	for (i = 1;i <= x;i++){
		for(j = 1;j <= y;j++){
			scanf("%d", &a[i][j]);
		}
	}
	
	scanf("%d", &z);
	for (k = 1;k <= z;k++){
				scanf("%d %d %d", &b,&c,&d);
				a[b][c] = d;
		}		
		
	for (i = 1;i <= x;i++){
		for(j = 1;j <= y;j++){
			if(j == y){
					printf("%d\n", a[i][j]);
				} else {
					printf("%d ", a[i][j]);
				}
		}
	}	
}
