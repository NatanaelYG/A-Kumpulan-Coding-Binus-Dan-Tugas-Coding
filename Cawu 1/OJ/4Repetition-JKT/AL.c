#include <stdio.h>
#include <stdbool.h>

int main(){
	int n,m,x,y,i,j,k,l;
	
	int weapon = 0;
	bool myth = false;
	scanf("%d %d", &n, &m);
	for(i = 1;i <= n;i++){
		scanf("%d", &x);
		if(x>weapon){
			weapon = x;
		}
	}
	for(j = 1;j <= m;j++){
		scanf("%d", &y);
		if(y>=weapon){
		myth = true;
		break;
	}
}
	if (!myth){
		printf("The dark secret was true\n");
	} else {
		printf("Secret debunked\n");
	}
}