#include <stdio.h>

int main(){
	int studio;
	int n,rombongan, sum,max=0,count = 0;;
	int i,j,k;
	
	scanf("%d", &studio);
	scanf("%d", &n);
	sum = 0;
	for(i = 0;i < n;i++){
		scanf("%d", &rombongan);
		sum += rombongan;
	} 
	for(i = 0;i < n;i++){
		if(sum > studio){
			sum = sum - studio;
			count++;
//			printf("%d", count);
		} else {
			count++;
			break;
//			printf("%d", count);
		}
	} 
	printf("%d\n", count);
}
