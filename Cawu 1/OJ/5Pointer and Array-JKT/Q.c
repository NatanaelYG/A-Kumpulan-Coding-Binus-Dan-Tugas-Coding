#include <stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    for(int i = 1; i <=t; i++) {
        int n,m,q;
        scanf("%d %d %d",&n,&m,&q);
        int friends[51][51];
        int room[51]={0};
        for(int j = 0; j < n; j++){
            for(int k = 0; k < m; k++){
                int temp;
                scanf("%d",&temp);
                friends[j][k]=temp;
            }
        }
        for(int l=0;l<q;l++){
            int temp;
            scanf("%d",&temp);
            for(int o=0;o<m;o++){
                int res=friends[temp-1][o]+room[o];
                if(res>1){
                    room[o]=0;
                }else{
                    room[o]=res;
                }
            }
        }
        printf("Case #%d:\n",i);
        for(int p=0;p<m;p++){
            if(room[p]==0){
                printf("NO\n");
            }else{
                printf("YES\n");
            }
        }
    }
    return 0;
}