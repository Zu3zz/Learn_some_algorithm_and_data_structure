#include <iostream>
#include <cassert>
#include <vector>
#include "Edge.h"

using namespace std;
// 稠密图 - 邻接矩阵
template <typename Weight>

class DenseGraph
{
private:
  int n, m;                         // 节点数和边数
  bool directed;                    // 是否为有向图
  vector<vector<Edge<Weight> *> > g; // 图的具体数据

public:
  // 构造函数
  DenseGraph(int n, bool directed)
  {
    assert(n >= 0);
    this->n = n;
    this->m = 0;
    this->directed = directed;
    for (int i = 0; i < n; i++)
    {
      g.push_back(vector<Edge<Weight> *>(n, NULL));
    }
  }
  ~DenseGraph() {
    for(int i = 0; i < n; i++)
    {
      for(int j = 0; j < n; j++)
      {
        if(g[i][j] != NULL)
          delete g[i][j];
      }
    }
  }

  int V() { return n; }
  int E() { return m; }

  void addEdge(int v, int w, Weight weight)
  {
    assert(v >= 0 && v < n);
    assert(w >= 0 && w < n);
    if (hasEdge(v, w))
    {
      delete g[v][w];
      if (!directed)
        delete g[w][v];
      m--;
    }
    g[v][w] = new Edge<Weight>(v, w, weight);
    if (!directed)
      g[w][v] = new Edge<Weight>(w, v, weight);
    m++;
  }

  bool hasEdge(int v, int w)
  {
    assert(v >= 0 && v < n);
    assert(w >= 0 && w < n);
    return g[v][w] != NULL;
  }
  // 打印邻接矩阵
  void show()
  {
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        if(g[i][j])
          cout << g[i][j]->wt() << "\t";
        else
          cout<<"NULL\t";
      cout << endl;
  }

  class adjIterator
  {
  private:
    DenseGraph &G;
    int v;
    int index;

  public:
    adjIterator(DenseGraph &graph, int v) : G(graph)
    {
      assert(v >= 0 && v < G.n);
      this->v = v;
      this->index = -1;
    }
    ~adjIterator() {}
    // 返回图G中与顶点v相连接的第一个顶点
    Edge<Weight>* begin()
    {
      // 索引从-1开始, 因为每次遍历都需要调用一次next()
      index = -1;
      return next();
    }
    Edge<Weight>* next()
    {
      for (index += 1; index < G.V(); index++)
        if (G.g[v][index])
          return G.g[v][index];
      return NULL;
    }
    bool end()
    {
      return index >= G.V();
    }
  };
};