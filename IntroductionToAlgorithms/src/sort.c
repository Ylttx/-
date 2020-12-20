#include "sort.h"

void insertion_sort(int* A, int n) {
    int j;

    for (j = 1; j < n; j++) {
        int key = A[j];
        int i = j - 1;

        while (i >= 0 && A[i] > key) {
            A[i + 1] = A[i];
            i--;
        }
        A[i + 1] = key;
    }
}

void insertion_down_sort(int* A, int n) {
    int j;

    for (j = 1; j < n; j++) {
        int key = A[j];
        int i = j - 1;

        while (i >= 0 && A[i] < key) {
            A[i + 1] = A[i];
            i--;
        }
        A[i + 1] = key;
    }
}
