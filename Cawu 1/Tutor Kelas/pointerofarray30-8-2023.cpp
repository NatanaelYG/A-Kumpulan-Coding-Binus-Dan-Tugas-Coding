#include <stdio.h>

int main(){
	int angka[15];
	int max, min, i, total;
	float average;
	
	
	for( i = 0;i < 10; i++){
		scanf("%d", &angka[i]);
	}
	
	max = min = angka[0];
	for(i = 0; i < 10;i++){
		if(max < angka[i]) max = angka[i];
		if(min > angka[i]) min = angka[i];
		total += angka[i];
	}
	
	average = total / 10.0;
	printf("%d %d %f\n", max, min, average);
	
	return 0;
}
