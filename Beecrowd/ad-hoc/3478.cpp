#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int searchCountries(vector<vector<int>> adj){
  int n = adj.size();
  vector<bool> visited(n, false);

  stack<int> stk;
  int sum = 0;
  for(int i = 0; i < n; i++){
    if(visited[i]) continue;
    sum++;

    visited[i] = true;
    stk.push(i);
    while(!stk.empty()){
      int cur = stk.top();
      stk.pop();
      for(int j : adj[cur]){
        if(!visited[j]){
          visited[j] = true;
          stk.push(j);
        }
      }
    }
  }

  return sum;
}

int main(){
  int c, f;
  cin >> c >> f;

  vector<vector<int>> adj(c);

  int x, y;
  for(int i = 0; i < f; i++){
    cin >> x >> y;
    x--; y--;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  int result = searchCountries(adj);

  cout << result << endl;

  return 0;
}