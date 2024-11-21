#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {
	int jammasuk, jamkeluar, total;
	int satujampertamamobil = 6000;
	int satujampertamamotor = 4000;
	int selanjutnyamobil = 4000;
	int selanjutnyamotor = 2000;
	int maxsatuharimobil = 200000;
	int maxsatuharimotor = 150000;
	int hitung;
	int totaljam;
	char kendaraan[100];
	
	printf("Kendaraan : ");
	scanf("%s", kendaraan);
	strlwr(kendaraan);
	
	printf("\nMasuk Jam : " );
	scanf("%d", &jammasuk);
	
	printf("\nKeluar Jam : ");
	scanf("%d", &jamkeluar);
	
	if (jammasuk > jamkeluar){
		totaljam = jamkeluar + (24 - jammasuk);
	} else {
		totaljam = jammasuk - jamkeluar;
	}

	hitung = fabs(totaljam);
	
	if (strcmp(kendaraan, "mobil") == 0){
	if(hitung == 1) {
		printf("%d", satujampertamamobil);
	} else if (hitung > 1 && hitung < 24) {
		total = (satujampertamamobil + ((hitung - 1) * selanjutnyamobil));
		printf("%d", total);
	} else if (hitung == 0) {
		printf("%d", maxsatuharimobil);
	}
}
	if (strcmp(kendaraan, "motor") == 0){
	if(jamkeluar == 1) {
		printf("%d", satujampertamamotor);
	} else if (hitung > 1 && hitung < 24) {
		total = (satujampertamamotor + ((hitung - 1) * selanjutnyamotor));
		printf("%d", total);
	} else if (hitung == 0) {
		printf("%d", maxsatuharimotor);
	}else{
		printf ("Unknown Error Occurred");
	}
}
		return 0;
}



