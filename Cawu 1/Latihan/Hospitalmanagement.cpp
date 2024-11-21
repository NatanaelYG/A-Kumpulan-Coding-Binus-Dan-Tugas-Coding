#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void hapusLayar(){
    for(int i = 0;i < 80;i++){
        printf("\n");
    }
}

struct User{
    char username[1000];
    int age;
    char status[1000];
    char id[1000];
};

struct User user[100];

int people = 0;

void readFile(){
    FILE *fin = fopen("myData.txt", "r");
    if(people == 0){
        printf("Tidak Ada Data");
    } 
    while(!feof(fin)){
        scanf("%[^#]#%[^#]#%[^#]#%[^\n]\n", user[people].username, user[people].age, user[people].status, user[people].id);
    }
    fclose(fin);
}

void addUser(){

    do {
        printf("Input Age: ");
        scanf("%d", &user[people].age);
    } while (user[people].age <= 0);

    do {
        printf("Input User Name : ");
        scanf("%s", user[people].username); getchar();
    } while (strlen(user[people].username) <= 2);

    do {
        printf("Input Status [Heal / Sick] : ");
        scanf("%s", user[people].status);
    } while(strcmp(user[people].status,"Heal") != 0 && strcmp(user[people].status,"Sick") != 0);
    people++;

}

void showuser(){
    printf("\n");
    for(int i = 0;i < people;i++){
        printf("%d %s %s\n", user[i].age, user[i].username, user[i].status);
    }
}

void mainMenu(){
    int choose;

    do {
        // hapusLayar();
        printf("1. Add New User\n");
        printf("2. Show User\n");
        printf("3. Sort/restore\n");
        printf("4. Copy data\n");
        printf("5. Delete data\n");
        printf("6. Exit and save file\n");
        printf("Choose >>");
        scanf("%d", &choose);

        switch (choose)
        {
        case 1:
            addUser();
            break;
        case 2:
            showuser();
            break;
        case 3: 
        
            break;
        case 4: 
        
            break;
        case 5:
        
            break;
        case 6:

            break;
        }
    } while (choose != 6);
}


int main(){
    mainMenu();
}