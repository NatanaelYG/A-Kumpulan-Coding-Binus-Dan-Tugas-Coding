#include <stdio.h>
#include <stdlib.h>

void menuSatu();
void menuDua();
void square();
void rectangle();
void triangle();

int main()
{
    system("cls");
	int menu;

    do {
        printf("Selection and Repetition\n");
        printf("========================\n");
        printf("1. Shape Arena Calculator\n");
        printf("2. Grade Calculator\n");
        printf("0. Exit\n");
        printf(">> ");
        scanf("%d", &menu);
        getchar();

        switch (menu)
        {
            case 1:
                menuSatu();
                break;
            case 2:
                menuDua();
    
                break;
            case 0:
                system("cls");
                printf("Wonderful things can be achieved when there's teamwork, hardwork, and perseverance - BlueJackets 22-2\n");
                printf("\n=======================\n");
                printf("Press enter to continue\n");
                getchar();
                break;
            default: 
                system("cls");
                printf("Menu Tidak Tersedia\n\n");
        }
        }
        while (menu != 0);
	
}

void menuSatu() {
    system("cls");
    int menu;
    do {
    printf("Shape Arena Calculator\n");
    printf("======================\n");
    printf("1. Square\n");
    printf("2. Rectangle\n");
    printf("3. Triangle\n");
    printf("0. Back\n");
    printf(">> ");
    scanf("%d", &menu);
    getchar();

    switch (menu)
    {
    case 1:
        square();
        break;
    case 2:
        rectangle();
        break;
    case 3:
        triangle();
        break;
    }
    }
    while (menu != 0);
    system("cls");
}

void square() {
    system("cls");
    double side;
    printf("Input Side: ", side);
    scanf("%lf", &side);
    getchar();
    printf("Square Area: %.2lf\n\n", side*side);

    printf("\n=======================\n");
    printf("Press enter to continue");
    getchar();
    getchar();
    system("cls");
}

void rectangle() {
    system("cls");
    double width, height;
    printf("Input Base: ", width);
    scanf("%lf", &width);
    getchar();
    printf("Input Height: ", height);
    scanf("%lf", &height);
    getchar();
    printf("Rectangle Area: %.2lf\n\n", width*height);

    printf("\n=======================\n");
    printf("Press enter to continue");
    getchar();
    getchar();
    system("cls");
}

void triangle() {
    system("cls");
    double base, height;
    printf("Input Base: ", base);
    scanf("%lf", &base);
    getchar();
    printf("Input Height: ", height);
    scanf("%lf", &height);
    getchar();
    printf("Triangle Area: %.2lf\n\n", (base*height)/2 );

    printf("\n=======================\n");
    printf("Press enter to continue");
    getchar();
    getchar();
    system("cls");
}

void menuDua() {
    system("cls");
    double math,english,history,art,score;
    printf("Enter Math Score [0.0 - 10.0]: ");
    scanf("%lf", &math);
    getchar();
    printf("Enter English Score [0.0 - 10.0]: ");
    scanf("%lf", &english);
    getchar();
    printf("Enter History Score [0.0 - 10.0]: ");
    scanf("%lf", &history);
    getchar();
    printf("Enter Art Score [0.0 - 10.0]: ");
    scanf("%lf", &art);
    getchar();

    system("cls");
    score = (math+english+history+art)/4;
    printf("Report Card\n");
    printf("===========\n");
    printf("Math: %.1lf\n", math);
    printf("English: %.1lf\n", english);
    printf("History: %.1lf\n",history);
    printf("Art: %.1lf\n",art);
    printf("Average: %.1lf \n", score);
    printf("Final Grade: ");

    if (score < 6){
        printf("F\n");
    } else if (score >= 6 && score < 7){
        printf("D\n");
    } else if (score >= 7 && score < 8){
        printf("C\n");
    } else if (score >= 8 && score < 9){
        printf("B\n");
    } else if (score >= 9 && score <= 10){
        printf("A\n");
    } 
    

    printf("\n\n=======================\n");
    printf("Press enter to continue");
    getchar();
    getchar();
    system("cls");
}