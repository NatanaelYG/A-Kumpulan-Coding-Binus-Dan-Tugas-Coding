#include <stdio.h>

int main()
{
	int jam, menit, jamm, menitm;
	char course[101];
	for (int i = 0; i < 5; i++){
	
	scanf("%s %02d:%02d-%02d:%02d", course, &jam, &menit, &jamm, &menitm);

	printf("%s %02d:%02d-%02d:%02d\n", course, jam-1, menit, jamm-1, menitm);
}
}

