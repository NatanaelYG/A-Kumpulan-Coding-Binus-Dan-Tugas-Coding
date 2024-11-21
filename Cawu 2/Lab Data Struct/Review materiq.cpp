#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Mhs{
    char name[100];
    char nim[10];
    int umur;
};

int main(){

    // int a = 10;
    // int *b = &a;

    // printf("%d\n", a);
    // printf("%d\n", &a);
    // printf("%d\n", b);
    // printf("%d\n", *b);

    // *b = 50;
    // printf("%d\n\n", a);

    // int umur[100] = {10,15,12,20};

    // for(int i = 0;i < 4;i++){
    //     printf("%d\n", umur[i]);
    // }

    // int tinggi[5];
    // tinggi[0] = 10;
    // tinggi[2] = 15;
    // printf("%d\n", tinggi[2]);

    // char nama[10][100];
    // char nim[10][100];
    // int umur[10];

    // struct Mhs murid;
    // strcpy(murid.name, "BCA");
    // strcpy(murid.nim, "1234567890");
    // murid.umur = 20;

    // printf("%s\n", murid.name);
    // printf("%s\n", murid.nim);
    // printf("%d\n", murid.umur);

    // struct Mhs students[5];
    // students[0].umur = 19;
    // strcpy(students[2].name, "PPTI");

    // printf("%s\n", students[2].name);

    // struct Mhs *murid2 = (Mhs*)malloc(sizeof(Mhs));
    // murid2->umur = 19;
    // printf("%d\n", murid2->umur);

    Mhs sekolah[5];
	for(int i = 0 ; i < 5 ; i++){
		char nama[100] = "";
		printf("Mahasiswa ke-%d\n", i);
		puts("====================");
		
		printf("Input nama: ");
		scanf("%[^\n]", nama); getchar();
		strcpy(sekolah[i].name, nama);
		
		char nim[10] = "";
		printf("Input nim: ");
		scanf("%[^\n]",nim); getchar();
		strcpy(sekolah[i].nim, nim);
		
		int umur;
		printf("Input umur: ");
		scanf("%d", &umur); getchar();
		sekolah[i].umur = umur;
		puts("");
	}
	
	for(int i = 0 ; i < 5 ; i++){
		printf("Mahasiswa %d\n", i);
		puts("==================");
		printf("Nama	: %s\n", sekolah[i].name);
		printf("NIM	: %s\n", sekolah[i].nim);
		printf("Umur	: %d\n", sekolah[i].umur);
		puts("");
	}
	puts("");
    

    return 0;
}