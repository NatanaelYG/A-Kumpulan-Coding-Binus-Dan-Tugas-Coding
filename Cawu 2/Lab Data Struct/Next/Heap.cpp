#include<stdio.h>

#define SIZE 50

int data[SIZE];
int counter = 1;

//Swap
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

//Insert
void insert(int newData){
    int current = counter;
    data[current] = newData;

    while(current != 1){
        int parent = current/2;

        if(data[parent] >= data[current]) break;
        swap(&data[current], &data[parent]);
        current = parent;
    }
    counter++;
    printf("Insert Success for %d\n", newData);
}

void view(){
    printf("Data : ");
    for(int i = 1; i < counter; i++){
        printf("%d ", data[i]);
    }
    printf("\n");
}

//pop
void pop(){
    if(counter == 1){
        printf("Data is empty!\n");
        return;
    }

    int current = 1,left,right;
    counter--;
    swap(&data[1], &data[counter]);

    // kondisi ketika current minimal punya anak kiri
    while(current * 2 < counter){
        left = current * 2;
        right = current * 2 + 1;

        if(data[left] > data[current]){
            // kondisi ketika value anak kana paling gede
            if(right < counter && data[right] > data[left]){
                swap(&data[current], &data[right]);
                current = right;
            } else {
                swap(&data[current], &data[left]);
                current = left;
            }
            // kondisi ketika anak kiri < current, maka cek anak kanan
        } else if (right < counter && data[right] > data[current]){
            swap(&data[current], &data[right]);
            current = right;
        }
        else break;
    }

    printf("Pop Success!\n");
    return;
}

// Heapify
void heapify(int arr[], int size, int index){
    int largest = index;
    int left = index * 2;
    int right = index * 2 + 1;

    if(left <= size && arr[left] > arr[largest]) largest = left;
    if(right <= size && arr[right] > arr[largest]) largest = right;
    if(largest != index){
        swap(&arr[largest], &arr[index]);
        heapify(arr, size, largest);
    }
}

//HeapSort
void heapsort(int arr[], int size){
    // Membuat array mentahnya, menjadi sebuah heap tree
    for(int i = size/2; i >= 1; i--){
        heapify(arr, size, i);
    }

    // Melakukan sort pada arraynya
    for(int i = size; i > 1; i--){
        swap(&arr[1], &arr[i]);
        heapify(arr, i-1, 1);
    }

}

int main(){

    // insert(6);
    // insert(9);
    // insert(1);
    // insert(10);
    // insert(3);
    // insert(13);
    // insert(2);

    // pop();
    // pop();
    // pop();

    int arr[] = {6, 9, 1, 10, 3, 13, 2};
    heapsort(arr, 7);
    
    for(int i = 1; i < 7; i++){
        printf("%d ", arr[i]);
    }

    // view();

    return 0;
}
