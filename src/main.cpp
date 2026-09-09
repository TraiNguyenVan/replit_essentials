#include <iomanip>
#include <iostream>

using namespace std;

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

int main(int argc, char* argv[]) {
    int n, a[(int)1e6];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    long long empirical = insertionSort(a, n);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
    double worst = (double)n * (n - 1) / 2.0;
    double avg = (double)n * n / 4.0;
    double ratio = empirical / avg;

    cout << "Empirical comparisons = " << empirical << "\n";
    cout << "Theoretical worst n(n-1)/2 = " << (long long)worst << "\n";
    cout << "Theoretical avg n^2/4 = " << (long long)avg << "\n";
    cout << fixed << setprecision(4) << "Ratio (empirical/avg) = " << ratio << "\n";
    return 0;
}