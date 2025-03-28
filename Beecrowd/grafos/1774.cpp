#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// Usado para gerenciar e agrupar conjuntos disjuntos
class DisjointSetUnion{
  vector<int> parent, rank;

  public:
    DisjointSetUnion(int n){
      parent.resize(n);
      rank.resize(n);
      for(int i = 0; i < n; i++){
        parent[i] = i;
        rank[i] = 1;
      }
    }

    int findRoot(int i){
      return (parent[i] == i)? i : (parent[i] = findRoot(parent[i]));
    }

    void unite(int x, int y) {
        int s1 = findRoot(x), s2 = findRoot(y);
        if (s1 != s2) {
            if (rank[s1] < rank[s2]) parent[s1] = s2;
            else if (rank[s1] > rank[s2]) parent[s2] = s1;
            else parent[s2] = s1, rank[s1]++;
        }
    }

};

bool comparator(vector<int>& a, vector<int>& b){
  if(a[2] <= b[2]) return true;
  return false;
}

int kruskalAlgorithm(int vertices, vector<vector<int>>& edges){
  sort(edges.begin(), edges.end(), comparator);

  DisjointSetUnion dsu(vertices);
  int cost = 0, count = 0;

  for(vector<int> &edge : edges){
    int start=edge[0], end=edge[1], weight=edge[2];

    // confirmar ciclo
    if(dsu.findRoot(start) != dsu.findRoot(end)){
      dsu.unite(start, end);
      cost += weight;
      if(++count == vertices - 1) break;
    }
  }

  return cost;
}

int main(){
  int routers_amount, cables_amount;
  cin >> routers_amount >> cables_amount;

  // {inicio, fim, peso}
  vector<vector<int>> routers;
  for(int i = 0; i < cables_amount; i++){
    vector<int> cable(3);
    cin >> cable[0] >> cable[1] >> cable[2];
    cable[0]--;
    cable[1]--;
    routers.push_back(cable);
  }

  int res = kruskalAlgorithm(routers_amount, routers);

  cout << res << endl;
}
