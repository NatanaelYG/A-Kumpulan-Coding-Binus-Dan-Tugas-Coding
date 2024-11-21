#include <stdio.h>

int main(){
	int i;
	char s[5];
	
	for(i = 0;i < 3;i++){
		scanf("%s", s);
		printf("%c\n", s[1]);
	}
	
	return 0;
}
