#include <stdio.h>

int main(){
	int n,t;
	long long int i,jump,l,counter,total;
	
	scanf("%d", &n);
	for(i = 1;i <= n;i++){
		jump = 0;
		scanf("%d", &t);
		counter = 0; 
		total = 0;
		for(l = 1;l <= t;l++){
			counter += l;
			if (counter >= t || counter == t){
				break;
			} else {
				total++;
			}
		}
		printf("Case #%lld: %lld\n", i,total+1);
	}
}
