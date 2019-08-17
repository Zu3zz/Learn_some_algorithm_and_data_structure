#include <iostream>
#include <algorithm>
#include <cassert>

using namespace std;

template <typename Item>

class MaxHeap{
private:
  Item *data;
  int count;
  int capacity;
  void shiftUp(int k){
    while(k > 1 && data[k/2] < data[k]){
      swap(data[k/2], data[k]);
      k/=2;
    }
  }
public:
  MaxHeap(int capicity){
    data = new Item[capacity + 1];
    count = 0;
    this->capacity = capacity;
  }
  ~MaxHeap(){
    delete[] data;
  }
  int size(){
    return count;
  }
  void isEmpty(){
    return count == 0;
  }
  int insert(Item item){
    assert(count + 1 <= capacity)
    data[count+1] = item;
    count++;
    shiftUp(count);
  }
};

int main(){
  return 0;
}