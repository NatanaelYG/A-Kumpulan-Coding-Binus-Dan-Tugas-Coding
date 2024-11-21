#include <stdio.h>
#include <string.h>

int main(){
	int i,j,k,l;
	int t;
	int n;
	char lorong[10005];
	int mati,tahanNapas,K,lantai,panjang;
	
	scanf("%d", &t);
		for(i = 1;i <= t;i++){
			scanf("%d %d", &n,&k);
			scanf("%s", &lorong);
			
			tahanNapas = 0;
			panjang = strlen(lorong);
			lantai = 1;//1 adalah di lantai 1,2 adalah di lantai 2
			for(j = panjang - K;j < panjang;j++){
				if(lorong[i] == '0'){
					tahanNapas++;
				}
				else if(lorong[i] == '1'){
					if(lantai == 1)lantai = 2;
				}
				if(lantai == 1) tahanNapas = 0;
				if(tahanNapas >= K && lantai == 1){
					mati = 1;
					break;
				}
			}
			if(mati == 0){
				printf("Case #%d: Alive\n",i);
			} else {
				printf("Case #%d: Dead\n",i);
			}
		}
	}

