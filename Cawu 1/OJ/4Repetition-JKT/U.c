#include <stdio.h>

int main(){
	int t,n;
	int i,j,lili,bibi;
	char tes = 0;
	
	scanf("%d", &t); getchar();
	for (i = 1;i <= t;i++){
		scanf("%d", &n); getchar(); 
			lili = 0;
			bibi = 0;
		for (j = 0;j < n;j++){
			scanf("%c", &tes);
			if(tes == 'L'){
				lili++;
			} else if (tes == 'B'){
				bibi++;
			}
		}
		if(lili == bibi){
			printf("None\n");
		} else if (lili > bibi){
			printf("Lili\n");
		} else {
			printf("Bibi\n");
		}
	}
}
