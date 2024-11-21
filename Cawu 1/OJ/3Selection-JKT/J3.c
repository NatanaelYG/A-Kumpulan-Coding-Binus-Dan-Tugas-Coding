#include <stdio.h>

int main()
{
	long long int f, s, t;
	
	scanf("%lld %lld %lld", &f, &s, &t);
	
	if (f < t && s > t || f == s && f == t){
		printf("%lld\n", s-t);
	} else {
		printf("-1\n");
	}
}
