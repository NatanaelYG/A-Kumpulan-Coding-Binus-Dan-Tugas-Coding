#include <stdio.h>
#include <string.h>
#include <stdbool.h>

    
bool isnumeric(char arr[], int start, int len){
    for(int i = start; i < len;i++){
        if(arr[i] < '0' || arr[i] > '9'){
            return false;
        }
    }
}

struct user{
    char role[12];
    char name[50];
    char email[50];
    int age;
    union{
        char student[11];
        char lecture[6];
    }id;
};

    struct user userlist[10];
    int usercount = 0;

void registeruser(){
    char name[50] = "";
    char role[12] = "";
    char email[50] = "";
    char lectid[6] = "";
    char studid[11] = "";
    int studlen = sizeof(studid)/sizeof(studid[0]);
    int lectlen = sizeof(lectid)/sizeof(lectid[0]);

    do {
        printf("Input Role (Student/Lecture): ");
        scanf("%s", &role); getchar();
    } while (strcmp(role,"Student") != 0 && strcmp(role, "Lecture") != 0);

    do {
        printf("Input Name: ");
        scanf("%[^\n]", &name); getchar();
    } while(strlen(name) == 0);

    do {
        printf("Input Email: ");
        scanf("%[^\n]", &email); getchar();
    } while(strlen(email) == 0);

    if(strcmp(role,"Student") == 0){
        do {
            printf("Input Student ID: ");
            scanf("%[^\n]", &studid); getchar();
        } while (strlen(studid) != 10 || isnumeric(studid, 0,studlen));
        strcpy(userlist[usercount].id.student,studid);
    } else {
        do {
            printf("Input Lecture ID: ");
            scanf("%[^\n]", &lectid); getchar();
        } while(strlen(lectid) != 5 || isnumeric(lectid,1,lectlen) || lectid[0] != 'D');
        strcpy(userlist[usercount].id.lecture,lectid);
    }
    strcpy(userlist[usercount].role, role);
    strcpy(userlist[usercount].name, name);
    strcpy(userlist[usercount].email, email);
    usercount++;
}

void showuser(){
    if(usercount == 0){
        printf("There are not user\n");
    } else {
        for(int i = 0;i < usercount;i++){
            if(strcmp(userlist[i].role, "Lecture") == 0)printf("%s %s %s %s\n", userlist[i].role, userlist[i].name, userlist[i].email, userlist[i].id.lecture);
            else printf("%s %s %s %s\n", userlist[i].role, userlist[i].name, userlist[i].email, userlist[i].id.student);
        }
    }
}

void hapuslayar(){
    int i;
    for(i = 0;i <= 50;i++){
        printf("\n");
    }
}

void mainmenu(){

    FILE *file = fopen("lab.in","r");
    int menu;
//  mode: write(w) - tulis, read(r) - baca, append(a) - tulis
    do{
    // hapuslayar();

    // struct user user1;
    // strcpy(user1.name,"Hansen");
    // strcpy(user1.email,"hansen.gunawan02@binus.ac.id");
    // user1.role;
    // user1.age;

    printf("Binary User Management\n");
    printf("======================\n");
    printf("1. Register new user\n");
    printf("2. Show all users\n");
    printf("3. Exit\n");
    printf("Chose >>");
    scanf("%d", &menu);
    printf("\n");

    switch(menu){
        case 1:
            // hapuslayar();
            registeruser();
            printf("\n");
            break;
        case 2:
            // hapuslayar();
            showuser();
            printf("\n");
            break;
    } 

    } while (menu != 3);
}

int main(){
    
    mainmenu();

    return 0;
}