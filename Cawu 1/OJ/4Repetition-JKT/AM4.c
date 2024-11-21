#include <stdio.h>

int main() {
	int n,m,i,j;
	scanf("%d", &n);
	getchar();
	for (i = 1;i <= n;i++){
		printf("Case #%d:\n", i);
		scanf("%d", &m);
		getchar();
		for (j = 1;j <= m;j++){
			if (j % 15 == 0){
			printf("%d Lili\n", j);			
		} else if (j % 3 == 0 || j % 5 == 0){
			printf("%d Jojo\n", j);
		} else {
			printf("%d Lili\n", j);
		}
		}
	}
}
