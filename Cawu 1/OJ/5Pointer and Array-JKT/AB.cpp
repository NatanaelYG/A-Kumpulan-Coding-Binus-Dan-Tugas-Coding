#include <stdio.h>

int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++)
    {
        int h, w;
        scanf("%d", &h);
        w = h;
        int matriksa[100][100];
        int matriksb[100][100];
        int matriksc[100][100];
        int matriksab[100][100];
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                scanf("%d", &matriksa[i][j]);
            }
        }
        for (int i = 0; i < w; i++)
        {
            for (int j = 0; j < w; j++)
            {
                scanf("%d", &matriksb[i][j]);
            }
        }
        for (int i = 0; i < w; i++) 
        {
            for (int j = 0; j < w; j++)
            {
                scanf("%d", &matriksc[i][j]);
            }
        }

        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                int index = 0;
                for (int k = 0; k < w; k++)
                {
                    index += matriksa[i][k] * matriksb[k][j];
                }
                matriksab[i][j] = index;
            }
        }
        printf("Case #%d:\n", i);
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                int index = 0;
                for (int k = 0; k < w; k++)
                {
                    index += matriksab[i][k] * matriksc[k][j];
                }
                printf("%d", index);
                if (j < w - 1)
                {
                    printf(" ");
                }
                else
                {
                    printf("\n");
                }
            }
        }
        // printf("\n");
    }
    return 0;
}