#include <stdio.h>

int main(){
	int q,total = 1;
	int i;
	
	scanf("%d", &q);
	for (i = 0; i < q; i++){
		total = (total*2) + 1;
	}
	printf("%d\n", total);
}
