#include <stdio.h>

int main()
{
    int testCase, amount, one, binary, on, off;
    int num[100];
    scanf("%d", &testCase);
    getchar();
    for(int i = 1; i <= testCase; i++)
    {
        scanf("%d", &amount);
        getchar();
        on = 0;
        off = 0;
        for(int j = 0; j < amount; j++)
        {
            scanf("%d", &num[j]);
            getchar();
        }
        for(int j = 0; j < amount-1; j++)
        {
            for(int k = j+1; k < amount; k++)
            {
                binary = num[j] ^ num[k];
                one = 0;
                while(binary / 2 != 0)
                {
                    if(binary % 2 == 1)
                    {
                        one++;
                    }
                    if(one == 3)
                    {
                        break;
                    }
                    binary /= 2;
                }
                if(binary == 1)
                {
                    one++;
                }
                if(one >= 3)
                {
                    on++;
                }
                else
                {
                    off++;
                }
            }
        }
        printf("Case #%d: %d %d\n", i, on, off);
    }
    return 0;
}
