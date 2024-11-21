#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int main()
{
	int menu;
    srand(time(NULL));
    char songnames[100][256];
    char singernames[100][256];
    int songdurations[100];
    char songids[100][20];

    int songcount = 0;

    char songname[256] = "";
    char singername[256] = "";
    int songduration = 0;

    char songid[20];

    int hours;
    int minutes;
    int seconds;

    // variable untuk menyatakan lagu yang diputar sekarang
    char currentsongname[256] = "";
    char currentsingername[256] = "";
    char currentsongid[20] = "";
    int currentsongduration = 0;

	do {
	printf("Cpotify\n");
	printf("=======\n");
    if (strlen(currentsongname) == 0){
        printf("Current played song: -\n");
    } else {
        int hour = currentsongduration / (60 * 60);
        int minute = currentsongduration / 60 % 60;
        int second = currentsongduration % 60;
        printf("Current played song: [%s] %s - %s (%02d:%02d:%02d)\n", currentsongid,currentsongname,currentsingername,hour,minute,second);
    }
	printf("Menu:\n");
	printf("1. Queue new song\n");
	printf("2. Show all queued songs\n");
	printf("3. Play next song\n");
	printf("4. Exit\n");
	printf(">> ");
	scanf("%d", &menu); getchar();
	
    if(menu == 1){
        do {
        printf("Song name: ");
        scanf("%[^\n]", &songname); getchar();
        } while (strlen(songname) <= 5 || strlen(songname) >= 100);

        do {
        printf("Singer name: ");
        scanf("%[^\n]", &singername); getchar();
        } while (strlen(singername) == 0);

        do {
        printf("Song duration: ");
        scanf("%d", &songduration); getchar();
        } while (songduration <= 0);

        // generate ID
        // SNG-[Durasi]-[random 3 angka]
        bool isduplicate = false;

        do {
        sprintf(songid, "SNG-%d-%03d", songduration, rand() % 1000);

        for(int index = 0; index < songcount; index++){
            if (strcmp(songid, songids[index])== 0){
                    isduplicate = true;
                    break;
                } else {
                    isduplicate = false;
                }
            }
        } while (isduplicate);

        // insert to array
        strcpy(songnames[songcount], songname);
        strcpy(singernames[songcount],singername);
        strcpy(songids[songcount], songid);
        songdurations[songcount] = songduration;

        songcount++;

    } else if(menu == 2){
        if (songcount == 0){
            printf("No queue song...\n");
        } else {
            for(int index = 0; index < songcount; index++){
                // convert dari detik ke jam:menit:detik

                minutes = songdurations[index] / 60;
                hours = minutes / 60;
                minutes = minutes % 60;
                seconds = songdurations[index] % 60;

                printf("SongID: %s\n", songids[index]);
                printf("Song Name: %s\n", songnames[index]);
                printf("Singer Name: %s\n", singernames[index]);
                printf("Song Duration: %.02d:%.02d:%.02d\n\n", hours,minutes,seconds);
            }
        }
        
    } else if(menu == 3){
        //play next song (ada deletnya)
        // kalau tidak ada lagu sama sekali
        if (songcount == 0){
            strcpy(currentsongname, "");
            strcpy(currentsingername, "");
            strcpy(currentsongid, "");
            currentsongduration = 0;
        } else {
            strcpy(currentsongname, songnames[0]);
            strcpy(currentsingername, singernames[0]);
            strcpy(currentsongid, songids[0]);
            currentsongduration = songdurations[0];


            // copy index 0 ke 1 variable yang lain (current song)
            // delete index 0
            for(int index = 1; index < songcount; index++){
            strcpy(songnames[index -1], songnames[index]);
            strcpy(songids[index - 1], songids[index]);
            strcpy(singernames[index - 1], singernames[index]);
            songdurations[index - 1] = songdurations[index];
            
            }
            songcount--;
        }
    }
	} while (menu != 4);
	return 0;
}
