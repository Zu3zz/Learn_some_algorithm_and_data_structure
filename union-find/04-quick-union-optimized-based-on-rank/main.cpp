#include <iostream>
#include <cassert>

using namespace std;

namespace UF4{
  class UnionFind{
  private:
    int* parent;
    int* rank; // size[i]表示以i为根的集合所表示的层数
    int count;
  public:
    UnionFind(int count){
      parent = new int[count];
      rank = new int[count];
      this->count = count;
      for(int i = 0; i < count; i++)
      {
        parent[i] = i;
        rank[i] = 1;
      }
    }
    ~UnionFind(){
      delete [] parent;
      delete [] rank;
    }
    int find(int q){
      assert(q >= 0 && q < count);
      while(q != parent[q]){
        q = parent[q];
      }
      return q;
    }
    bool isConnected(int p, int q){
      return find(q) == find(q);
    }
    void unionElements(int p, int q){
      int pRoot = find(p);
      int qRoot = find(q);
      if(qRoot == pRoot)
        return;
      if(rank[pRoot] < rank[qRoot]){
        parent[pRoot] = qRoot;
      } else if (rank[qRoot] < rank[pRoot]){
        parent[qRoot] = pRoot;
      } else { // rank[pRoot] = rank[qRoot]
        parent[pRoot] = qRoot;
        rank[qRoot] +=1;
      }
    }
  };
}