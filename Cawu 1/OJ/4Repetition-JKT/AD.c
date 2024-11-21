#include <stdio.h>

int main(){
	int n,a, max = 0, array[1001] = {0};
	int i;
	
	scanf("%d", &n);
	for(i = 1;i <= n;i++){
		scanf("%d", &a);
		array[a]++;
		if (array[a] >= max){
		max = array[a];
		}
	} 
	printf("%d\n", max);
}
