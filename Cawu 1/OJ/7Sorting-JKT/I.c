#include <stdio.h>
#include <stdlib.h>

int main(){
    long long int t,n,a[505];
    long long int i,j,k,l,selisih, max = 0, max2 = 0;

    scanf("%lld", &t);
    for(i = 1;i <= t;i++){
    	max = 0;
    	max2 = 0;
        scanf("%lld", &n);
        for(j = 0;j < n;j++){
            scanf("%lld", &a[j]);
        }
        for(k = 0;k < n-1;k++){
        	for(l = 0;l < n-k-1;l++){
        		if(a[l] > a[l+1]){
        			long long int temp = a[l];
        			a[l] = a[l+1];
        			a[l+1] = temp;
				}
			}
		}
//        for(j = 0;j < n;j++){
//            printf("%d ", a[j]);
//        }
//		printf("\n");
		for(j = 0;j < n-1;j++){
			if(j < n/2-1){
				selisih = abs(a[j] - a[j+1]);
				if(selisih > max2){
					max2 = selisih;
				}
//				printf("%d\n", selisih);
			} else if(j >= n/2){
				selisih = abs(a[j] - a[j+1]);
				if(selisih > max){
					max = selisih;
				}
//				printf("%d\n", selisih);
			}
		}
		if(max2 > max) printf("Case #%lld: %lld\n", i, max2);
		else printf("Case #%lld: %lld\n", i, max);
    }
}
