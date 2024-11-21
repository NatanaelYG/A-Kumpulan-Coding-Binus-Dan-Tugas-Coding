#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

int main()
{
    int k,j,i,l;
    scanf("%d", &k);
    for(i=1; i<=k; i++){
        char s[1001];
        int idx[1001];
        
        scanf("%s", s);
        printf("Case #%d:\n", i);

        for(j=0;j<strlen(s);j++){
            if(s[j]-0>=65&&s[j]-0<=68){
                idx[j]= abs(s[j]-'A');
                printf("A");
            }else if(s[j]-0>=69&&s[j]-0<=72){
                idx[j]= abs(s[j]-'E');
                printf("E");
            }else if(s[j]-0>=73&&s[j]-0<=78){
                idx[j]= abs(s[j]-'I');
                printf("I");
            }else if(s[j]-0>=79&&s[j]-0<=84){
                idx[j]= abs(s[j]-'O');
                printf("O");
            }else if(s[j]-0>=85&&s[j]-0<=90){
                idx[j]= abs(s[j]-'U');
                printf("U");
            }
    }
            printf("\n");
        for(l=0;l<strlen(s);l++){
            printf("%d",idx[l]);
        }
        printf("\n");
    }
    return 0;
}