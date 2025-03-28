#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

vector<int> bfs(vector<vector<int>>& adj, int src){
  int nv = adj.size();
  vector<int> res;
  queue<int> q;
  vector<bool> visited(nv, false);

  visited[src] = true;
  q.push(src);

  while(!q.empty()){
    int current = q.front();
    q.pop();
    res.push_back(current);

    for(int x : adj[current]){
      if(!visited[x]) {
        visited[x] = true;
        q.push(x);
      }
    }
  }

  return res;
}

int main(){

  // No weight
  vector<vector<int>> adj = {
    {0},
    {2, 5, 7},
    {4},
    {},
    {1, 5},
    {6, 0},
    {},
    {5}
  };
  vector<int> res;

  cout << "BFS: " << endl;
  res = bfs(adj, 1);
  for(auto j : res) cout << j << " ";
  cout << endl;

}