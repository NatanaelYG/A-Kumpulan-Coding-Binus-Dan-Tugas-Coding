#include <stdio.h>

int main()
{
    int t;
    scanf("%d", &t);
    
    for(int i=1;i<=t;i++){
        int num;
        scanf("%d", &num);
        if(num==1){
            printf("Case #%d: %d\n",i,0);
        }else{
            long long int t1 = 0, t2 = 1;
            long long int t3 = t1 + t2;
            for (int j = 3; j < num; ++j) {
                t1 = t2;
                t2 = t3;
                t3 = t1 + t2;
            }
            printf("Case #%d: %lld\n",i,t3);
        }
    }
    return 0;
}