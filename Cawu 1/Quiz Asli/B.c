#include <stdio.h>

int main()
{
    double Month,Interest;
    long long int Money;
    int i,j,T;
    int credits;

    scanf("%d",&T); getchar();
    for(i = 1;i <= T;i++){
        	Money = 0;
        	scanf("%lld %lf %lf",&Money,&Interest,&Month); getchar();
        	printf("Case #%d:", i); 
        	for(j = 1;j <= Month;j++){
            	printf("\n");
            	credits = (Money*((Interest/100)/12)*0.8);
            	Money += credits;
            	printf("%d %lld",j,Money);
        }
        printf("\n");
    }
}
