#include <stdio.h>

int main(){
	int t,a,b;
	int i,j,k,l;
	int total[1000], counter;
	
	scanf("%d", &t);
	for(i = 1;i <= t;i++){
		scanf("%d %d", &a, &b);
		counter=0;
			printf("Case #%d: ", i);
		while(a != 0 || b!=0){
			k=a%10, l=b%10;
			
			total[counter] = (k+l) %10;
			counter++; 
			a /=10, b /= 10;
			}  
		while(total[counter-1] == 0){
			counter--;
			if(counter < 0){
				printf("0");
			}
		}
			for(j=counter-1; j>= 0; j--){
			printf("%d", total[j]);
			}
			printf("\n");
	}
}
