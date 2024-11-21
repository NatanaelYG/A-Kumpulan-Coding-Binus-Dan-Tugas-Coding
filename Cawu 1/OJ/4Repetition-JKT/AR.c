#include <stdio.h>

int main()
{
	int t, m;
	scanf("%d %d", &t, &m);

	for (int s = 0; s < t; s++)
	{
		for (int i = 1; i <= m; i++)
		{
			for (int j = 1; j <= m-i; j++)
			{
				printf(" ");
			}
			for (int k = 1; k <= i; k++)
			{
				printf("*");
			}
			printf("\n");
		}
	}
}
