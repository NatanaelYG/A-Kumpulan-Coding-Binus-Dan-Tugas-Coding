/*
    Ada 3 jenis stream
    1. Standard input stream    : input stream dari keyboard (stdin)
    2. Standard output stream   : stdout
    3. Standard error stream    : stderr

    Record  : kumpulan data-data(field) yang menjadi satu
    File    : kumpulan record-record yang menjadi satu

    FILE --> Alias struct

    3 Langkah menghubungkan antara source code dengan database
    1. Open Connection
    2. Manipulasi data: Baca / Tulis
    3. Close Connection

    Data sebelum mulai : 
    Data setelah selesai : END OF File
*/
#include <stdio.h>
#include <string.h>
struct data{
    char nama[5];
    int score;
};

void bacaFile(struct data highscore[], int *count){
    // 1. Open File, parameternya ada 2 : ("[file]", "[mode]");
    FILE *fin = fopen("tembak.vio", "r");

    // 2. Manipulasi data (baca/ tulis)

        // Cara Pengecekan End Of File yang pertama
        *count = 0;
        while(!feof(fin)){
            fscanf(fin, "%s %d\n", highscore[*count].nama, &highscore[*count].score);
            (*count)++;
        }
    // 3. Close File
    fclose(fin);
}

void cetakData(struct data highscore[], int count){
    int i;
    printf("%50s\n", "Highscore");
    printf("%50s\n", "=========");
    printf("No Nama Score\n");
    printf("=============\n");
    for (i = 0 ; i < count; i++){
        printf("%-2d %-4s %5d\n", (i+1), highscore[i].nama, highscore[i].score);
    }
}

void tulisFile(struct data highscore[], int count){
    int i;
    //1. Open File
    FILE *fout = fopen("tembak.vio", "w");

    //2. Manipulasi
    for (i = 0 ; i < count ; i++){
        fprintf(fout, "%s %d\n", highscore[i].nama, highscore[i].score);
    }

    //3. Close file
    fclose(fout);
}

int main(){
    struct data highscore[15];
    int count;
    int pilihan, i;
    char tempNama[5];
    int tempScore;

    bacaFile(highscore, &count);

    do{
        cetakData(highscore, count);
        for(i = 0; i < 21-count ; i++) printf("\n");
        printf("Menu\n");
        printf("1. Main Game\n");
        printf("2. Exit\n");
        scanf("%d", &pilihan); getchar();

        switch(pilihan){
            case 1:
                do{
                    printf("Masukkan nama Anda [3 char] = ");
                    scanf("%s", tempNama); getchar();
                } while (strlen(tempNama) != 3);

                do{
                    printf("Masukkan score Anda [1....99999] = ");
                    scanf("%d", &tempScore);
                } while (tempScore < 1 || tempScore > 99999);

                strcpy(highscore[count].nama, tempNama);
                highscore[count].score = tempScore;
                count++;

                tulisFile(highscore, count);
                break;
        }
    } while (pilihan != 2);
    
    return 0;
}