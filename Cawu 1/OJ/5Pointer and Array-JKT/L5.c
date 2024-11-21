#include <stdio.h>

int main()
{
	int i;
	int n,a[1001],b[1001];
	
	scanf("%d", &n);
	for(i = 0;i < n;i++){
		scanf("%d", &a[i]); getchar();
	}
	for(i = 0;i < n;i++){
		scanf("%d", &b[a[i]]); getchar();
	}
	for(i = 0;i < n;i++){
	i != n-1 ? printf("%d ", b[i]):printf("%d\n",b[i]);
	}
	return 0;
}
