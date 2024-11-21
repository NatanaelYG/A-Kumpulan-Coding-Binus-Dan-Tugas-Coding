#include <stdio.h>
#include <string.h>

struct data{
    char nama[51];
    int usia;
};

void cetak(struct data mhs[], int count){
    int i;
    printf("Nama Usia\n");
    for(i = 0;i < count; i++){
        printf("%s %d\n", mhs[i].nama, mhs[i].usia);
    }
}

// void tukarData(struct data *mhs1[], struct data *mhs2[]){
//     struct data temp = *mhs1;
//     *mhs1 = *mhs2;
//     *mhs2 = temp;
// }

void bubble(struct data mhs[], int count){
    int i,j;
    for(i = 0;i < count;i++){
        for(j = count -1; j > i;j++){
            // if(mhs[j].usia > mhs[j-1].usia){
            if(strcmp(mhs[j].nama, mhs[j-1].nama) > 0){
                struct data temp = mhs[j];
                mhs[j] = mhs[j-1];
                mhs[j - 1] = temp;
                // tukardata(*mhs1[j-1], *mhs2[j]);
            }
        }
    }
}

int main(){
    int count = 5;
    struct data mhs[5] = {
        {"Agus", 70},
        {"Dedi", 52},
        {"Rudi", 36},
        {"Chandra", 12},
        {"Budi", 20},
    };
    printf("Data sebelum sort\n");
    cetak(mhs, count);

    bubble(mhs,count);

    printf("Data setelah sort\n");
    cetak(mhs, count);

    return 0;
}