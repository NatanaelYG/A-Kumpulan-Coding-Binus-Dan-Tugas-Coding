#include <stdio.h>
#include <string.h>

int main(){
    int lifepoint = 7,len, cek;
    int i,j,k,l;
    char key[100],answer;

    printf("Input Your Key : ");
    scanf("%s", key); getchar();
    len = strlen(key);
        char under[100] = {};

    do{
        printf("\nLifepoint : %d\n", lifepoint);
        printf("Input Your Answer : ");
        scanf("%c", &answer); getchar();


        for(j = 0;j < len;j++){
                if(key[j] == answer){
                    cek = 1;
                    under[j] = answer;
                } else if(j == len-1 && key[j] != answer && cek == 0){
                    lifepoint--;
                    cek = 0;
                }
            }
            under[len] = '\0';

        for(j = 0;j < len;j++){
                printf("%c ", under[j]);
                // if(key[j] == under[j]){
                //     break;
                // }
            }
    } while (!(lifepoint == 0 || strcmp(key,under) == 0));
    return 0;
}