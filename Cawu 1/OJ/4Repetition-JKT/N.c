#include <stdio.h>

int main(){
	int n,full,diminum,sisa,ditukar;
	int i;
	
	scanf("%d", &n);
	for(i = 0;i < n;i++){
		scanf("%d %d", &full, &diminum);
		ditukar = full;
		sisa = full;
		while (sisa >= diminum){
			sisa -= diminum;
			sisa++;
			ditukar++;
//			printf("%d\n", ditukar);
		}
		printf("Case #%d: %d\n",i+1,ditukar);
	}
}
