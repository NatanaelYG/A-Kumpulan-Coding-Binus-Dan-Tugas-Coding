#include <stdio.h>

int main(){
	int n,i,j,k,l;
	int a[100],same,happy = 0;
	
	scanf("%d", &n);
	for (i = 1;i <= n;i++){
		scanf("%d", &a[i]);
		same = a[i+1];
		printf("%d", same);
		if (same == a[i+1]){
			
		} else {
			happy++;
		}
	}
	printf("%d",happy);
}
