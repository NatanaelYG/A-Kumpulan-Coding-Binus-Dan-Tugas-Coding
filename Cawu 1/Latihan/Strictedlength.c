#include <stdio.h>
#include <string.h>

int main(){
	int N,i,j,k;
	
	int num;
	
	scanf("%d", &N);
	for (i = 0;i < N;i++){
		num = 0;
		char a[105];
		scanf("%s", &a); getchar();
		num = strlen(a);
		if(num >= 10){
			printf("%c%d%c\n", a[0],num-2,a[num-1]);
		} else {
			printf("%s\n", a);
		}
	}
	printf("\n");
}
