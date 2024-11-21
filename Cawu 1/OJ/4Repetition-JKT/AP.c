#include <stdio.h>

int main(){
	int t,n,m,i,j,k;
	char s,hasil[100];
	int angka;
	
	scanf("%d", &t);
	for(i = 1;i <= t;i++){
		scanf("%d %d", &n, &m); getchar();
		for(j = 1;j <= n;j++){
			scanf("%c", &s); 
		angka = s - 'a';
		angka = angka + m;
		if(angka > 25){
			angka = angka % 26;
		} hasil[j] = angka + 'a';
		}
		printf("Case #%d: ",i);
		for (j = 1;j <= n;j++){
			printf("%c",hasil[j]);
		}
		printf("\n");
	
}
}
