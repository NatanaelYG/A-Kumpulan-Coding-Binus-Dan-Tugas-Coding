#include <stdio.h>
#include <string.h>

    int ispali[10000][10000] = {};

int main(){
    char input[10000];
    int i,j,k,l;
    
    scanf("%s", input);
    int len = strlen(input);
    int counter = 0;

    int alphabet[27] = {};
    for(i = 0;i < len;i++){
        alphabet[input[i] - 'a']++;
    }

    for(i = 0;i < 26; i++){
        if (alphabet[i] != 0) counter++;
    }

    for(i = 0;i < len;i++){
        ispali[i][i] = 1;
        counter++;
    }

    for (i = 0;i < len - 1;i++){
        if(input[i] == input[i + 1]){
            ispali[i][i+1] = 1;
            counter++;
        }
    }

    for(k = 3;k <= len; k++){
        for(i = 0;i < len - k + 1;i++){
            j = i + k - 1;
            if(input[i] == input[j] && ispali[i+1][j - 1]){
                ispali[i][j] = 1;
                counter++;
            }
        }
    }

    printf("Total Unique Palindrome : %d\n", counter);

    return 0;
}