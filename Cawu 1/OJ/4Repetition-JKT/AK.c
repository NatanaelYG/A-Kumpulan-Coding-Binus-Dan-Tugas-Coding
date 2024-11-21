#include <stdio.h>

int main(){
	int n,a[1005],i;
	
	scanf("%d", &n); getchar();
	for(i = 0;i < n;i++){
		a[i] = 0;
		scanf("%d", &a[i]); getchar();
	}
	for(i = 0;i < n;i++){
		if (i == n-1){
				printf("%d\n", a[i]);
			} else if(a[i] >= a[i+1]){
				printf("%d ", a[i]);
		}
		// if(a[i] >= a[i+1] && i != n-1){
		// 	if (i == n){
		// 		printf("%d\n", a[i]);
		// 	} else {
		// 		printf("%d ", a[i]);
		// 	}
		// }
	}
}