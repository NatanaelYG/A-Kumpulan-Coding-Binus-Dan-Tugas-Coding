#include <stdio.h>
#include <string.h>

int main(){
    char nama[105][105],temp[105];
    int n,j,k;

    scanf("%d", &n);
    
    for(j = 0;j < n;j++){
    	scanf("%s", nama[j]);
	}
    for (j = 0; j < n; j++){
        for( k = 0; k < n - j - 1; k++){
            if(strcmp(nama[k],nama[k+1]) > 0){
                strcpy(temp,nama[k]); 
                strcpy(nama[k],nama[k+1]);
                strcpy(nama[k+1],temp);
            }
        }
    }
    for(j = 0;j < n;j++){
        printf("%s\n",nama[j]);

    }
}
