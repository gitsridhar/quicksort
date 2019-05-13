#include <stdio.h>

void swap(int *left, int *right) {
    int temp = *left;
    *left = *right;
    *right = temp;
}

int partition(int data[], int low, int high) {
    int pivot = data[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if(data[j] <= pivot) {
            i++;
            swap(&data[i], &data[j]);
        }
    }
    swap(&data[i+1], &data[high]);
    return (i + 1);
}

void quicksort(int data[], int low, int high) {
    if (low < high) {
        int pi = partition(data, low, high);
        quicksort(data, low, pi-1);
        quicksort(data, pi+1, high);
    }
}

int main() {
    int data[] = {1,9,2,8,3,7,4,6,5};
    quicksort(data, 0, (sizeof(data)/sizeof(data[0]))-1);
    for (int i=0; i<(sizeof(data)/sizeof(data[0])); i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
    return 0;
}
