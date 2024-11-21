#include <stdio.h>

int main() 
{
	int i,j,k;
	int hari;
	int jumlahtayangan[100];
	int jumlahhari;
	int a,b;
	int total=0;
	
	scanf("%d", &hari);
	for (i = 1;i <= hari;i++){
		scanf("%d", &jumlahtayangan[i]);
	}
	
	scanf("%d", &jumlahhari);
	for (j = 1;j <= jumlahhari;j++){
		total = 0;
		scanf("%d %d", &a, &b);
		for (i = a;i <= b;i++){
			total += jumlahtayangan[i];
		}
		printf("Case #%d: %d\n",j, total);
	}
	
}
