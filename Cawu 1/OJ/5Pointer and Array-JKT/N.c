#include <stdio.h>
#include <string.h>

int main()
{
    int t;
    scanf("%d", &t);
    for(int o=1;o<=t;o++){
        int n;
        int j1=-1000000;
        int j2=-1000000;
        int temp,j1idx,j2idx;
        int idx=0;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            int temp;
            scanf("%d", &temp);
            if (temp > j1)
            {
                if(j2<j1){
                    j2=j1;
                }
                j1 = temp;
                j1idx=i;
            }
            if (temp > j2 && i != j1idx)
            {
                j2 = temp;
                j2idx=i;
            }
        }
        printf("Case #%d: %d\n",o,j1+j2);
    }
    return 0;
}