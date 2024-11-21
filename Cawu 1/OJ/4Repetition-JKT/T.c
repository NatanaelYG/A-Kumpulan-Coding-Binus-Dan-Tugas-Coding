#include <stdio.h>

int main(){
	int n,tc,tv,ts;
	int i,j = 0;
	
	scanf("%d", &n);
	for(i = 1;i <= n;i++){
		scanf("%d %d %d", &tc, &tv, &ts);
		if(tv > ts){
			j++;
		}
	}
	printf("%d\n", j);
}
