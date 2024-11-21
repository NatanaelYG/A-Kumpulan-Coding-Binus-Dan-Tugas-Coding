#include <stdio.h>
#include <stdbool.h>

int main()
{
//	int n;
//	int num = 10;
//	int *ptrnum;
//	
//	ptrnum = &num;
//	printf("%d\n", *ptrnum);
//	printf("%d\n", ptrnum);
//	printf("%d\n", &ptrnum);
//	
//	*ptrnum = 132;
//	printf("%d\n", *ptrnum);
//	printf("%d\n", num);
//	
//	int numarray[3];
//	
//	for(int i = 1;i <= 3;i++){
//		printf("[%d] : %d\n", i, &numarray[i]);
//	}
	
	double ipk[5], deletedipk;
	int ipkcount = 5, i;
	bool isfound = false;
	double deleted;
	
//	ipk[ipkcount++];
	
	for(i = 1;i <= 5;i++){
		scanf("%lf", &ipk[i-1]);
//		printf("%.2lf\n", ipk[i-1]);
	}	
	
	printf("Deleted Array ");
	scanf("%lf", &deletedipk);
	for(i = 1;i <= 5;i++){
	if(ipk[i-1] == deletedipk){
			isfound = true;
		}
		if (isfound){
			ipk[i-1] = ipk[i];
		}	
	}
	
	ipkcount--;
	for(i = 1;i <= ipkcount;i++){
		printf("%.2lf\n", ipk[i-1]);
	}
	return 0;
}
