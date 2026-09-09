#include "../include/insertionSort.hpp"

long long insertionSort(int a[], int n) {
    int counter = 0;
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            ++counter;
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
    return counter;
}
#include "../include/insertionSort.hpp"

long long insertionSort(int a[], int n) {
    int counter = 0;
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            ++counter;
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
    return counter;
}
#include "../include/insertionSort.hpp"

long long insertionSort(int a[], int n) {
    int counter = 0;
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            ++counter;
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
    return counter;
}
#include "../include/insertionSort.hpp"

long long insertionSort(int a[], int n) {
    int counter = 0;
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            ++counter;
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
    return counter;
}
