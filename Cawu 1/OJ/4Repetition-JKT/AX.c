#include <stdio.h>

int main(){
	long long int n, i, j;
	long long int a, hasil;
	
	scanf("%lld", &n);
		hasil = 0;
	for(i = 1;i <= n;i++){
		scanf("%lld", &a);
		if(a < 0){
			a = 0;	
		} 
			hasil += a;
			
	}
	printf("%lld\n", hasil);
}
