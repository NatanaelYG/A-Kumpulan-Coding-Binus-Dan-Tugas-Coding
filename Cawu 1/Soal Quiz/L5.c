//#include <stdio.h>
//
//int main()
//{
//	int i;
//	int n,a[999],b[999];
//	
//	scanf("%d", &n);
//	for(i = 0;i < n;i++){
//		scanf("%d", &a[i]);
//	}
//	
//	for(i = 0;i < n;i++){
//		scanf("%d", &b[a[i]]);
//	}
//	for(i = 0;i < n;i++){
//		i != n-1 ? printf("%d ", b[i]): printf("%d\n", b[i]);
//	}
//}

#include <stdio.h>

int main() {
    int tc, input[999], index[999];
    scanf("%d", &tc);
    for(int i = 0; i < tc; i++) {
        scanf("%d", &index[i]);
    }
    for(int i = 0; i < tc; i++) {
        scanf("%d", &input[index[i]]);
    }
    for(int i = 0; i < tc; i++) {
        i != tc-1 ? printf("%d ", input[i]): printf("%d\n", input[i]);
    }
}
