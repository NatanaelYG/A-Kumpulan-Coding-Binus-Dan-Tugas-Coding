#include <stdio.h>

int main(){
	long long int n,t, result;
	int i;
	
	scanf("%lld", &n);
		result = 0;
	for (i = 1;i <= n;i++){
		scanf("%lld", &t);
			result = result + t;
			if (result >= 40){
				result -=  40; 
			} else if (result == 30){
				result = 10;
			} else if (result == 12){
				result = 28;
			} else if (result == 35){
				result = 7;
			}
	}
	printf("%lld\n", result);
}
