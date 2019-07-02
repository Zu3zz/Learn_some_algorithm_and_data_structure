//
// created by 3zz.
//
#include <iostream>
#include "SortTestHelper.h"
#include "InsertionSort.h"

using namespace std;

// 将arr[l...mid]和arr[mid+1...r]两部分进行归并
template <typename T>
void __merge(T arr[], int l, int mid, int r)
{
  // 定义一个额外空间用来存储数据
  T aux[r - l + 1];
  // T *aux = new T[r - l + 1];
  for (int i = l; i <= r; i++)
  {
    aux[i - l] = arr[i];
  }
  // 将i,j分别指向两个数组开头的位置
  int i = l, j = mid + 1;
  for (int k = l; k <= r; k++)
  {
    // 如果此时第一个数组全部取完了 i已经大于mid说明后面一个数组[mid+1...r]还没取完 取它的元素即可
    if (i > mid)
    {
      arr[k] = aux[j - l];
      j++;
    } // // 如果此时第二个数组全部取完了 j已经大于r 说明第一个数组[l...mid]还没取完 取它的元素即可
    else if (j > r)
    {
      arr[k] = aux[i - l];
      i++;
    } // 后面两个是正常判断谁小就取谁的
    else if (aux[i - l] < aux[j - l])
    {
      arr[k] = aux[i - l];
      i++;
    }
    else
    {
      arr[k] = aux[j - l];
      j++;
    }
  }
  // delete[] aux;
}

template <typename T>
void __mergeSort(T arr[], int l, int r)
{
  if (l >= r)
    return;
  int mid = l + (r - l) / 2;
  __mergeSort(arr, l, mid);
  __mergeSort(arr, mid + 1, r);
  __merge(arr, l, mid, r);
}

template <typename T>
void mergeSort(T arr[], int n)
{
  __mergeSort(arr, 0, n - 1);
}

// 比较InsertionSort和MergeSort两种排序算法的性能效率
// 整体而言, MergeSort的性能最优, 对于近乎有序的数组的特殊情况, 见测试2的详细注释
int main()
{

  // Merge Sort是我们学习的第一个O(nlogn)复杂度的算法
  // 可以在1秒之内轻松处理100万数量级的数据
  // 注意：不要轻易尝试使用SelectionSort, InsertionSort或者BubbleSort处理100万级的数据
  // 否则，你就见识了O(n^2)的算法和O(nlogn)算法的本质差异：）
  int n = 50000;

  // 测试1 一般性测试
  cout << "Test for random array, size = " << n << ", random range [0, " << n << "]" << endl;
  int *arr1 = SortTestHelper::generateRandomArray(n, 0, n);
  int *arr2 = SortTestHelper::copyIntArray(arr1, n);

  SortTestHelper::testSort("Insertion Sort", insertionSort, arr1, n);
  SortTestHelper::testSort("Merge Sort", mergeSort, arr2, n);

  delete[] arr1;
  delete[] arr2;

  cout << endl;

  // 测试2 测试近乎有序的数组
  // 对于近乎有序的数组, 数组越有序, InsertionSort的时间性能越趋近于O(n)
  // 所以可以尝试, 当swapTimes比较大时, MergeSort更快
  // 但是当swapTimes小到一定程度, InsertionSort变得比MergeSort快
  int swapTimes = 10;
  assert(swapTimes >= 0);

  cout << "Test for nearly ordered array, size = " << n << ", swap time = " << swapTimes << endl;
  arr1 = SortTestHelper::generateNearlyOrderedArray(n, swapTimes);
  arr2 = SortTestHelper::copyIntArray(arr1, n);

  SortTestHelper::testSort("Insertion Sort", insertionSort, arr1, n);
  SortTestHelper::testSort("Merge Sort", mergeSort, arr2, n);

  delete[] arr1;
  delete[] arr2;

  return 0;
}