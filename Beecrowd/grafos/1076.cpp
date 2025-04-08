#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int dfs(vector<vector<int>> adj, int start){

  vector<bool> visited(adj.size(), false);
  int count = 0;
  stack<int> st;

  st.push(start);
  visited[start] = true;

  while(!st.empty()){
    int cur = st.top();
    st.pop();
    for(int node : adj[cur]){
      if(!visited[node]){
        st.push(node);
        visited[node] = true;
        count++;
      }
    }
  }

  return count;
}

int main(){

  int t;
  cin >> t;
  while(t--){
    int start;
    cin >> start;

    int v, a;
    cin >> v >> a;

    vector<vector<int>> adj(v, vector<int>());
    int v1, v2;
    for(int i = 0; i < a; i++){
      cin >> v1 >> v2;
      adj[v1].push_back(v2);
      adj[v2].push_back(v1);
    }

    int steps = dfs(adj, start);

    cout << steps * 2 << endl;

  }

  return 0;
}