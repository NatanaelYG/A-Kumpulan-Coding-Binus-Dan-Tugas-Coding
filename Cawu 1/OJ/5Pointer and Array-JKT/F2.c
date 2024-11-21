#include <stdio.h>
#include <string.h>

int main()
{
    int t;
    scanf("%d", &t);
    for(int o=1;o<=t;o++){
        char s[100001];
        int jumlah=0;
        int index=0;
        int name[27]={0};
        scanf("%s", s);
        int len=strlen(s);
        // printf("%d", 'a'-97);
        for(int i=0;i<len;i++){
            name[s[index]-97]++;
            index++;
        }
        for (int i = 0; i <27; i++)
        {
            if(name[i]!=0){
                jumlah++;
            }
        }
        if(jumlah%2==0){
            printf("Case #%d: Yay\n",o);
        }else{
            printf("Case #%d: Ewwww\n",o);
        }
    }
    return 0;
}