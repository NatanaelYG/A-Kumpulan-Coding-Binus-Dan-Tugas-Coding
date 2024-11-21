#include <stdio.h>
#include <string.h>

void pilihmenu(int main);
void factorial();
void palindrome();
void GCD();
void bubble();

int main(){
    int menu;
    do{
        printf("\nrecursive functions\n");
        printf("====================\n");
        printf("1. factorial\n");
        printf("2. palindrome\n");
        printf("3. Greatest Common Divisor\n");
        printf("4. Bubble sort\n");
        printf("5. Exit\n");
        printf(">> ");
        scanf("%d",&menu); getchar();

        pilihmenu(menu);
    } while (menu != 5);
    return 0;
}

void pilihmenu(int menu){
    if (menu == 1){
        factorial();
    } else if (menu == 2){
        palindrome();
    } else if (menu == 3){
        GCD();
    } else if (menu == 4){
        bubble();
    } 
}

unsigned long long faktorial(int angka){
    if (angka == 1)return 1;
    return angka * faktorial(angka-1);
}

void factorial(){
    int angka;

    do {
        printf("input the number you want: ");
        scanf("%d",&angka); getchar();
        printf("the factorial of %d is %llu\n", angka, faktorial(angka));
        printf("press enter to continue...");
        getchar();
    } while (angka < 0);
}

int palindrome(char kata[], int panjang)
{
	int i,j;
    int valid = 0,cek;
    for (i = 0, j = panjang-1; i <= panjang - 1, j >= 0; i++ , j--){
        if (kata[i] == kata[j]) {
            valid = 1;
        } else {
            valid = 0;
            break;
        }
    }
    return valid;
}

void palindrome(){
    char kata[100];
    int i, panjang, palind;

    do{
        printf("input the string you want check: ");
        scanf("%s",&kata); getchar();

        panjang = strlen(kata);
        palind = palindrome(kata, panjang);

        if (palind == 1){
            printf("%s is a palindrome!\n", kata);
        } else if(palind == 0){
            printf("%s is not a palindrome!\n", kata);
        }
        
    } while (strlen(kata) <= 0);
    printf("press enter to continue...");
    getchar();
    printf("\n");
}

int gcd(int angka1,int angka2){
    int total = angka1 % angka2;
    if(total == 0){
        return angka2;
    } else {
        return gcd(angka2,total);
    }
}

void GCD(){
    int angka1,angka2,hasil,i;

    printf("input the 2 number you want to check\n");
    scanf("%d %d",&angka1,&angka2); getchar();
    
    hasil = gcd(angka1,angka2);
    
    printf("the GCD of %d and %d is %d\n",angka1,angka2, hasil);
    printf("press enter to continue...");
    getchar();
    printf("\n");
}

// void bubblesort(int input[], int size){
//     int i,j;
//     bool swapped;

//     for (i = 0; i < size; i++){
//         swapped = false;
//         for (j = 0; j < size - i;j++){
//             if(input[j] > input[j+1]){
//                 int temp = input[j];
//                 input[j] = input[j+1];
//                 input[j+1] = temp;
//                 swapped = true;
//             }
//         }
//         if (swapped == false){
//             break;
//         }
//     }
// }

void bubblesort(int input[],int size){
    for (int i = 0; i < size; i++){
        for(int j = 0; j < size - i - 1; j++){
            if (input[j] > input[j + 1]){
                int temp = input[j];
                input [j] = input[j + 1];
                input [j + 1] = temp;
            }
        }
    }
}

void bubble(){
    int size,i,j,input[100];
    
    printf("please input the array size: ");
    scanf("%d",&size); getchar();
    for(i = 0; i < size; i++){
        scanf("%d",&input[i]);
        getchar();
    }
    
    bubblesort(input,size);
    printf("here's your sorted array: ");
    for(i = 0; i < size; i++){
        printf("%d ",input[i]);
    }
    puts("");
}