//#include <stdio.h>
//#include <limits.h>  
//
//int main() {
//    int n,num;
//    int i;
//    int total = 0;
//    int ganjilkecil = INT_MAX;  
//
//    scanf("%d", &n);
//
//    for (i = 1; i <= n; i++) {
//        scanf("%d", &num);
//        total += num;
//
//        if (num % 2 == 1 && num < ganjilkecil) {
//            ganjilkecil = num;
//        }
//    }
//
//    if (total % 2 == 1) {
//        total -= ganjilkecil;
//    }
//
//    printf("%d\n", total);
//
//    return 0;
//}

#include <stdio.h>

int main(){
	int n,m[1000];
	int i,min;
	int total = 0;
	
	scanf("%d", &n);
	for (i = 1;i <= n;i++){
		scanf("%d", &m[i]);
		total += m[i];
	}
	
	for (i = 1;i <= n;i++){
		if (m[i] % 2 == 1){
			min = m[i];
			break;
		}
	}
	
	if (total % 2 == 0){
		printf("%d", total);
	} else {
		printf("%d", total - min);
	}
	return 0;
}
