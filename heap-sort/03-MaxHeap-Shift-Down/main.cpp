//
// created by 3zz.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <ctime>
#include <cmath>
#include <cassert>

using namespace std;

template <typename Item>
class MaxHeap
{
private:
  Item *data;
  int count;
  int capacity;

  void shiftUP(int k)
  {
    while (k > 1 && data[k / 2] < data[k])
    {
      swap(data[k / 2], data[k]);
      k /= 2;
    }
  }
  void shiftDown(int k)
  {
    while (2 * k <= count)
    {
      int j = 2 * k; //
      if (j + 1 <= count && data[j + 1] > data[j])
        j += 1;
      if (data[k] >= data[j])
        break;
      swap(data[k], data[j]);
      k = j;
    }
  }

public:
  // 构造函数, 构造一个空堆, 可容纳capacity个元素
  MaxHeap(int capacity)
  {
    data = new Item[capacity + 1];
    count = 0;
    this->capacity = capacity;
  }

  ~MaxHeap()
  {
    delete[] data;
  }

  int size()
  {
    return count;
  }

  // 返回一个布尔值, 表示堆中是否为空
  bool isEmpty()
  {
    return count == 0;
  }

  // 向最大堆中插入一个新的元素 item
  void insert(Item item)
  {
    assert(count + 1 <= capacity);
    data[count + 1] = item;
    count++;
    shiftUP(count);
  }
  Item extractMax()
  {
    assert(count > 0);
    Item ret = data[1];
    swap(data[1], data[count]);
    count--;
    shiftDown(1);
    return ret;
  }
};

// 测试最大堆
int main()
{
  MaxHeap<int> maxheap = MaxHeap<int>(100);
  srand(time(NULL));
  int n = 100; // 随机生成n个元素放入最大堆中
  for (int i = 0; i < n; i++)
  {
    maxheap.insert(rand() % 100);
  }

  int *arr = new int[n];
  // 将maxheap中的数据逐渐使用extractMax取出来
  // 取出来的顺序应该是按照从大到小的顺序取出来的
  for (int i = 0; i < n; i++)
  {
    arr[i] = maxheap.extractMax();
    cout << arr[i] << " ";
  }
  cout << endl;
  // 确保arr数组是从大到小排列的
  for (int i = 1; i < n; i++)
    assert(arr[i - 1] >= arr[i]);
  delete[] arr;
  return 0;
}