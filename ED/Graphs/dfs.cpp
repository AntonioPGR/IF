#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

vector<int> dfs(vector<vector<int>>& adj, int src){
  int nv = adj.size();
  vector<int> res;
  stack<int> st;
  vector<bool> visited(nv, false);

  visited[src] = true;
  st.push(src);

  while(!st.empty()){
    int current = st.top();
    st.pop();
    res.push_back(current);

    for(int i = adj[current].size() - 1; i >= 0; i--) {
      if (!visited[adj[current][i]]) {
        visited[adj[current][i]] = true;
        st.push(adj[current][i]);
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

  cout << "DFS: " << endl;
  res = dfs(adj, 1);
  for(auto j : res) cout << j << " ";
  cout << endl;

}