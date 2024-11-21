#include <stdio.h>

int main()
{
    int a,b;

    for (int i=0; i<4; i++){
    scanf("%d %d",&a,&b);
    
    printf("$%.2lf\n", 100/(100-(double)a)*b);
    }
}