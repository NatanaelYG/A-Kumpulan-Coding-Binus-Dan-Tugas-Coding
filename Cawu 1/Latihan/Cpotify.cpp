#include <stdio.h>
#include <string.h>

void menusatu();
void menudua();
void menutiga();

int hour,minute,second;
char name[100];
char singername[100];
int songduration;
int songcount;

int main(){
    int menu;
    do {
        printf("Cpotify\n");
        printf("=======\n");
        printf("Menu:\n");
        printf("1. Queue new song\n");
        printf("2. Show all queued songs\n");
        printf("3. Play next song\n");
        printf("4. Exit\n");
        printf(">> ");
        scanf("%d",&menu);

        switch(menu) {
            case 1:
                menusatu();
                break;
        }
    } while (menu != 4);
    return 0;
}

void menusatu(){

        do {
            printf("Song name: \n");
            scanf("%[^\n]", &name);
        } while (strlen(name) <= 5 || strlen(name) >= 100);
        
        do {
        printf("Singer name: \n");
        scanf("%[^\n]", &singername);
        } while (strlen(singername) <= 0);

        do {
        printf("Song duration: \n");
        scanf("%d", &songduration);
        } while (songduration < 0);
}

void menudua(){
        hour = songduration / 60*60;
        minute = songduration / 60;
        second = songduration % 60;

    if (songcount == 0){
            printf("No queue song...\n");
        } else {
            for (int i = 0; i < songcount; i++) {
        printf("Song ID: ");
        printf("Song Name: ", name);
        printf("Singer Name: ", singername);
        printf("Song Duration: %.02d:%.02d:%.02d", hour, minute, second);
            }
        }
    
}