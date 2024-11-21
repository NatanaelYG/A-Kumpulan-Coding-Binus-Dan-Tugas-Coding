#include <stdio.h>

int main()
{
	int t, a, b, c;
	
	scanf("%d", &t);
	for (int i = 1; i <= t; i++){
		scanf("%d %d %d", &a, &b, &c);
		if (a*b/100 > c){
			printf("Case #%d: %d\n", i, c);
		} else {
			printf("Case #%d: %d\n",i , a*b/100);
		}
	}
}
