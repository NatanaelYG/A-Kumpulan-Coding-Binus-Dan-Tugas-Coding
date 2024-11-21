#include <stdio.h>
#include <string.h>

int main()
{
	char m[1000] = { };
	int n,i;
	int panjang = 0;
	
	scanf("%d", &n);
	for(i = 1;i<= n;i++){
		scanf("%s", &m);
		panjang = strlen(m);
		printf("Case #%d: %d\n",i,panjang);
	}
}
