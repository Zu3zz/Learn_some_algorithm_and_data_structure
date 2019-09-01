#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

class DenseGraph{
private:
  int n, m;               // 节点数和边数
  bool directed;          // 是否为有向图
  vector<vector<bool> > g; // 图的具体数据

public:
  // 构造函数
  DenseGraph(int n, bool directed){
    assert(n >= 0);
    this->n = n;
    this->m = 0;
    this->directed = directed;
    for(int i = 0; i < n; i++)
    {
      g.push_back(vector<bool>(n, false));
    }
  }
  ~DenseGraph(){}

  int V(){return n;}
  int E(){return m;}

  void addEdge(int v, int w){
    assert(v >= 0 && v < n);
    assert(w >= 0 && w < n);
    if(hasEdge(v,w)){
      return;
    }
    g[v][w] = true;
    if(!directed){
      g[w][v] = true;
    }
    m++;
  }
  
  bool hasEdge(int v, int w){
    assert(v >= 0 && v <n);
    assert(w >= 0 && w < n);
    return g[v][w];
  }
  // 打印邻接矩阵
  void show(){
    for(int i = 0; i< n;i++){
      for(int j = 0;j<n;j++){
        cout<<g[i][j]<<"\t";
      }
      cout<<endl;
    }
  }

  class adjIterator{
  private:
    DenseGraph &G;
    int v;
    int index;
  public:
    adjIterator(DenseGraph &graph, int v): G(graph){
      assert( v>=0 && v< G.n);
      this->v = v;
      this->index = -1;
    }
    ~adjIterator(){}
    // 返回图G中与顶点v相连接的第一个顶点
    int begin(){
      // 索引从-1开始, 因为每次遍历都需要调用一次next()
      index = -1;
      return next();
    }
    int next(){
      for(index +=1;index < G.V();index++)
        if(G.g[v][index])
          return index;
        return -1;
    }
    bool end(){
      return index >= G.V();
    }
  };
};