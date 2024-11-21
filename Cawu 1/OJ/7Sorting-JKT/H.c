#include <stdio.h>
#include <string.h>

int main(){
    int i,j,k,l;
    int r,c;
    char input[205][205], temp,temps[205];

    scanf("%d %d", &r, &c); getchar();
    for(i = 0; i < r; i++){
        for(j = 0; j < c; j++){
            scanf("%c", &input[i][j]); 
        }   
        getchar();
    }

    for(i = 0; i < r ; i++){
        for(j = 0; j < c - 1; j++){
            for(k = 0; k < c - j - 1; k++){
                if(input[i][k] > input[i][k+1]){
                    temp = input[i][k];
                    input[i][k] = input[i][k+1];
                    input[i][k+1] = temp;
                }
            }
        }
    }

    for(i = 0; i < r; i++){
        for(j = 0; j < r - i - 1; j++){
            if(strcmp(input[j],input[j+1]) < 0){
                strcpy(temps,input[j]);
                strcpy(input[j],input[j+1]);
                strcpy(input[j+1],temps);
            }
        }
    }
    for(i = 0; i < r; i++){
        for(j = 0;j < c; j++){
            printf("%c",input[i][j]);
        }
        printf("\n");
    }
}