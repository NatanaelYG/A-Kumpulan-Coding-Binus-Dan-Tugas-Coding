#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

    // int i;
    // int floors = 15;
    // for(i = floors;i >= 1;i--){
    //     printf("%d\n", i);
    // }



void mainmenu(){
    int menu;
    int i,j,k,l;
    int floor = 1, player;
    int powerenemy = (floor*20) + ((rand() % 10) * floor);
    int zenn = 0, sword = 30, head = 0, chest = 0;
    int zen = 0;
    int power, harga;
    int senjata1 = 0, senjata2 = 1, senjata3 = 2;
    int jenis;
    // char barang[100] = {"sword","head","chest"};
    int choose;
    int cek = 0;

    do {
        // status(floor);
        // printf("\n");



        printf("Status (%d Zenn)\n", zenn + zen);
        zen = (floor*10) + (rand() % 31);
        printf("Sword - Power: %d\n", sword);
        printf("Head  - Power: %d\n", head);
        printf("Chest - Power: %d\n\n", chest);

        printf("Choose:\n");
        printf("1. Go Up\n");
        printf("2. Fight\n");
        printf("3. Shop\n");
        printf("4. Quit\n");
        printf("Choose: ");
        scanf("%d", &menu);
        printf("\n");

        switch(menu){
            case 1:
            if(cek == 1){
                printf("You Climb Up To Floor %d\n", floor);
                printf("Press Any Key to Continue..\n");
                getchar();
                getchar();
                cek = 0;
            } if(cek == 0){
                printf("You Must Fight the Boss Before You Can Go Up\n");
                printf("Press Any Key to Continue..\n");
                getchar();
                getchar();
            }
                break;
                
            case 2:

                printf("Player total Attack : %d\n", sword);
                printf("Enemy Total Attack  : %d\n\n", powerenemy);

                if(sword >= powerenemy){
                    printf("You Win!!!\n");
                    printf("You Get %d Zenn\n");
                    printf("Press Any Key to Continue..\n");
                    getchar();
                    getchar();
                } else {
                    printf("You Lose!!!\n");
                    printf("Game Over\n");
                }



                break;
            case 3:
                power = floor * (rand() % 50);
                harga = (power/10) * 30;
                jenis = (rand() % 2);
                

                    printf("Welcome to Shin Shop\n");
                    if (jenis == 0){
                        printf("We have a sword with Power %d. The cost %d Zenn\n",power,harga);
                    } else if (jenis == 1){
                        printf("We have a head with Power %d. The cost %d Zenn\n",power,harga);
                    } else if (jenis == 2){
                        printf("We have a chest with Power %d. The cost %d Zenn\n",power,harga);
                    }
                    
                    printf("1. Buy \n");
                    printf("2. Quit Shop\n");
                    printf("Choose : ");
                    scanf("%d", choose);
                    
                    switch(choose){
                        case 1:
                            printf("Thank you for Buying..\n");
                            printf("Please Come Back Again...\n");
                            printf("Press Any Key to Continue..\n");
                            getchar();
                            getchar();

                            break;
                        case 2:
                            printf("Please Come Back Again...\n");
                            printf("Press Any Key to Continue..\n");
                            getchar();
                            getchar();

                            break;
                    }
                    
        
        
                    
                


                break;
        }

    } while (menu != 4);

    
}

int main(){
    
    mainmenu();

    return 0;
}
