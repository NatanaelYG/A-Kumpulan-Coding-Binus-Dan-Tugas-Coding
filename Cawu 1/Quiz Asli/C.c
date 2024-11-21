#include <stdio.h>
#include <string.h>

int main(){
	int i,j,k,l;
	int T,N;
    char input[100];
    int cek;
	
	scanf("%d", &T);
	for (i = 1;i <= T;i++)
	{
		scanf("%d", &N);
		{
			for(j = 1;j <= N;j++)
			{
				scanf("%s", &input[j]);
			}
            
            if(strcmp(input,input) == 1){
                    cek += 1;
                    printf("Case #%d: %d\n", i,cek);
                } else {
                    printf("Case #%d: 0\n",i);
                }
		}
        
	}
}