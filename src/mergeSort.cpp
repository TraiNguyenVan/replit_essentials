#ifndef MERGE_SORT_HPP
#define MERGE_SORT_HPP

#include "../include/mergeSort.hpp"
// merge
void mix(int a[], int left, int middle, int right) {
    int temp[right - left + 1];
    int i = left;
    int j = middle + 1;
    int k = 0;
    while (i <= middle && j <= right) {
        if (a[i] <= a[j]) {
            temp[k++] = a[i++];
        } else {
            temp[k++] = a[j++];
        }
    }
    while (i <= middle) {
        temp[k++] = a[i++];
    }
    while (j <= right) {
        temp[k++] = a[j++];
    }
    for (int x = left; x <= right; x++) {
        a[x] = temp[x - left];
    }
}

// split/divide
void divide(int a[], int left, int right) {
    int middle = (left + right) / 2;
    if (left < right) {
        divide(a, left, middle);
        divide(a, middle + 1, right);
        mix(a, left, middle, right);
    }
}
#endif