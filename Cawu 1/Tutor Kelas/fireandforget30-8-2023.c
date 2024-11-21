#include <stdio.h>
#include <ctype.h>
#include <string,h>

int main()
{
	int angka, min, max, total, i;
	
	
	scanf("%d", &angka);
	min = max = total = angka;
	for(i = 1;i < 10; i++){
		scanf("%d", &angka);
		if(max < angka) max = angka;
		if(min > angka) min = angka;
		total = total + angka;
	}
	printf("%d %d %f\n", min, max, total);
	
	return 0;
}
