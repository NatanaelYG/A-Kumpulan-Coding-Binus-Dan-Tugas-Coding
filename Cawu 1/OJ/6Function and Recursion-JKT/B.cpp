#include <stdio.h>

void tree(int t,int input[],int index,int sum){
	int counter = 0;
	sum += input[index];
	if (index * 2 <= t){
		tree(t,input,index*2,sum);
		counter++;
	}
	if (index * 2 + 1 <= t){
		tree(t,input,index*2 + 1,sum);
		counter++;
	}
	if (counter == 0){
		printf("%d\n", sum);
	}
}

int main(){
	int n,t,i,j,input[100],sum = 0;
	
	scanf("%d", &n);
	for(i = 1;i <= n;i++){
		scanf("%d", &t);
		for(j = 1;j <= t;j++){
			scanf("%d", &input[j]);
		}
		int index = 1;
		printf("Case #%d:\n", i);
		tree(t,input,index,sum);
	}
	return 0;
}