#include <iostream>
#include <algorithm>
#include <ctime>
#include <cassert>
#include <vector>

using namespace std;

void shiftDown(int *arr, int parent, int k) {
    int child = 2 * parent + 1;
    while (child < k) {
        if (child + 1 < k && arr[child] > arr[child + 1]) {
            child++;
        }
        if (arr[parent] > arr[child]) {
            swap(arr[parent], arr[child]);
            parent = child;
            child = 2 * parent + 1;
        } else {
            break;
        }
    }
}


int *HeapSet(int *arr, int n, int k) {
    assert(arr);
    assert(k > 0);
    int *ret = new int[k];
    for (int i = 0; i < k; i++) {
        ret[i] = arr[i];
    }
    for (int i = (k - 2) / 2; i >= 0; i--) {
        shiftDown(ret, i, k);
    }
    for(int i = k;i<n;i++){
        if(ret[0] <arr[i]){
            ret[0] = arr[i];
            shiftDown(ret, 0, k);
        }
    }
    return ret;
}

void Print(int *arr, int k) {
    cout << "最多" << k << "个" << endl;
    for (int i = 0; i < k; i++)
        cout << arr[i] << endl;
    cout << endl;
}

void Test() {
    int arr[] = {21, 8, 1, 4, 7, 36, 45, 23, 5, 9, 12};
    int k = 5;
    int *ret = HeapSet(arr, sizeof(arr) / sizeof(arr[0]), k);
    Print(ret, k);
}

int main() {
    Test();
    return 0;
}