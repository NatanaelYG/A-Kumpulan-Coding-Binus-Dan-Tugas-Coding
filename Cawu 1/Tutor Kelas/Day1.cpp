#include <stdio.h>

int main() 
{	
	char nomorrekening[11];
	
	printf("Masukan Nomor Rekening : ");
	
	scanf("%[^10]", nomorrekening);
	getchar();
	printf("Nomor Rekening : %s", nomorrekening);
	
	float nominal;
	
	printf("\nMasukan Nominal : ");
	scanf("%f", &nominal);
	
	printf("Rp %.2f", nominal);
	
	return 0;
}
