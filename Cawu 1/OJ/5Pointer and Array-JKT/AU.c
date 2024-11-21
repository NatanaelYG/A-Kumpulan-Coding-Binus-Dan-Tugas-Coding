#include <stdio.h>

int main()
{
	int t, m;
	int i,j,k,l;
	scanf("%d", &t);
	for ( i = 1; i <= t; i++)
	{
		for ( j = t; j >= i;j--){
			printf(" ");
		}
		for ( k = 1; k <= i; k++){
			printf("*");
		}
		printf("\n");
	}
		for ( j = t; j >= i;j--){
			printf(" ");
		}
		for ( k = 1; k <= i; k++){
			printf("*");
		}
		printf("\n");
	}
	
//for (int i = 1; i <= n; i++){
//        for(int j = n; j >= i; j--){
//            cout << " ";
//        }
//        for(int k = 1; k <= i; k++){
//            cout << "*";
//        }
//        cout << endl;
//    }
