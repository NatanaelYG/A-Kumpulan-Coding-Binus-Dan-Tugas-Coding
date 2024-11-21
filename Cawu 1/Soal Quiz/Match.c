#include <stdio.h>

int main()
{
	int i,j,k,l;
	int t,n,a[101],p,q;
	
	scanf("%d", &t);
	for(i = 1;i <= t;i++){
		scanf("%d", &n);
		for(j = 1;j <= n;j++){
			scanf("%d", &a[j]);
		}
		
	for(k = 0; k < 1;k++){
		scanf("%d %d", &p, &q);
		}
	
		printf("Case #%d : ",i);
		if (a[p] < a[q]){
		printf("Lili\n");
	} else if(a[p] > a[q]){
		printf("Bibi\n");
	} else if(a[p] == a[q]){
		printf("Draw\n");
	}
	}
}
