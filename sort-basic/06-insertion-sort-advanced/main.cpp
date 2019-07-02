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
    T e = arr[i];
    int j; // j保存元素e应该插入的位置
    for (j = i; j > 0 && arr[j-1] > e; j--)
      arr[j] = arr[j-1];
    arr[j] = e;
  }
}

int main()
{
  // 测试排序算法辅助函数
  int N = 10000;
  int *arr = SortTestHelper::generateNearlyOrderedArray(N, 10);
  int *arr2 = SortTestHelper::copyIntArray(arr, N);
  SortTestHelper::testSort("Selection Sort", selectionSort, arr, N);
  SortTestHelper::testSort("Insertion Sort", insertionSort, arr, N);
  delete[] arr;
  delete[] arr2;
  return 0;
}
