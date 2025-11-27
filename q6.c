#include <stdio.h>

int heap[100];
int size = 0;

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void insert(int x) {
    heap[size] = x;
    int i = size;
    size++;

    while (i > 0 && heap[(i-1)/2] < heap[i]) {
        swap(&heap[i], &heap[(i-1)/2]);
        i = (i-1)/2;
    }
}

int getMax() {
    if (size == 0) return -1;
    return heap[0];
}

int deleteMax() {
    if (size == 0) return -1;

    int max = heap[0];
    heap[0] = heap[size-1];
    size--;

    int i = 0;
    while (1) {
        int left = 2*i + 1;
        int right = 2*i + 2;
        int largest = i;

        if (left < size && heap[left] > heap[largest]) largest = left;
        if (right < size && heap[right] > heap[largest]) largest = right;

        if (largest == i) break;

        swap(&heap[i], &heap[largest]);
        i = largest;
    }
    return max;
}

int main() {
    insert(40);
    insert(20);
    insert(60);
    insert(10);
    insert(50);

    printf("Max Element: %d\n", getMax());

    printf("Deleted: %d\n", deleteMax());
    printf("Deleted: %d\n", deleteMax());

    printf("Max Now: %d\n", getMax());

    return 0;
}
