#include <stdio.h>
#include <string.h>

int main()
{
	int n, t;
	char s[105];
	int i, panjang, flag, titik;
	
	scanf("%d", &n); getchar();
	for(t = 1; t <= n;t++){
		gets(s);
		panjang = strlen(s);
		
		flag = 1;
		titik = 0;
		for(i = 0;i < panjang;i++){
				if(s[i] == '.'){
					if(s[i+1] == '.'){
						flag = 0;
						break;
					}
					else{
						titik++;
					}
				}
				else if(s[i] >= '0' && s[i] <= '9'){
					continue;
				}
			else {
				flag = 0;
				break;
			}
		}	
		
		if(flag == 0){
			printf("Case #%d: NO\n", t);
		} else {
			if(titik == 5){
				printf("Case #%d: YES\n", t);
			} else {
				printf("Case #%d: NO\n", t);
			}
		}
	}
	return 0;
}
