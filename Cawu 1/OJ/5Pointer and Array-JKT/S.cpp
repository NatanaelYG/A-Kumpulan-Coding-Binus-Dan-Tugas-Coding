// #include <stdio.h>

// int main(){
//     int t,a,b,count = 0;
//     int i,j,l,k,total[1000];

//     scanf("%d",&t);
//     for (i = 1; i <= t; i++){
//         scanf("%d %d",&a, &b);
//         printf("Case #%d: ",i);
//         while(a != 0 || b != 0){
//             j=a%10, l=b%10;

//             total[count] = (j+l)%10;
//             count++;
//             a /= 10, b /= 10;
//         }
//         while(total[count-1] == 0){
//             count--;
//             if(count < 0){
//                 printf("0");
//             }

//             for (k= count-1; k >= 0; k--){
//                 printf("%d",total[k]);
//             }
//             printf("\n");
//         }

//     }
// }

#include <stdio.h>

int main()
{
    int t;
    scanf("%d", &t);
    for(int i=1;i<=t;i++){
        int a,b;
        scanf("%d %d", &a, &b);
        int res=0;
        int multiplier = 1;
        int sum;
        while (a || b) {
            sum = (a % 10) + (b % 10);
            sum %= 10;
            res = (sum * multiplier) + res;
            a /= 10;
            b /= 10;
            multiplier *= 10;
        }
        printf("Case #%d: %d\n",i,res);
    }
    return 0;
}