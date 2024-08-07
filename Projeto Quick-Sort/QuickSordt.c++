#include <iostream>
using namespace std;

int partition(int *a, int start, int end) {
    int pivot = a[end];
    int partitionIndex = start;

    for(int i = start; i < end; i++) {
        if(a[i] <= pivot) {
            swap(a[i], a[partitionIndex]);
            partitionIndex++;
        }
    }
    swap(a[partitionIndex], a[end]);
    return partitionIndex;
}

void quickSort(int *a, int start, int end) {
    if(start < end) {
        int partitionIndex = partition(a, start, end);
        quickSort(a, start, partitionIndex - 1);
        quickSort(a, partitionIndex + 1, end);
    }
}

void print(int t, int *a) {
    for(int i = 0; i < t; ++i) {
        cout << "Elemento " << i << " = " << a[i] << endl;
    }
    cout << "----------------" << endl;    
}

int main(int argc, char** argv) {
    int v[8] = {49, 38, 58, 87, 34, 93, 26, 13};
    print(8, v);
    quickSort(v, 0, 7);
    print(8, v);
    
    return 0;
}