#include <stdio.h>

int main()
{
	int n;
	int i,j;
	int a[5000];
	int happycus = 0, happy;
	
	scanf("%d", &n);
	for (i = 0;i < n;i++){
		scanf("%d", &a[i]);
		happy = 1;
		for (j = 0; j < i; j++){
			if(a[j] == a[i]){
				happy = 0;
				break;
			}
		}
		if (happy){
			happycus++;
		}
	}
	printf("%d\n", happycus);
}