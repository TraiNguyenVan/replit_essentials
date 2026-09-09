#include <iostream>

using namespace std;

// swap
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
// Bubble sort
void BubbleSort(int A[], int n) {
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (A[j] > A[j + 1]) {
                swap(&A[j], &A[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
}

int main(int argc, char* argv[]) {
    int n, a[(int)1e6];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    BubbleSort(a, n);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
    return 0;
}