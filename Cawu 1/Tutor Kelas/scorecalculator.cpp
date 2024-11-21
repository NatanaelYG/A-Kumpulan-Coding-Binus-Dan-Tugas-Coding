#include <stdio.h>
#include <string.h>

int main()
{
    int input = -1;
    int counter = 0;
    char courseName[3][50];
    char courseCredit[10];
    char courseScore[100];

    do {
        printf("Score Calculator\n");
        printf("================\n");
        printf("1. Add Course\n");
        printf("2. Course List\n");
        printf("3. Update Course\n");
        printf("4. Delete Course\n");
        printf("5. Total GPA\n");
        printf("6. Exit\n");
        printf(">> ");
        scanf("%d", &input); getchar();
        switch (input) {
                char name[50];
                int score, credit;
                char conf;
            case 1:{
                if(counter < 3){
                    do {
                        printf("input course name: ");
                        scanf("%[^\n]", &name); getchar();
                    } while(strlen(name) <= 5);
                    do{
                        printf("input score credit: ");
                        scanf("%d", &credit); getchar();
                    } while(credit %2 != 0);
                    do {
                        printf("input course score: ");
                        scanf("%d", &score); getchar();
                    } while(score > 100);

                    do {
                        printf("input y to proceed or n to cancel: ");
                        scanf("%c", &conf); getchar();
                    } while(conf != 'y' && conf != 'n');

                    if (conf == 'y'){
                        strcpy(courseName[counter], name); 
                        courseCredit[counter] = credit;
                        courseScore[counter] = score;    
                        counter++;
                    } 
                    
                } else {
                    printf("counter has reached the limit\n");
                }
            }
                break;
            case 2:{
                for(int i = 0;i < counter;i++){
                    printf("%d %s %d %d\n",i+1,courseName[i], courseCredit[i], courseScore[i]);
                }
                break;
            }
            case 3:{
                char name[50];
                int score, credit;
                int idx = -9;
                for(int i = 0;i < counter;i++){
                    printf("%d %s %d %d\n",i+1,courseName[i], courseCredit[i], courseScore[i]);
                }
                do{
                printf("input the course index you want to update: ");
                scanf("%d", &idx);getchar();
                } while (idx > counter || idx < 1);
                do {
                        printf("input course name: ");
                        scanf("%[^\n]", &name); getchar();
                    } while(strlen(name) <= 5);
                    do{
                        printf("input score credit: ");
                        scanf("%d", &credit); getchar();
                    } while(credit %2 != 0);
                    do {
                        printf("input course score: ");
                        scanf("%d", &score); getchar();
                    } while(score > 100);
                strcpy(courseName[idx-1], name);
                courseCredit[idx-1] = credit;
                courseScore[idx-1] = score;
                break;
            }
            case 4:{
                int idx = -1;
                for(int i = 0;i < counter;i++){
                    printf("%d %s %d %d\n",i+1,courseName[i], courseCredit[i], courseScore[i]);
                }
                do{
                printf("input the course index you want to delete: ");
                scanf("%d", &idx); getchar();
                } while (idx > counter || idx < 0);

                for(int i = idx-1;i < counter;i++){
                    strcpy(courseName[i], courseName[i+1]);
                    courseCredit[i] = courseCredit[i+1];
                    courseScore[i] = courseScore[i+1];
                }
                counter--;
                break;
            }
            case 5:{
                float total = 0;
                for(int i = 0;i < counter;i++){
                    total += (courseScore[i]/20) * courseCredit[i] * 0.5;
                }
                printf("your total score is %f\n", total);
                break;
            }
        } 
    } while(input != 6);
}
