#include <stdio.h>

int main(){
	int t,n,i,j,k;
	char convert[50];
	
	scanf("%d", &t);
	for(i = 1;i <= t;i++){
		scanf("%d", &n);
		printf("Case #%d: ",i);
		for(j = 0; j < n; j++){
			convert[j] = j + 'a';
			printf("%c",convert[j]);
		}
		printf("\n");
	}
	return 0;
}
