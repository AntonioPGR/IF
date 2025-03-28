#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class DisjointSetUnion{
  vector<int> parent;
  vector<int> rank;

  public:
    DisjointSetUnion(int n) : parent(n), rank(n,1) {
      for(int i = 0; i < n; i++) parent[i] = i;
    }

    int findRoot(int i){
      if(parent[i] != i) parent[i] = findRoot(parent[i]);
      return parent[i];
    }

    void unite(int x, int y){
      int rootX = findRoot(x);
      int rootY = findRoot(y);
      if(rootX != rootY){
        if(rank[rootX] < rank[rootY]) parent[rootX] = rootY;
        else {
          parent[rootY] = rootX;
          if(rank[rootX] == rank[rootY]) rank[rootX]++;
        }
      }
    }
};

int kruskal(int vertices, vector<vector<int>>& edges){
  sort(edges.begin(), edges.end(), [](vector<int> &a, vector<int> &b){
    return a[2] < b[2];
  });

  DisjointSetUnion dsu(vertices);
  int cost = 0;

  for(vector<int> edge : edges){
    if(dsu.findRoot(edge[0]) != dsu.findRoot(edge[1])){
      dsu.unite(edge[0], edge[1]);
      cost += edge[2];
    }
  }

  return cost;
}

int main(){

  int juncoes, qnt_estradas;

  while(cin >> juncoes >> qnt_estradas && juncoes != 0 && qnt_estradas != 0){
    
    int custo_total = 0;
    vector<vector<int>> estradas(qnt_estradas, vector<int>(3, 0));
    for(int i = 0; i < qnt_estradas; i++){
      cin >> estradas[i][0] >> estradas[i][1] >> estradas[i][2];
      custo_total += estradas[i][2];
    }

    int custo_minimo = kruskal(juncoes, estradas);

    cout << custo_total - custo_minimo << endl;

  }

}