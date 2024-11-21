#include <stdio.h>
#include <string.h>

void asd(int m,char input[100][100], int nilai[]){
    int i,j,temps;
    char temp[100];

    for (i = 1;i <= m;i++){
        for(j = 1;j <= m - i;j++){
            if(nilai[j] < nilai[j+1]){
                strcpy(temp,input[j]);
                strcpy(input[j],input[j+1]);
                strcpy(input[j+1],temp);

                temps = nilai[j];
                nilai[j] = nilai[j+1];
                nilai[j+1] = temps;
            } else if (strcmp(input[j],input[j+1]) > 0 && nilai[j] == nilai[j+1]){
                strcpy(temp,input[j]);
                strcpy(input[j],input[j+1]);
                strcpy(input[j+1],temp);

                temps = nilai[j];
                nilai[j] = nilai[j+1];
                nilai[j+1] = temps;
            }
            // else if (nilai[j] > nilai[j+1]){
            //     strcpy(temp,input[j]);
            //     strcpy(input[j],input[j+1]);
            //     strcpy(input[j+1],temp);

            //     temps = nilai[j];
            //     nilai[j] = nilai[j+1];
            //     nilai[j+1] = temps;
            // }
        }
    }
}

int main(){
    int n,m, nilai[1005];
    char input[1005][100],search[100];
    int i,j,k,l;
    int count = 0;

    scanf("%d", &n);
    for(i = 1;i <= n;i++){
        scanf("%d", &m); getchar();
        for(j = 1;j <= m;j++){
            scanf("%[^#]#%d", input[j],&nilai[j]); getchar();
        }
            scanf("%s", search); getchar();
            asd(m,input,nilai);
        printf("Case #%d: ",i);
            for(j = 1;j <= m;j++){
                // printf("%s %d\n", input[j],nilai[j]);
                // count++;
                if(strcmp(search,input[j]) == 0){
                    printf("%d\n", j);
                    break;
                }
            }
            // count = 0;
    }

}