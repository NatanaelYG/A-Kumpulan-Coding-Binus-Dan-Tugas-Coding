#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    char kata1[260] = {},kata2[260] = {};
    int i,j,k,l;
    int n,countmin = 0, countplus = 0;
    int word[30]={0};
    int total = 0;
    int len1 = 0,len2 = 0;
    int totals;

    scanf("%d", &n);
    for(i = 0;i < n;i++){

        for(int j=0; j<26; j++){
            word[j]=0;
        }

        scanf("%s", kata1); getchar();
        scanf("%s", kata2); getchar();

        len1 = strlen(kata1);
        len2 = strlen(kata2);
        totals = len1 + len2;
        printf("%d\n", len1);
        printf("%d\n", len2);


        for(j = 0;j < len1;j++){
            word[kata1[j] - 'a'] += 1;
            printf("%d ", word[kata1[j] - 'a']);
        } printf("\n");
        for(k = 0;k < len2;k++){
            word[kata2[k] - 'a'] -= 1;
            printf("%d ", word[kata2[k] - 'a']);
        } printf("\n");
        for(l = 0;l < 26;l++){
            if(word[l] > 0){
                countplus += abs(word[l]);
            } else {
                countmin += abs(word[l]);
            }
        }
        printf("%d\n", countplus);
        printf("%d\n", countmin);
        printf("Test %d: ",i + 1);
        printf("%d", total);
        if(countplus + countmin >= totals){
            printf("Anagram not found!\n");
        } else {
            printf("%d\n", countplus + countmin);
        }
        len1 = 0;
        len2 = 0;
        countplus = 0;
        countmin = 0;
        total = 0;
    }
}