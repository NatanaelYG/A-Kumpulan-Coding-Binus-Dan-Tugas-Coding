#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

typedef struct patient {
    int id;
    char name[30];
    int age;
    char status[30];
    int height;
    struct patient *left, *right;
} node;
node *root = NULL;

int id_counter = -1;

node *createNode(int id, char *name, int age, char *status) {
    node *newNode = (node*)malloc(sizeof(node));
    strcpy(newNode->name, name);
    strcpy(newNode->status, status);
    newNode->id = id;
    newNode->age = age;
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

node *searching(int id, node *root) {
    if (!root) return NULL;
    else if (id < root->id) return searching(id, root->left);
    else if (id > root->id) return searching(id, root->right);
    return root;
}

node *insertion(int id, char *name, int age, char *status, node *root) {
    if (!root) return createNode(id, name, age, status);
    else if (id < root->id) root->left = insertion(id, name, age, status, root->left);
    else if (id > root->id) root->right = insertion(id, name, age, status, root->right);
    return balancing(root);
}

void printList(node *root) {
    if (root) {
        printList(root->left);
        printf("Patient: %d, Name: %s, Age: %d, Status: %s\n", root->id, root->name, root->age, root->status);
        printList(root->right);
    }
}


node *deletion(int id, node *root) {
    if (!root) return NULL;
    if (id < root->id) root->left = deletion(id, root->left);
    else if (id > root->id) root->right = deletion(id, root->right);
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
            root->id = temp->id;
            strcpy(root->name, temp->name);
            strcpy(root->status, temp->status);
            root->age = temp->age;
            root->left = deletion(temp->id, root->left);
        }
    }
    return balancing(root);
}

void urgentPatient(node *root) {
    if (root) {
        urgentPatient(root->right);
        if (strcmp(root->status, "Urgent") == 0) {
            printf("Patient: %d, Name: %s, Age: %d, Status: %s\n", root->id, root->name, root->age, root->status);
        }
        urgentPatient(root->left);
    }
}

bool checkName(char *name) {
    int len = strlen(name);
    return len >= 2 && len <= 30;
}

bool checkStatus(char *status) {
    return strcmp(status, "Urgent") == 0 || strcmp(status, "Ok") == 0;
}

void addPatient() {
    char name[30];
    char status[30];
    int age;

    do {
        printf("Input Name: ");
        scanf("%[^\n]", name);
        getchar();
    } while (!checkName(name));

    do {
        printf("Input Age: ");
        scanf("%d", &age);
        getchar();
    } while (age <= 0);

    do {
        printf("Input Status [Urgent, Ok]: ");
        scanf("%s", status);
        getchar();
    } while (!checkStatus(status));

    id_counter++;

    root = insertion(id_counter, name, age, status, root);
}

void searchData() {
    if (!root) {
        printf("No Data!!!\n");
        return;
    }

    printList(root);

    int id;
    printf("Input ID: ");
    scanf("%d", &id);
    getchar();

    node *patient = searching(id, root);
    if (patient) {
        printf("Patient found: ID: %d, Name: %s, Age: %d, Status: %s\n", patient->id, patient->name, patient->age, patient->status);
    } else {
        printf("Patient with ID %d not found.\n", id);
    }
}

void deleteData() {
    if (!root) {
        printf("No Data to remove\n");
        return;
    }

    printList(root);

    int id;
    printf("Input Patient ID: ");
    scanf("%d", &id);
    getchar();

    node *patient = searching(id, root);
    if (!patient) {
        printf("Patient not found.\n");
        return;
    }

    root = deletion(id, root);
    printf("Patient data removed successfully.\n");
}

void editData() {
    printList(root);
    int id;
    printf("Input ID: ");
    scanf("%d", &id);
    getchar();

    node *key = searching(id, root);
    if (!key) {
        printf("ID not found.\n");
        return;
    }

    char status[30];
    do {
        printf("Input new Status [Urgent, Ok]: ");
        scanf("%s", status);
        getchar();
    } while (!checkStatus(status));

    strcpy(key->status, status);
}

void mainMenu() {
    while (true) {
        int choice;

        printf("\n========================\n");
        printf("Data Patient in Hospital\n");
        printf("========================\n");
        printf("1. Add patient\n");
        printf("2. List of all patient\n");
        printf("3. Urgent patient\n");
        printf("4. Search patient\n");
        printf("5. Edit patient data\n");
        printf("6. Delete data\n");
        printf("7. Exit\n");
        printf("Input choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                addPatient();
                break;
            case 2:
                printList(root);
                break;
            case 3:
                urgentPatient(root);
                break;
            case 4:
                searchData();
                break;
            case 5:
                editData();
                break;
            case 6:
                deleteData();
                break;
            case 7:
                return;
            default:
                printf("Menu Tidak Tersedia\n");
        }
    }
}

int main() {
    mainMenu();
    return 0;
}
