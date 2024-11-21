#include <stdio.h>

int main(){
	int t;
	int a,b, jumlah;
	int i,j;
	
	scanf("%d", &t); getchar();
	for(i = 0;i < t;i++){
		scanf("%d %d", &a, &b);
		jumlah = a;
		while(a >= b){
			a -= b;
			a += 1;
			jumlah++;
		}
		printf("Case #%d: %d\n",i+1, jumlah);
	}
}
