#include <stdio.h>

int main() {
	int i, j;
	for(i = 0; i <= 20; i++){
		for(j = 0; j <= 20; j++) {
			if(i%2 == 0 || j%2 == 0) {
				printf("*");
			} else if(i%2 != 0 || j%2 != 0) {
				printf("#");
			}
		}
		printf("\n");
	}
}
