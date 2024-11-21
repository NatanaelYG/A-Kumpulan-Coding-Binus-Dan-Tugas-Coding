#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


struct ramal{
    char nama[100];
    int lucky;
};


void cetak(struct ramal pelanggan[],int count){
    int i;
    printf("No. %-50s %5s\n", "nama", "lucky");
    for(i = 0;i < count;i++){
        printf("%-3d %-50s %5d%%\n",i+1, pelanggan[i].nama, pelanggan[i].lucky);
    }
}

int main(){
    struct ramal pelanggan[100], temp;
    char menu[51];
    char tempnama[51];
    int templucky, index, indexsisip;
    srand(time(NULL));
    int count = 0,i;

    do{
        cetak(pelanggan, count);
        for(i = 0;i < 25-count;i++)printf("\n");
        do {
            printf("[add/delete/copy/exit] : ");
            gets(menu);

            if((strcmp(menu, "add") != 0 && 
                strcmp(menu, "delete") != 0 && 
                strcmp(menu, "copy") != 0 && 
                strcmp(menu, "exit") != 0))
                printf("Menu Not Valid!!!\n");

        } while(strcmp(menu,"add") != 0 && 
                strcmp(menu,"delete") != 0 &&
                strcmp(menu,"copy") != 0 &&
                strcmp(menu,"exit") != 0);

        if(strcmp(menu,"add") == 0){
            printf("Masukkan nama Anda [3..50]:");
            gets(tempnama);

            templucky = rand() % 101;

            strcpy(pelanggan[count].nama, tempnama);
            pelanggan[count].lucky = templucky;
            count++;
        } 

        else if(strcmp(menu,"delete") == 0){
            if(count == 0) printf("Belum ada data\n");
            else {
                cetak(pelanggan,count);
                do {
                    printf("\n\nMau delet nomor brp [1..%d] : ",count);
                    scanf("%d", &index); getchar();
                } while(index < 1 || index > count);

                for(i = index-1;i < count;i++){
                    pelanggan[i] = pelanggan[i+1];
                }
                index--;
                count--;
            }
        } 
        else if(strcmp(menu,"copy") == 0){
            if(count == 0) printf("Belum ada data\n");
            else {
                cetak(pelanggan,count);
                do {
                    printf("\n\nMau copy nomor brp [1..%d] : ",count);
                    scanf("%d", &index); getchar();
                } while(index < 1 || index > count);

                do {
                    printf("\n\nMau di sisip nomor brp [1..%d] : ",count);
                    scanf("%d", &indexsisip); getchar();
                } while(indexsisip < 1 || indexsisip > count);
                
                count++;
                temp = pelanggan[index-1];

                for(i = count-1;i >= indexsisip-1;i--){
                    pelanggan[i] = pelanggan[i-1];
                }
                pelanggan[indexsisip-1] = temp;
                pelanggan[indexsisip-1].lucky = rand() % 101;

            }
        } 
        
    } while(strcmp(menu,"exit") != 0);
}