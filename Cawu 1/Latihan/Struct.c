#include <stdio.h>
#include <string.h>

struct msh{
	char nim[11];
	char nama[51];
	int usia;
	float IPK;
}msh1, LA11[35];

int B[10];

void hapusLayar(){
	int i;
	for(i = 0;i < 25;i++)printf("\n");
}

void menu(){
		printf("Menu\n");
		printf("1. Masukan data mahasiswa\n");
		printf("2. Lihat data\n");
		printf("3. Ubah data\n");
		printf("4. Delete\n");
		printf("5. Exit\n");
		printf("Pilihan = ");
}

void isiData(struct msh LA11[], int *count){
	printf("Masukan Nim = ");
	scanf("%s", LA11[*count].nim); getchar();
	
	printf("Masukan Nama = ");
	gets(LA11[*count].nama);
	
	printf("Masukan Usia = ");
	scanf("%d", &LA11[*count].usia);
	
	printf("Masukan IPK = ");
	scanf("%f", &LA11[*count].IPK);
	
	*count += 1;
}

void cetakData(struct msh LA11[], int count){
	int i;
		
		printf("Data Mahasiswa\n");
		printf("%2s %-12s %-30s %-5s %-5s\n", "No.","NIM", "NAMA", "USIA", "IPK");
		printf("=========================================================\n");
	
	for(i = 0;i < count;i++){
		printf("%-2d %-12s %-30s %4d %5.2f\n", 
		(i+1), LA11[i].nim, LA11[i].nama, LA11[i].usia, LA11[i].IPK);
	}
		printf("=========================================================\n");
}

void ubahData(struct msh LA11[], int index){
	printf("Masukan Nim = ");
	scanf("%s", LA11[index].nim); getchar();
	
	printf("Masukan Nama = ");
	gets(LA11[index].nama);
	
	printf("Masukan Usia = ");
	scanf("%d", &LA11[index].usia);
	
	printf("Masukan IPK = ");
	scanf("%f", &LA11[index].IPK);
}

void deleteData(struct msh LA11[], int index, int *count){
	int i;
	
	for(i = index; i < *count; i++){
		LA11[i] = LA11[i+1];
	}
	*count -= 1;
}

int main(){
	int pilihan, count = 0, indexchange;
	struct msh LA11[35];
	

	do{	
		hapusLayar();
		printf("Jumlah Mahasiswa = %d\n", count);
		menu();
		scanf("%d", &pilihan);
		
		switch(pilihan){
			case 1:
				if(count <= 35){
					isiData(LA11, &count);
				} else {
					printf("Kelas Sudah Penuh!");
					getchar();
				}
				break;
			case 2:
				if (count == 0){
					printf("Data tidak ada\n");
				} else {
					cetakData(LA11, count);
					printf("\n\nPress Enter To Continue!!!");
				} getchar();
				
				break;
			case 3:
				if (count == 0){
					printf("Data tidak ada\n");
				} else {
					cetakData(LA11, count);
					do {
						printf("Pilih Nomor Untuk Di Ubah [1..%d] : ", count);
						scanf("%d", &indexchange);
					} while (indexchange < 1 || indexchange > count);
					ubahData(LA11, indexchange-1);
				}
				break;
			case 4:
				if (count == 0){
					printf("Data tidak ada\n");
				} else {
					cetakData(LA11, count);
					do {
						printf("Pilih Nomor Delete [1..%d] : ", count);
						scanf("%d", &indexchange);
					} while (indexchange < 1 || indexchange > count);
					deleteData(LA11, indexchange-1, &count);
				}
				break;
		}
		
	} while (pilihan != 5);
	
	
//	struct msh msh2 = {"2700340989","Jack Volre", 17, 3.9};
//	strcpy(msh1.nim, "2700923423");
//	strcpy(msh1.nama, "Cornol Ralp");
//	msh1.usia = 19;
//	msh1.IPK = 3.92;
//	
//	
////	msh1 = msh2;
//	
//	printf("Nim = %s\n", msh1.nim);
//	printf("Nama = %s\n", msh1.nama);
//	printf("Usia = %d\n", msh1.usia);
//	printf("IPK = %.2f\n", msh1.IPK);
//	
//	printf("\n");
//	
//	printf("Nim = %s\n", msh2.nim);
//	printf("Nama = %s\n", msh2.nama);
//	printf("Usia = %d\n", msh2.usia);
//	printf("IPK = %.2f\n", msh2.IPK);
	
	
	return 0;
}
