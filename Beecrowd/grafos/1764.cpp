#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int findMST(vector<vector<pair<int, int>>>& adj){
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  vector<bool> inMST(adj.size(), false);
  pq.push({0, 0}); // (weight, vertex)
  int mstCost = 0;

  while(!pq.empty()){
    auto temp = pq.top();
    int u = temp.second;
    int w = temp.first;
    pq.pop();

    if(inMST[u]) continue;
    inMST[u] = true;
    mstCost += w;

    for(auto& t : adj[u]){
      int v = t.second;
      int weight = t.first;
      if(!inMST[v]) pq.push({weight, v});
    }
  }

  return mstCost;
}

int main(){
  int m, n;
  while(cin >> m >> n && m != 0 && n != 0){
    vector<vector<pair<int, int>>> adj(m);
    int x, y, z;
    for(int i = 0; i < n; i++){
      cin >> x >> y >> z;
      adj[x].push_back(make_pair(z, y));
      adj[y].push_back(make_pair(z, x));
    }

    int min_km = findMST(adj);

    cout << min_km << endl;
  }

  return 0;
}