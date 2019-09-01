#include "DenseGraph.h"
#include "SparseGraph.h"
#include "Path.h"
#include "ReadGraph.h"

using namespace std;

int main(){

  string filename = "testG.txt";
  SparseGraph g = SparseGraph(7,false);
  ReadGraph<SparseGraph> readGraph(g, filename);
  g.show();
  cout<<endl;

  Path<SparseGraph> dfs(g,0);
  cout<<"DFS: ";
  dfs.showPath(6);

  return 0;
}