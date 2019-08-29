#include <iostream>
#include <cassert>

using namespace std;

namespace UF5{
  class UnionFind{
  private:
    int* parent;
    int* rank;
    int count;
  public:
    UnionFind(int count){
      parent = new int[count];
      rank = new int[count];
      this->count = count;
    }
    ~UnionFind(){
      delete [] parent;
      delete [] rank;
    }
    int find(int q){
      assert(q >= 0 && q < count);
      /* path compression
       * not best solution
      while(q != parent[q]){
        parent[q] = parent[parent[q]]
        q = parent[q];
      }
      return q;
      */
      // using recursion to get shortest tree
      if(q != parent[q])
        parent[q] = find(parent[q]);
      return parent[q];
    }
    bool isConnected(int q, int p){
      return find(q) == find(p);
    }
    void unionElements(int q, int p){
      int pRoot = find(p);
      int qRoot = find(q);
      if(qRoot == pRoot){
        return;
      }
      if(rank[qRoot] < rank[pRoot]){
        parent[qRoot] = pRoot;
      } else if(rank[pRoot] < rank[qRoot]){
        parent[pRoot] = qRoot;
      } else { // rank[qRoot] == rank[pRoot]
        parent[pRoot] = qRoot;
        rank[pRoot] += 1;
      }
    }
  };
}