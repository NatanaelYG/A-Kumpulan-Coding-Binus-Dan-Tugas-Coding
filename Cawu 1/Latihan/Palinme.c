#include <stdio.h>

int main(){
	int t,i,j,k;
	char n[1000];
	
	scanf("%d", &t);
	for(i = 0;i <= t;i++){
		scanf("%s", &n[i]);
		if(n[i] == 'n'){
			printf("%s", n[i]);
		} else if (n[i] == 'd') {
			printf("%s", n[i]);
		} 
	}
	
}
