#include <stdio.h>

int main(){
    long long int  temp,n,x[105],y,i,j,k,l,count = 0;

    scanf("%lld", &n);getchar();
    for(i = 0;i < n;i++){
        scanf("%lld", &x[i]); getchar();
    }
    
   	for(j = 0;j < n-1;j++){
   		for(k = 0;k < n - j-1;k++){
   			if(x[k] > x[k+1]){
    			temp = x[k];
    			x[k] = x[k+1];
    			x[k+1] = temp;
			}
		}
	}

    scanf("%lld", &y); getchar();
    
    for(i = 0;i < n;i++){
        if(x[i] <= y){
            y -= x[i];
            count++;
            // printf("%lld ", y);
        } 
    }
    printf("%lld\n", count);
}
