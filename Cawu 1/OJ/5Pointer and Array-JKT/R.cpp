#include <string.h>
#include <stdio.h>

int main(){
    int i,j,k,l;
    int t,m;
    char input[1005],hurufa,hurufb;

    scanf("%d",&t); getchar();
    for(i=1;i<=t;i++){
        scanf("%s", input); getchar();
        scanf("%d", &m); getchar();
        for(j=0;j<m;j++){
            scanf("%c %c", &hurufa, &hurufb); getchar();
            for(k = 0;input[k];k++){
                if (input[k] == hurufa){
                    input[k] = hurufb;
                } 
            }
        }
        printf("Case #%d: %s\n", i, input);
    }
    return 0;
}