#include <stdio.h>

int main(){
	int m,n,i;
	
	scanf("%d", &m);
	for (i = 0; i < m;i++){
		scanf("%d", &n);
		n++;
	}
	printf("%d", n);
	
	return 0;
}
