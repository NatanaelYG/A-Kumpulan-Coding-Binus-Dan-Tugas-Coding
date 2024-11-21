#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

typedef struct animal {
    char id[10];
    char name[30];
    int age;
    char habitat[10];
    int hungerbar;
    int height;
    struct animal *left, *right;
} node;

node *root = NULL;

node *createNode(char *id, char *name, int age, char *habitat, int hungerbar) {
    node *newNode = (node*)malloc(sizeof(node));
    strcpy(newNode->id, id);
    strcpy(newNode->name, name);
    strcpy(newNode->habitat, habitat);
    newNode->age = age;
    newNode->hungerbar = hungerbar;
    newNode->height = 1;
    newNode->left = newNode->right = NULL;

    return newNode;
}

int findMax(int a, int b) {
    return (a > b) ? a : b;
}

int getHeight(node *root) {
    return (root) ? root->height : 0;
}

int getBf(node *root) {
    return (root) ? getHeight(root->left) - getHeight(root->right) : 0;
}

void updateHeight(node *root) {
    root->height = findMax(getHeight(root->left), getHeight(root->right)) + 1;
}

node *leftRotate(node *root) {
    node *right = root->right;
    node *rightleft = right->left;

    root->right = rightleft;
    right->left = root;

    updateHeight(root);
    updateHeight(right);

    return right;
}

node *rightRotate(node *root) {
    node *left = root->left;
    node *leftright = left->right;

    root->left = leftright;
    left->right = root;

    updateHeight(root);
    updateHeight(left);

    return left;
}

node *balancing(node *root) {
    if (!root) return NULL;

    updateHeight(root);

    int bf = getBf(root);

    if (bf > 1) {
        if (getBf(root->left) < 0) root->left = leftRotate(root->left);
        root = rightRotate(root);
    } else if (bf < -1) {
        if (getBf(root->right) > 0) root->right = rightRotate(root->right);
        root = leftRotate(root);
    }

    return root;
}

node *insertion(char *id, char *name, int age, char *habitat, int hungerbar, node *root) {
    if (!root) return createNode(id, name, age, habitat, hungerbar);
    else if (strcmp(id, root->id) < 0) root->left = insertion(id, name, age, habitat, hungerbar, root->left);
    else if (strcmp(id, root->id) > 0) root->right = insertion(id, name, age, habitat, hungerbar, root->right);
    return balancing(root);
}

void printList(node *root) {
    if (root) {
        printf("%-10s | %-20s | %-5d | %-10s | %-10d\n", root->id, root->name, root->age, root->habitat, root->hungerbar);
        printList(root->left);
        printList(root->right);
    }
}

node *searching(char *id, node *root) {
    if (!root) return NULL;
    else if (strcmp(id, root->id) < 0) return searching(id, root->left);
    else if (strcmp(id, root->id) > 0) return searching(id, root->right);
    return root;
}

node *deletion(char *id, node *root) {
    if (!root) return NULL;
    if (strcmp(id, root->id) < 0) root->left = deletion(id, root->left);
    else if (strcmp(id, root->id) > 0) root->right = deletion(id, root->right);
    else {
        if (!root->left && !root->right) {
            free(root);
            return NULL;
        } else if (!root->left) {
            node *temp = root->right;
            free(root);
            return temp;
        } else if (!root->right) {
            node *temp = root->left;
            free(root);
            return temp;
        } else {
            node *temp = root->left;
            while (temp->right) temp = temp->right;
            strcpy(root->id, temp->id);
            strcpy(root->name, temp->name);
            strcpy(root->habitat, temp->habitat);
            root->age = temp->age;
            root->hungerbar = temp->hungerbar;
            root->left = deletion(temp->id, root->left);
        }
    }
    return balancing(root);
}

bool checkName(char *name) {
    int len = strlen(name);
    int countWord = 0;
    int x = 0;

    for (int i = 0; i < len; i++) {
        if (name[i] == ' ') {
            x = 0;
        } else if (x == 0) {
            x = 1;
            countWord++;
        }
    }
    return countWord >= 2;
}

bool checkUnique(node *root, char *name) {
    if (!root) return true;
    if (strcmp(name, root->name) == 0) return false;
    return checkUnique(root->left, name) && checkUnique(root->right, name);
}

bool checkHabitat(char *habitat) {
    return strcmp(habitat, "Land") == 0 || strcmp(habitat, "Air") == 0 || strcmp(habitat, "Sea") == 0;
}

int calculateHungerBar(int age) {
    return 100 - (age * 10);
}

void generateID(char *id, char *name) {
    int a = rand() % 10;
    int b = rand() % 10;
    int c = rand() % 10;
    sprintf(id, "%c%c%d%d%d", toupper(name[0]), toupper(name[1]),a,b,c);
}

void addAnimal() {
    char name[30];
    int age;
    char habitat[10];
    char id[10];
    int hungerbar;

    do {
        printf("Input Animal's Name (at least 2 words): ");
        scanf(" %[^\n]", name);
        getchar();
    } while (!checkName(name) || !checkUnique(root, name));

    do {
        printf("Input Animal's Age (more than 0): ");
        scanf("%d", &age);
        getchar();
    } while (age <= 0);

    do {
        printf("Input Animal's Habitat [Land, Air, Sea]: ");
        scanf(" %[^\n]", habitat);
        getchar();
    } while (!checkHabitat(habitat));

    hungerbar = calculateHungerBar(age);
    generateID(id, name);

    root = insertion(id, name, age, habitat, hungerbar, root);
}

void feedAnimal() {
    if (!root) {
        printf("No animals to feed.\n");
        return;
    }
    printList(root);

    char id[10];
    printf("Input Animal's ID to Feed: ");
    scanf(" %[^\n]", id);
    getchar();

    node *animal = searching(id, root);
    if (!animal) {
        printf("Animal not found.\n");
        return;
    }

    if (animal->hungerbar < 50) {
        animal->hungerbar = 100;
        printf("Animal fed successfully.\n");
    } else {
        printf("Animal's hungerbar is already sufficient.\n");
    }
}

void removeAnimal() {
    if (!root) {
        printf("No animals to remove.\n");
        return;
    }
    printList(root);

    char id[10];
    printf("Input Animal's ID to Remove: ");
    scanf(" %[^\n]", id);
    getchar();

    node *animal = searching(id, root);
    if (!animal) {
        printf("Animal not found.\n");
        return;
    }

    root = deletion(id, root);
    printf("Animal removed successfully.\n");
}

void mainMenu() {
    while (true) {
        int choice;

        printf("Animal List (printed in preorder)\n");
        printf("================================\n");
        printf("ID        | Name                 | Age  | Habitat  | Hungerbar\n");
        printf("--------------------------------------------------------------\n");
        printList(root);
        printf("\nMenu\n");
        printf("1. Insert New Animal\n");
        printf("2. View Animals\n");
        printf("3. Feed Animal\n");
        printf("4. Remove Animal\n");
        printf("5. Exit\n");
        printf("Input choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                addAnimal();
                break;
            case 2:
                printList(root);
                break;
            case 3:
                feedAnimal();
                break;
            case 4:
                removeAnimal();
                break;
            case 5:
                return;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

int main() {
    srand(time(NULL));
    mainMenu();
    return 0;
}
