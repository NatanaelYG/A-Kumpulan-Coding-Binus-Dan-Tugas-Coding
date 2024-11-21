#include <stdio.h>

union bil{
	int di;
	char dc[4];
};

int main(){
	union bil bill;
	
	bill.di = 123123;
	printf("di = %d\n", bill.di);
	printf("dc[0] = %d\n", bill.dc[0]);
	printf("dc[0] = %c\n", bill.dc[0]);
	printf("dc[1] = %d\n", bill.dc[1]);
	printf("dc[1] = %c\n", bill.dc[1]);
	printf("dc[2] = %d\n", bill.dc[2]);
	printf("dc[2] = %c\n", bill.dc[2]);
	printf("dc[3] = %d\n", bill.dc[3]);
	printf("dc[3] = %c\n", bill.dc[3]);
}
