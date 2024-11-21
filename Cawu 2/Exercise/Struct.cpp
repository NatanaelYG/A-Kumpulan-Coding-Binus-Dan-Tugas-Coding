#include <stdio.h>
#include <stdlib.h>

struct Item {
    char name[50];
    int value;
};

struct Character {
    char name[100];
    int health;
    int damage;
};

int main(){
    
    struct Character* player1 = (struct Character*)malloc(sizeof(struct Character));
    struct Item* item1 = (struct Item*)malloc(sizeof(struct Item*));
    struct Character* enemy1 = (struct Character*)malloc(sizeof(struct Character*));
    struct Item* item2 = (struct Item*)malloc(sizeof(struct Item*));

    printf("Player: ");
    scanf("%[^\n]", player1->name); getchar();
    printf("Health: ");
    scanf("%d", &player1->health); getchar();
    printf("Damage: ");
    scanf("%d", &player1->damage); getchar();

    printf("\n");

    printf("Enemy: ");
    scanf("%[^\n]", enemy1->name); getchar();
    printf("Health: ");
    scanf("%d", &enemy1->health); getchar();
    printf("Damage: ");
    scanf("%d", &enemy1->damage); getchar();

    printf("\n");

    printf("Items:\n");
    printf("Name: ");
    scanf("%[^\n]", item1->name); getchar();
    printf("Value: ");
    scanf("%d", &item1->value); getchar();

    printf("\n");

    printf("Name: ");
    scanf("%[^\n]", item2->name); getchar();
    printf("Value: ");
    scanf("%d", &item2->value); getchar();

    printf("\n");

    printf("Character List:\n");
    printf("Name: %s\n", player1->name);
    printf("Health: %d\n", player1->health);
    printf("Damage: %d\n", player1->damage);

    printf("\n");

    printf("Name: %s\n", enemy1->name);
    printf("Health: %d\n", enemy1->health);
    printf("Damage: %d\n", enemy1->damage);
    printf("\n");

    printf("Item List:\n");
    printf("Name: %s\n", item1->name);
    printf("Value: %d\n", item1->value);

    printf("\n");

    printf("Name: %s\n", item2->name);
    printf("Value: %d\n", item2->value);

    free(player1);
    free(enemy1);
    free(item1);
    free(item2);

    return 0;
}