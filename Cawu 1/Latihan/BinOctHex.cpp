#include <stdio.h>

void con(long long int angka,long long int mode){
    long long int remainder, satuan = 0;
    char hasil[10000] = "";
    long long int proses,i;

    proses = angka;
    while(proses != 0){
        remainder = proses % mode; // mod 10 untuk Binary decimal, 8 untuk octal

        if(mode == 16 && remainder == 10) hasil[satuan] = 'A';
        else if(mode == 16 && remainder == 11) hasil[satuan] = 'B';
        else if(mode == 16 && remainder == 12) hasil[satuan] = 'C';
        else if(mode == 16 && remainder == 13) hasil[satuan] = 'D';
        else if(mode == 16 && remainder == 14) hasil[satuan] = 'E';
        else if(mode == 16 && remainder == 15) hasil[satuan] = 'F';
        else hasil[satuan] = 'G';

        hasil[satuan] = remainder + '0';
        // printf("%lld %lld %lld %c\n", proses, remainder, satuan, hasil[satuan]);

        // hasil = hasil + remainder * satuan;
        proses = proses/ mode; //Bagi 10 untuk binary decimal, 8 untuk octal
        satuan++;
        // satuan = satuan * 10;
    }
    printf("Hasil Convert %d = ", mode);
    for(i = satuan; i >= 0;i--){
        printf("%c", hasil[i]);
    } printf("\n");
}

int main(){
    long long int angka;

    scanf("%lld", &angka);
    con(angka,2);
    con(angka,8);
    con(angka,10);
    con(angka,16);
    con(angka,12);
    

    return 0;
}