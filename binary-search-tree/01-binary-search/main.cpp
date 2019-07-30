#include <iostream>

using namespace std;

template <typename T>

int binarySearch(T arr[], int n, T target)
{
  // 在arr[l...r]之间查找target
  int l = 0, r = n - 1;
  while (l <= r)
  {
    int mid = (r - l) / 2 + l;
    if (arr[mid] == target)
      return mid;
    if (target < arr[mid])
      // 在arr[l...mid-1]之间查找target
      r = mid - 1;
    else // target > arr[mid]
      // 在arr[mid+1...r]之中查找target
      l = mid + 1;
  }
  return -1;
}