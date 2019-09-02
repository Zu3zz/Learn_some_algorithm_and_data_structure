#include <iostream>
#include <iomanip>
#include "DenseGraph.h"
#include "ReadGraph.h"
#include "SparseGraph.h"

using namespace std;

int main(){
  string filename = "testG1.txt";
  int V = 8;
  cout<<fixed<<setprecision(2);

  // test Weight Dense Graph
  DenseGraph<double> g1 = DenseGraph<double> (V, false);
  ReadGraph<DenseGraph<double>, double> readGraph1(g1, filename);
  g1.show();
  cout<<endl;

  // test Weight Sparse Graph
  SparseGraph<double> g2 = SparseGraph<double> (V,false);
  ReadGraph<SparseGraph<double>, double> readGraph2(g2,filename);
  g2.show();
  cout<<endl;

  return 0;
}