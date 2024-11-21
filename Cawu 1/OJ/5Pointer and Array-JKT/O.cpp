#include <stdio.h>

int main(){
    int n,i,j,k,l;
    int input[105][105],baris,kolom,count = 0,temp;

    scanf("%d",&n); getchar();
    for(j = 0;j<n;j++){
        for(k = 0;k<n;k++){
            scanf("%d", &input[j][k]);
        }
    }
    for(i = 0;i<n;i++){
        for(k = 0;k<n;k++){
            temp = input[i][k];
            for (l = k+1; l < n; l++){
                if(temp == input[i][l]){
                    count++;
                    break;
                }
            }
            for(l = i+1; l < n; l++){
                if(temp == input[l][k]){
                    count++;
                    break;
                }
            }
        }
    }

    if(count > 0){
        printf("Nay\n");
    } else {
        printf("Yay\n");
    }
}