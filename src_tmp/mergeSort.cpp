#include <chrono>
#include <iostream>
using namespace std;

template <typename F>
double timeIt(F f) {
    double best = 1e18;
    for (int i = 0; i < 5; i++) {
        auto t0 = chrono::high_resolution_clock::now();
        f();
        auto t1 = chrono::high_resolution_clock::now();
        best = min(best, chrono::duration<double, milli>(t1 - t0).count());
    }
    return best;
}

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

int main(int argc, char* argv[]) {
    int n, a[(int)1e6];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    double time = timeIt([&]() { divide(a, 0, n - 1); });
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
    cout << "MergeSort: " << time << " ms\n";
    return 0;
}
