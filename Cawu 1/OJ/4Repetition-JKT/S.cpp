#include <stdio.h>

int main(){
	long long int n,p,b,count;
	long long int i,hasil = 0;
	
	scanf("%lld %lld", &n, &p);
	for(i = 0;i < n;i++){
		scanf("%lld", &b);
		if (b < p){
			hasil++;
		} 
	}
	printf("%lld\n", hasil);
}
