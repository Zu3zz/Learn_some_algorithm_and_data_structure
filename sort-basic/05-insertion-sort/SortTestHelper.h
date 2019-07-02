//
// created by 3zz.
//
#ifndef INC_03_SELECTION_SORT_GENERATE_TEST_CASES_SORTTESTHELPER_H
#define INC_03_SELECTION_SORT_GENERATE_TEST_CASES_SORTTESTHELPER_H

#include <iostream>
#include <ctime>
#include <cassert>
using namespace std;

namespace SortTestHelper
{
// 生成有n个元素的随机数组， 每个元素的随机范围为[rangeL, rangeR]
int *generateRandomArray(int n, int rangeL, int rangeR)
{
  assert(rangeL <= rangeR);
  int *arr = new int[n];
  srand(time(NULL));
  for (int i = 0; i < n; i++)
  {
    arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
  }
  return arr;
}

// 打印数组
template <typename T>
void printArray(T arr[], int n)
{
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
  return;
}

// 查看是否已经排序
template <typename T>
bool isSorted(T arr[], int n)
{
  for (int i = 0; i < n - 1; i++)
    if (arr[i] > arr[i + 1])
      return false;
  return true;
}

// 测试排序性能
template <typename T>
void testSort(string sortName, void (*sort)(T[], int), T arr[], int n)
{
  clock_t startTime = clock();
  sort(arr, n);
  clock_t endTime = clock();
  assert( isSorted(arr, n));
  cout << sortName << " : " << double(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
  return;
}

// 复制一个整形函数
int* copyIntArray(int a[], int n){
  int* arr = new int[n];
  copy(a,a + n, arr);
  return arr;
}
};     // namespace SortTestHelper
#endif //INC_03_SELECTION_SORT_GENERATE_TEST_CASES_SORTTESTHELPER_H