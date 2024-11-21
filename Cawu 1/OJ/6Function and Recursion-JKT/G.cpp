#include <stdio.h>
#include <string.h>

int pali(char kata[], int panjang){
    int i,j;
    int valid, cek = 0;
    for(i = 0,j = panjang - 1;i <= panjang-1, j >= 0;i++,j--){
        if (kata[i] == kata[j]){
            valid = 1;
        } else {
            valid = 0;
            break;
        }
    } 
    return valid;
}

int main(){
    int t, i;
    char kata[1005];
    int panjang;

    scanf("%d",&t);
    for(i=0;i<t;i++){
        scanf("%s", kata);
        panjang = strlen(kata);
    if(pali(kata, panjang) == 1){
        printf("Case #%d: yes\n",i+1);
    } else {
        printf("Case #%d: no\n",i+1);
    }
}
}