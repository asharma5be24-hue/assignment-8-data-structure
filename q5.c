#include <stdio.h>

void heapify(int a[], int n, int i) {
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && a[l] > a[largest]) largest = l;
    if (r < n && a[r] > a[largest]) largest = r;

    if (largest != i) {
        int t = a[i]; a[i] = a[largest]; a[largest] = t;
        heapify(a, n, largest);
    }
}

void heapsort(int a[], int n) {
    for (int i = n/2 - 1; i >= 0; i--)
        heapify(a, n, i);

    for (int i = n-1; i > 0; i--) {
        int t = a[0]; a[0] = a[i]; a[i] = t;
        heapify(a, i, 0);
    }
}

int main() {
    int a[] = {7, 2, 9, 1, 5};
    int n = 5;

    heapsort(a, n);

    for (int i = 0; i < n; i++) printf("%d ", a[i]);

    return 0;
}
