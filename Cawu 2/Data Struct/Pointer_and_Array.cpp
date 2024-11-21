#include <stdio.h>
#include <stdlib.h>

// int main(){
    
//     int a = 10;
//     int* ptr =  &a;
//     int* node = ptr;
//     int** d_ptr = &ptr;

//     printf("%d\n", d_ptr);
//     printf("%d\n", ptr);
// }

// void increment(int* a){
//     *a =  *a + 1; 
// }

// main() {
//     int a = 10;

//     increment(&a);

//     printf("Incremented value : %d", a);
//     return 0;
// }

// int main(){
//     int Arr[5] = {2, 4, 6, 8, 10};
//     printf("Manual access : %d\n", Arr[0]);

//     int* ptr = Arr;

//     printf("Single pointer will lead ti Arr[0] : %d\n", *ptr);

//     printf("Increments the Arr[0] : %d\n", *ptr+1);
    
//     printf("Index move : %d\n", *(ptr+1));

//     printf("Address move : %d\n", ptr+1);

//     printf("\n");

//     char Array[5] = {'g', 'o', 'o', 'd', 's'};

//     printf("Access string as unity : %s\n", Array);
//     printf("Increment single character : %c\n", *Array+1);
// }

struct Person {
    char name[50];
    int age;
};

int main() {
    printf("Size of struct Person: %lu bytes\n", sizeof(struct Person));

    struct Person* person1 = (struct Person*)malloc(sizeof(struct Person));
    struct Person* person2 = (struct Person*)malloc(sizeof(struct Person));

    snprintf(person1->name, sizeof(person1->name), "David");
    person1->age = 30;

    snprintf(person2->name, sizeof(person2->name), "Jack");
    person2->age = 25;

    printf("Person 1\n");
    printf("Name : %s\n", person1->name);
    printf("Age : %d\n", person1->age);

    printf("\n");

    printf("Person 2\n");
    printf("Name : %s\n", person2->name);
    printf("Age : %d\n",  person2->age);

    free(person1);
    free(person2);
}