#include <stdio.h>

int main()
{
	int t,n,a,b,c,d,e;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++){
		e=0;
		scanf("%d %d %d %d %d",&n, &a, &b, &c, &d);
		for(int j=1; j<=n;j++){
			if (j%a == 0 || j%b == 0 || j%c == 0 || j%d == 0){
				e++;
			}
		}
		printf("Case #%d: %d\n",i ,e);
	}
}
