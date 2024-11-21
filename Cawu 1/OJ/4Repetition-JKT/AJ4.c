#include <stdio.h>

int main(){
	
	int n,m,i,total=0;
	
	scanf("%d", &m);
	for (i = 1; i <= m; i++){
		scanf("%d", &n);
		total += n;
	}
	printf("%d\n", total);
}
