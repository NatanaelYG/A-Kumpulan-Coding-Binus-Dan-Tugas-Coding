#include <stdio.h>
#include <string.h>
#include <stdlib.h>

union Userid{
    char phonenumber[13];
    char companyname[256];
};

struct User {
    char role[9];
    char name[256];
    char email[256];
    union Userid userid;
};

struct User users[100];
int usersLenght = 0;

int compareusers(struct User user1, struct User user2){
    int rolecomperresult = strcmp(user1.role, user2.role);

    if(rolecomperresult != 0){
        return rolecomperresult;
    }

    if (strcmp(user1.role, "Contact") == 0){
        return strcmp(user1.userid.phonenumber, user2.userid.companyname);
    } else if (strcmp(user1.role, "Business") == 0){
        return strcmp(user1.userid.phonenumber, user2.userid.companyname);
    } 
}

void merge(int l,int r,int mid){
    int leftarrlenght = mid - l + 1;
    struct User leftarr[leftarrlenght];

    for(int i = l,j = 0;i <= mid; i++,j++){
        leftarr[j] = users[i];
    }

    int rightarrlenght = r - mid;
    struct User rightarr[rightarrlenght];

    for(int i = mid + 1,j = 0;i <= r; i++,j++){
        rightarr[j] = users[i];
    }

    int leftarridx = 0;
    int rightarridx = 0;
    int combinedarridx = l;

    while (leftarridx < leftarrlenght && rightarridx < rightarrlenght){
        if(compareusers(leftarr[leftarridx], rightarr[rightarridx]) < 0){
            users[combinedarridx] = leftarr[leftarridx];
            combinedarridx++;
            leftarridx++;
        } else {
            users[combinedarridx] = rightarr[rightarridx];
            combinedarridx++;
            rightarridx++;
        }
    }

    while (leftarridx < leftarrlenght){
        users[combinedarridx] = leftarr[leftarridx];

            combinedarridx++;
            leftarridx++;
    } 
    
    while (rightarridx < rightarrlenght){
        users[combinedarridx] = rightarr[rightarridx];

            combinedarridx++;
            rightarridx++;
    } 
}

void mergesort(int l, int r){
    if (l >= r) return;

    int mid = l + (r - l) / 2;

    mergesort(l, mid);
    mergesort(mid+1, r);

    merge(l, r, mid);
}

void readFile(){
    FILE *file = fopen("users.txt","r");

    struct User role,name,email;

    if (file == NULL){
        return;
    }

    while (!feof(file)){
        fscanf(file,"%[^#]#%[^#]#%[^#]#", users[usersLenght].role , users[usersLenght].name, users[usersLenght].email);

        if(strcmp(users[usersLenght].role, "Contact") == 0){
            fscanf(file, "%[^\n]\n", users[usersLenght].userid.phonenumber);
        } else if(strcmp(users[usersLenght].role, "Business") == 0){
            fscanf(file, "%[^\n]\n", users[usersLenght].userid.companyname);
        }
        usersLenght++;
    }
    fclose(file);
}

void showusers(){
    printf("===========================================================================\n");
    printf("Role       Name            Email                     Phone or Name Company\n");
    printf("===========================================================================\n");

    for (int i = 0;i < usersLenght;i++){
        printf("%-10s %-15s %-25s", users[i].role, users[i].name, users[i].email);

        if(strcmp(users[i].role, "Contact") == 0){
            printf(" %-35s\n", users[i].userid.phonenumber);
        }   else if(strcmp(users[i].role, "Business") == 0){
            printf(" %-35s\n", users[i].userid.companyname);
        }
    }
    printf("===========================================================================\n");
}

void searchUsers(){
    if(usersLenght == 0){
        printf("There are no data\n");
        return;
    } else {
        char search[256];
        printf("Input Name To Search: ");
        scanf("%[^\n]", search); getchar();

        int low = 0;
        int high = usersLenght - 1;
        int foundIdx = -1;
        while(low <= high){
            int mid = (low + high)/2;
            if(strcmp(users[mid].name, search) == 0){
                foundIdx = mid;
                break;
            } else if(strcmp(users[mid].name, search) < 0){
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        if(foundIdx != -1){
            printf("User Found!\n");
            printf("Role   : %s\n", users[foundIdx].role);
            printf("Name   : %s\n", users[foundIdx].name);
            printf("Email  : %s\n", users[foundIdx].email);
            if(strcmp(users[foundIdx].role, "Contact") == 0){
            printf("ID     : %s\n", users[foundIdx].userid.phonenumber);
            }   else if(strcmp(users[foundIdx].role, "Business") == 0){
            printf("ID     : %s\n", users[foundIdx].userid.companyname);
            }
        } else {
            printf("User With The Name %s, Not Found!\n", search);
        }
    }
}

void registerUser(){
    char role[9];
    char name[256];
    char email[256];
    char phoneNumber[13];
    char companyName[256];

    printf("Input Role: ");
    scanf("%s", &role); getchar();

    printf("Input Name: ");
    scanf("%s", &name); getchar();
    
    printf("Input Email: ");
    scanf("%s", &email); getchar();

    if(strcmp(role, "Business") == 0){
        printf("Input Company Name : ");
        scanf("%s", &companyName); getchar();
        strcpy(users[usersLenght].userid.companyname, companyName);
    } else {
        printf("Input Phone Number : ");
        scanf("%s", &phoneNumber); getchar();
        strcpy(users[usersLenght].userid.phonenumber, phoneNumber);
    }

    strcpy(users[usersLenght].name, name);
    strcpy(users[usersLenght].email, email);
    strcpy(users[usersLenght].role, role);
    usersLenght++;
}

void writeData(){
    FILE *file = fopen("users.txt","w");

    if(file == NULL){
        printf("Error Opening File\n");
        return;
    } else {
        for(int i = 0;i < usersLenght; i++){
            fprintf(file, "%s#%s#%s#", users[i].role, users[i].name, users[i].email);
            if(strcmp(users[i].role, "Business") == 0){
            fprintf(file, "%s\n", &users[i].userid.companyname);
        } else {
            fprintf(file, "%s\n", &users[i].userid.phonenumber); 
    }

        }
        fclose(file);
    }
}

void hapusLayar(){
    for(int i = 0;i < 50; i++){
        printf("\n");
    }
}

void mainMenu(){
    int opt = -9;

    do {
        printf("PhoneBook Version 0.2\n");
        printf("=====================\n");
        printf("1. Register\n");
        printf("2. Show All User\n");
        printf("3. Search User\n");
        printf("4. Save To File And Exit\n");
        printf(">> ");
        scanf("%d", &opt); getchar();
        
        switch(opt) {
            case 1:
                hapusLayar();
                registerUser();
                break;
            case 2:
                hapusLayar();
                showusers();
                break;
            case 3:
                hapusLayar();
                searchUsers();
                break;
        }
    } while(opt != 4);
    writeData();
}

int main(){
    // readFile();
    // mergesort(0, usersLenght - 1);
    // showusers();
    // searchUsers();
    mainMenu();
}