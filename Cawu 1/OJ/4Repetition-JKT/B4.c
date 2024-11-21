#include <stdio.h>

int main()
{
	int n,m,i;
	
	scanf("%d %d", &n, &m);
	for(i = 1; i <= m;i++){
		printf("%d\n", n++);
	}
	return 0;
}
