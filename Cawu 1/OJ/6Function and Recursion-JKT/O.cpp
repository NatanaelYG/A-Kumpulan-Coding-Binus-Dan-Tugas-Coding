#include <stdio.h>

int input[105][105];
int count;
int m, n;

void asd(int baris, int kolom)
{
    if (input[baris][kolom] == '#' || baris < 1 || kolom < 1 || baris > n || kolom > m)
    {
        return;
    }
    else
    {
        if (input[baris][kolom] == '*')
        {
            count++;
        }
        input[baris][kolom] = '#';
        // printf("baris : %d kolom : %d\n", baris, kolom);
        asd(baris + 1, kolom);
        asd(baris, kolom + 1);
        asd(baris - 1, kolom);
        asd(baris, kolom - 1);
    }
}

int main()
{
    int t, i, j, k;
    int baris, kolom;

    scanf("%d", &t);
    getchar();
    for (i = 1; i <= t; i++)
    {
        scanf("%d %d", &n, &m);
        getchar();
        for (j = 1; j <= n; j++)
        {
            for (k = 1; k <= m; k++)
            {
                scanf("%c", &input[j][k]);
                if (input[j][k] == 'P')
                {
                    baris = j;
                    kolom = k;
                    // printf("%d %d", baris, kolom);
                }
            }
            getchar();
        }
        count = 0;
        asd(baris, kolom);
        printf("Case #%d: %d\n", i, count);
    }
    return 0;
}