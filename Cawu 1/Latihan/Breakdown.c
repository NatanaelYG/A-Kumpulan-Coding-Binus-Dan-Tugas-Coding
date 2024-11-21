#include <stdio.h>
#include <string.h>

int main(){
	int t,i,j,k;
	int nol;
	char n[100];
	
	scanf("%d", &t);
	for(i = 0;i < t;i++){
		scanf("%[^\n]", &n);
		printf("%c", n);
	}
	printf("\n");
	return 0;
}
