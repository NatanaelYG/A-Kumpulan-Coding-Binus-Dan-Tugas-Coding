#include <stdio.h>

int main(){
    int t,n,m,ang[10005], sum[10005];
    int i,j,k,l,count;

    FILE *fin = fopen("testdata.in","r");

    fscanf(fin,"%d\n", &t);
    for(i = 0;i < t;i++){
        fscanf(fin,"%d %d\n", &n, &m);
        while(fscanf(fin,"%d\n", &ang[i]) == '\0'){
            count = 0;
            sum[i] = ang[i] + ang[i+1];
        }
        for(i = 0;i < n-1;i++){
            sum[i] = ang[i] + ang[i+1];
            if(sum[i] == m){
                count++;
            }
        }
        printf("%d", count);
    }
}