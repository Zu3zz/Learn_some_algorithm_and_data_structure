#include <iostream>
#include "SortTestHelper.h"
#include "SelectionSort.h"

using namespace std;

template <typename T>
void insertionSort(T arr[], int n)
{
  for (int i = 1; i < n; i++)
  {
    // 寻找元素arr[i]合适的插入位置
    for (int j = i; j > 0 && arr[j] < arr[j - 1]; j--)
        swap(arr[j], arr[j - 1]);
  }
}

int main()
{
  // 测试排序算法辅助函数
  int N = 10000;
  int *arr = SortTestHelper::generateRandomArray(N, 0, N);
  int *arr2 = SortTestHelper::copyIntArray(arr, N);
  SortTestHelper::testSort("Selection Sort", selectionSort, arr, N);
  SortTestHelper::testSort("Insertion Sort", insertionSort, arr, N);
  delete[] arr;
  delete[] arr2;
  return 0;
}
