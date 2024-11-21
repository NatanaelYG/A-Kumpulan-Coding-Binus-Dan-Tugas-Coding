#include <stdio.h>

int main(){
	int t,n,i,j,k;
	char input[100];
	
	scanf("%d", &t); getchar();
	for(i = 1;i <= t;i++){
		scanf("%d", &n); getchar();
		for (j = 1;j <= n;j++){
			scanf("%[^\n]", &input[j]);	
		}	
		printf("Case #%d: ", i);
		for (j = 1;j <= n;j++){	
			if (input[j] >= 'a' && input[j] <= 'z'){
				printf("%c", input[j]);
			}
		}
		printf("\n");
	}
}
