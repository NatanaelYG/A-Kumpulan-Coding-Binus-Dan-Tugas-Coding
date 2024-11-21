#include <stdio.h>
#include <string.h>

int main(){
    int t,i,j,k,l;
    int nomor[255];
    char nama[100][255];
    char nomor1,nomor2,idx,idxs;

    scanf("%d", &t);
    for(i = 0;i < t;i++){
        scanf("%d %s", nomor[i], nama[i]);
    }
    scanf("%d", &nomor1);
    scanf("%d", &nomor2);


    for(i = 0;i < t;i++){
        if(nomor[i] == nomor1){
    		printf("%s", nama[nomor1]);
    		break;
        } 
    }
    
    for(i = 0;i < t;i++){
        if(nomor[i] == nomor2){
        } 
    }
//    printf("%s is calling %s\n", nama[nomor1],nama[nomor2]);

}
