#include <stdio.h>

int main(){
	int t,s;
	char arr1[100],arr2[100];
	int i,j,k,nilai,benar;
	
	scanf("%d", &t);
	for(i = 1; i <= t;i++){
		nilai = benar = 0;
		scanf("%d", &s);
		
		scanf("%s", arr1);
		scanf("%s", arr2);
		for (j = 0;j < s;j++){
			if(arr1[j] == arr2[j]){
				benar++;
			}
		}
		nilai = (benar*100)/s;
		printf("Case #%d: %d\n",i, nilai);
	}
}
