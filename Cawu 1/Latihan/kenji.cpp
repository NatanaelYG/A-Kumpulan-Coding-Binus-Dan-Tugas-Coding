#include <stdio.h>
#include <math.h>
#include <string.h>
int main()
{
    int Case, X = 0;
    scanf("%d", &Case);
    for (int i = 1; i <= Case; i++)
    {
        char char1, char2, char3;
        int count1 = 0, count2 = 0, count3 = 0;
        scanf("%c %c %c", &char1, &char2, &char3);
        if (char1 == '+')
        {
            count1++;
        }
        else if (char1 == '-')
        {
            count2++;
        }
        else if (char1 == 'x')
        {
            count3++;
        }
        if (char2 == '+')
        {
            count1++;
        }
        else if (char2 == '-')
        {
            count2++;
        }
        else if (char2 == 'x')
        {
            count3++;
        }
        if (char3 == '+')
        {
            count1++;
        }
        else if (char3 == '-')
        {
            count2++;
        }
        else if (char3 == 'x')
        {
            count3++;
        }
        if (count1 == 2 && count3 == 1)
        {
            X++;
        }
        else if (count2 == 2 && count3 == 1)
        {
            X--;
        }
    }
    printf("%d", X);
}