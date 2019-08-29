#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

class SparseGraph
{
private:
  int n, m; // 节点数和边数
  bool directed; // 是否为有向图
  vector<vector<int> > g; // 图的具体连接情况

public:
  // 构造函数
  SparseGraph(int n, int directed){
    this->n = n;
    this->m = 0;
    this->directed = directed;
    for(int i = 0;i<n;i++){
      g.push_back(vector<int>());
    }
  }
  ~SparseGraph(){}

  int V(){return n;}
  int W(){return m;}

  void addEdge(int v, int w){
    assert(v >= 0 && v < n);
    assert(w >= 0 && w < n);
    g[v].push_back(w);
    // 考虑自环边
    if( v != w && !directed){
      g[w].push_back(v);
    }
    m++;
  }
  // 需要遍历 O(n)
  bool hasEdge(int v, int w){
    assert(v >= 0 && v < n);
    assert(w >= 0 && w < n);
    for(int i = 0;i<g[v].size();i++){
      if(g[v][i] == w)
        return true;
      return false;
    }
  }
};