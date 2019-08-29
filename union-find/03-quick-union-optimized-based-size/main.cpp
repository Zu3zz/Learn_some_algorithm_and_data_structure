#include <iostream>
#include <cassert>

using namespace std;

namespace UF3{
  class UnionFind{
  private:
    int* parent;
    int* sz; // sz[i]表示以i为根的集合中元素的个数
    int count;
  public:
    UnionFind(int count){
      parent = new int[count];
      this->count = count;
      for(int i = 0; i < count; i++){
        parent[i] = i;
        sz[i] = 1;
      }
    }
    ~UnionFind(){
      delete [] parent;
      delete [] sz;
    }
    int find(int q){
      assert(q >= 0 && q < count);
      while(q != parent[q]){
        q = parent[q];
      }
      return q;
    }
    bool isConnected(int q, int p){
      return find(q) == find(p);
    }
    void unionElements(int q, int p){
      int qRoot = find(q);
      int pRoot = find(p);
      if(qRoot == pRoot)
        return;
      if(sz[qRoot] < sz[pRoot]){
        parent[qRoot] = pRoot;
        sz[pRoot] += sz[qRoot];
      } else {
        parent[pRoot] = qRoot;
        sz[qRoot] += sz[pRoot];
      }
    }
  };
}