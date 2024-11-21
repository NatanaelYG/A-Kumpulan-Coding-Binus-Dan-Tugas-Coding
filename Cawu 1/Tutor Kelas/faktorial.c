#include <stdio.h>

int main(){
	int n,m,total = 1,i;
	
	scanf("%d", &n);
	for (i = 1;i <= n;i++){
		total *= i;
		
		printf("Case #%d : %d\n", i, total);
	}
	
	return 0;
}
