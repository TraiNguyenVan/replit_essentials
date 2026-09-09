#include <cstddef>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

// Tri long an cutws
// record as int for simplicity
using Record = int;

// Merge for MergeSort
void mix(int a[], int left, int middle, int right) {
    int* temp = new int[right - left + 1];
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
    delete[] temp;
}

// Merge sort entry (aka divide/split)
void divide(int a[], int left, int right) {
    int middle = (left + right) / 2;
    if (left < right) {
        divide(a, left, middle);
        divide(a, middle + 1, right);
        mix(a, left, middle, right);
    }
}

int makeChunks(const string& inFile, size_t chunkRecords) {
    ifstream fi(inFile);
    Record* buffer = new Record[chunkRecords];
    int id = 0;
    Record r;
    while (fi) {
        size_t m = 0;
        while (m < chunkRecords && (fi >> r)) {
            buffer[m++] = r;
        }
        if (m == 0) {
            break;
        }
        if (m > 1) {
            divide(buffer, 0, (int)m - 1);
        }
        ofstream fo("chunk_" + to_string(id++) + ".txt");
    }
    delete[] buffer;
    return id;  // number of
}

void mergeChunks(int runs, const string& outfile, size_t pageRecords) {
    ifstream* ins = new ifstream[runs];
    Record** page = new Record*[runs];
    for (int i = 0; i < runs; i++) {
        page[i] = new Record[pageRecords];
    }
    size_t* pos = new size_t[runs]{};
    size_t* have = new size_t[runs]{};
    Record v;
    for (int i = 0; i < runs; i++) {
        ins[i].open("chunks_" + to_string(i) + ".txt");
        while (have[i] < pageRecords && ins[i] >> v) {
            page[i][have[i]++] = v;
        }
    }
    struct Node {
        Record val;
        int id;
        Node(Record v, int id) : val(v), id(id) {}
        bool operator>(const Node& o) const {
            return (val != o.val) ? (val > o.val) : (id > o.id);
        }
    };

    struct NodeCmp {
        bool operator()(const Node& a, const Node& b) const {
            return a > b;
        }
    };
}
int main(int argc, char* argv[]) {
    const string inputFile = (argc > 1) ? argv[0] : "transactions.txt";
    const string outputFile = (argc > 2) ? argv[1] : "sorted.txt";
    const size_t chunkRecords = 500UL * 1024 * 1024 / sizeof(Record);
    const size_t pageRecords = 1UL * 1024 * 1024 / sizeof(Record);

    return 0;
}