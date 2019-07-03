//
// created by 3zz.
//
#include <iostream>
#include "SortTestHelper.h"
#include "MergeSort.h"
#include "InsertionSort.h"

using namespace std;

template <typename T>
// 未优化版本
void mergeSortBU_ori(T arr[], int n)
{
  for (int sz = 0; sz <= n; sz += sz)
    for (int i = 0; i + sz < n; i += sz + sz)
      // 对 arr[i...i+sz-1] 和 arr[i+sz...i+2*sz-1] 进行归并
      __merge(arr, i, i + sz - 1, min(i + sz + sz - 1, n - 1));
}

template <typename T>
void mergeSortBU(T arr[], int n)
{
  // Merge Sort Bottom Up 优化
  // 对于小数组, 使用插入排序优化
  for (int i = 0; i < n; i += 16)
    insertionSort(arr,i, min(i + 15, n - 1));
  for (int sz = 16; sz < n; sz += sz)
    for (int i = 0; i < n - sz; i += sz + sz)
      // 对于arr[mid]<=arr[mid+1]的情况，不进行merge
      if (arr[i + sz - 1] > arr[i + sz])
        __merge(arr, i, i + sz - 1, min(i + sz + sz - 1, n - 1));
}

int main()
{
  int n = 1000000;
  // 测试1 一般性测试
  cout << "Test for random array, size = " << n << ", random range [0, " << n << "]" << endl;
  int *arr1 = SortTestHelper::generateRandomArray(n, 0, n);
  int *arr2 = SortTestHelper::copyIntArray(arr1, n);

  SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
  SortTestHelper::testSort("Merge Sort Bottom Up", mergeSortBU, arr2, n);

  delete[] arr1;
  delete[] arr2;
  cout << endl;

  // 测试2 测试近乎有序的数组
  int swapTimes = 100;
  cout << "Test for nearly ordered array, size = " << n << ", swap time = " << swapTimes << endl;
  arr1 = SortTestHelper::generateNearlyOrderedArray(n, swapTimes);
  arr2 = SortTestHelper::copyIntArray(arr1, n);

  SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
  SortTestHelper::testSort("Merge Sort Bottom Up", mergeSortBU, arr2, n);

  delete[] arr1;
  delete[] arr2;

  return 0;
}
