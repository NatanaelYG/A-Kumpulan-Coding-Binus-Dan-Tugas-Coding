#include <stdio.h>
#include <string.h>

int main(){
    int i,j,k,l,count;
    char input[1000],save[1000][1000];

    scanf("%[^\n]", input);getchar();
    int len = strlen(input);

    count = 0;
    k = 0;
    for(i = 0;i < len;i++){
        if(input[i] == ' ' || i == len-1){
            if(i == len-1) i+=1;
            int set = 0;
            for(j = k;j < i;j++){
                save[count][set++] = input[j];
            }
            save[count][set++] = '\0';
            count+=1;
            k = i+1;
        }
    }

    // for(i = 0; i < count; i ++){
    //     printf("%s\n", save[i]);
    // }
    for(i = 0; i < count; i++){
        int sublen = strlen(save[i]);
        for(j = sublen;j >= 0;j--){ 
            printf("%c", save[i][j]); 
        } 
        printf(" ");
    }
    return 0;
}