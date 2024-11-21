#include <stdio.h>
#include <string.h>

typedef struct dataM{
    char merk[3];
    int size;
}mineral;

typedef struct dataC{
    char merk[3];
    char powder[31];
    int size;
}carbonated;

mineral water[100];
carbonated product[100];
int countMineral, countCarbonated;

void mainMenu(){
    printf("Menu :\n");
    printf("=============================\n");
    printf("1. Insert New\n");
    printf("2. Manage Products\n");
    printf("3. Insert New Carbonated\n");
    printf("4. Manage Carbonated Products\n");
    printf("5. Exit\n");
    printf("Choice : ");
}

void manageMenu(){
    printf("Manage Menu\n");
    printf("===========\n");
    printf("1. Edit\n");
    printf("2. Delete\n");
    printf("Choice : ");
}

void displayMineral(){
    int i;
    printf("Mineral Water\n");
    printf("=======================\n");
    printf("%-3s %-10s %-8s\n", "No.", "Merk", "Size");
    for(i = 0 ; i < countMineral ; i++){
        printf("%-3d %-10s %8d\n", i+1, water[i].merk, water[i].size);
    }
}

void displayCarbonated(){
    int i;
    printf("Carbonated Water\n");
    printf("=======================================\n");
    printf("%-3s %-10s %-15s %-8s\n", "No.", "Merk", "Powder", "Size");
    for(i = 0 ; i < countCarbonated ; i++){
        printf("%-3d %-10s %-15s %8d\n", i+1, product[i].merk, product[i].powder, product[i].size);
    }
}

void insertNew(){
    char tempMerk[3]; 
    int tempSize, i, isNew;
    printf("Mineral Water\n");
    printf("=======================\n");
    do{
        printf("Merk [2]? ");
        scanf("%s", tempMerk); getchar();
    } while(strlen(tempMerk) != 2);
    
    do{
        printf("Size [240/600/1500] ml? ");
        scanf("%d", &tempSize); getchar();
    } while(tempSize != 240 && tempSize != 600 && tempSize != 1500);

    isNew = 1;
    if(countMineral > 0){
        for(i = 0 ; i < countMineral ; i++){
            if((strcmp(water[i].merk, tempMerk) == 0) && water[i].size == tempSize){
                isNew = 0;
                printf("Sudah ada Minuman %s size %d ml\n", water[i].merk, water[i].size);
                getchar();
                break;
            }
        }
    }

    if(isNew == 1){
        strcpy(water[countMineral].merk, tempMerk);
        water[countMineral].size = tempSize;
        printf("Minuman %s %d ml berhasil ditambahkan!\n", water[countMineral].merk, water[countMineral].size);
        getchar();
        countMineral++;
    }
}

void insertNewCarbonated(){
    char tempMerk[3], tempPowder[31]; 
    int tempSize, i, isNew;
    printf("Carbonated Water\n");
    printf("=======================\n");
    do{
        printf("Merk [2]? ");
        scanf("%s", tempMerk); getchar();
    } while(strlen(tempMerk) != 2);
    
    do{
        printf("Size [240/600/1500] ml? ");
        scanf("%d", &tempSize); getchar();
    } while(tempSize != 240 && tempSize != 600 && tempSize != 1500);

    do{
        printf("Carbonated Powder [2..30] ? ");
        scanf("%s", tempPowder); getchar();
    } while((strlen(tempPowder) < 2) || (strlen(tempPowder) > 30));

    isNew = 1;
    if(countCarbonated > 0){
        for(i = 0 ; i < countCarbonated ; i++){
            if((strcmp(product[i].merk, tempMerk) == 0) && product[i].size == tempSize){
                isNew = 0;
                printf("Sudah ada Minuman %s size %d ml berkarbonasi %s\n", product[i].merk, product[i].size, product[i].powder);
                getchar();
                break;
            }
        }
    }

    if(isNew == 1){
        strcpy(product[countCarbonated].merk, tempMerk);
        strcpy(product[countCarbonated].powder, tempPowder);
        product[countCarbonated].size = tempSize;
        printf("Minuman %s berkarbonasi %s %d ml berhasil ditambahkan!\n", product[countCarbonated].merk, product[countCarbonated].powder, product[countCarbonated].size);
        getchar();
        countCarbonated++;
    }
}

int main(){
    countMineral = 0;
    countCarbonated = 0;
    int mainChoice = -1;
    int manageWaterChoice = -1, manageCarbonatedChoice = -1;
    int editW, deleteW, editC, deleteC, i;
    do{
        printf("%50s\n", "Juragan Air");
        printf("\n\n");
        displayMineral();
        printf("\n\n");
        mainMenu();
        scanf("%d", &mainChoice); getchar();

        switch(mainChoice){
            case 1:{
                insertNew();
                break;
            }
            case 2:{
                displayMineral();
                printf("\n\n");
                if(countMineral == 0){
                    printf("Tidak ada data!\n");
                    getchar();
                }
                else{
                    manageMenu();
                    scanf("%d", &manageWaterChoice); getchar();
                    if(manageWaterChoice == 1){
                        do{
                            printf("Product mana yang anda mau edit [1..%d] ?", countMineral);
                            scanf("%d", &editW); getchar();
                        } while(editW < 1 || editW > countMineral);
                        do{
                            printf("Merk [2]? ");
                            scanf("%s", water[editW-1].merk); getchar();
                        } while(strlen(water[editW-1].merk) != 2);
                        
                        do{
                            printf("Size [240/600/1500] ml? ");
                            scanf("%d", &water[editW-1].size); getchar();
                        } while(water[editW-1].size != 240 && water[editW-1].size != 600 && water[editW-1].size != 1500);
                        printf("Minuman menjadi %s %d ml berhasil!\n", water[editW-1].merk, water[editW-1].size);
                        getchar();
                    }
                    else if(manageWaterChoice == 2){
                        do{
                            printf("Product mana yang anda mau delete [1..%d] ?", countMineral);
                            scanf("%d", &deleteW); getchar();
                        } while(deleteW < 1 || deleteW > countMineral);
                        for(i = deleteW-1 ; i <countMineral ; i++){
                            water[i] = water[i+1];
                        }
                        printf("Berhasil dihapus!\n");
                        getchar();
                        countMineral--;
                    }
                }
                break;
            }
            case 3:{
                displayCarbonated();
                printf("\n\n");
                insertNewCarbonated();
                break;
            }
            case 4:{
                displayCarbonated();
                printf("\n\n");
                if (countCarbonated == 0){
                    printf("Tidak ada data!\n");
                    getchar();
                }
                else{
                    manageMenu();
                    scanf("%d", &manageCarbonatedChoice); getchar();
                    if(manageCarbonatedChoice == 1){
                        do{
                            printf("Product mana yang anda mau edit [1..%d] ?", countCarbonated);
                            scanf("%d", &editC); getchar();
                        } while(editC < 1 || editC > countCarbonated);

                        do{
                            printf("Merk [2]? ");
                            scanf("%s", product[editC-1].merk); getchar();
                        } while(strlen(product[editC-1].merk) != 2);

                        do{
                            printf("Size [240/600/1500] ml? ");
                            scanf("%d", &product[editC-1].size); getchar();
                        } while(product[editC-1].size != 240 && product[editC-1].size != 600 && product[editC-1].size != 1500);

                        do{
                            printf("Carbonated Powder [2..30] ? ");
                            scanf("%s", product[editC-1].powder); getchar();
                        } while((strlen(product[editC-1].powder) < 2) || (strlen(product[editC-1].powder) > 30));

                        printf("Minuman menjadi %s berkarbonasi %s %d ml berhasil!\n", product[editC-1].merk, product[editC-1].powder, product[editC-1].size);
                        getchar();
                    }
                    else if(manageCarbonatedChoice == 2){
                        do{
                            printf("Product mana yang anda mau delete [1..%d] ?", countCarbonated);
                            scanf("%d", &deleteC); getchar();
                        } while(deleteC < 1 || deleteC > countCarbonated);
                        for(i = deleteC-1 ; i <countCarbonated ; i++){
                            product[i] = product[i+1];
                        }
                        printf("Berhasil dihapus!\n");
                        getchar();
                        countCarbonated--;
                    }
                }
                break;
            }
        }
    } while(mainChoice != 5);
}