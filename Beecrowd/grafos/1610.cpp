#include <iostream>
#include <vector>

using namespace std;

bool isCyclicUtil(vector<vector<int>> &dependences, int u, vector<bool> &visited, vector<bool> &reStack){
  if(reStack[u] == true) return true;

  visited[u] = true;
  reStack[u] = true;

  for(int dependence : dependences[u]){
    if(!visited[dependence] && isCyclicUtil(dependences, dependence, visited, reStack)) return true;
    else if(reStack[dependence]) return true;
  }

  reStack[u] = false;
  return false;
}

bool isCyclic(vector<vector<int>> &dependences){
  int edges = dependences.size();
  vector<bool> visited(edges, false), recStack(edges, false);

  for(int i = 0; i < edges; i++){
    if(!visited[i] && isCyclicUtil(dependences, i, visited, recStack))
      return true;
  }

  return false;
}

int main(){
  int t;
  cin >> t;
  while(t--){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> dependences(n);
    for(int i = 0; i < m; i++){
      int a, b;
      cin >> a >> b;
      a--;
      b--;
      dependences[a].push_back(b);
    }

    if(isCyclic(dependences)) cout << "SIM" << endl;
    else cout << "NAO" << endl;
  }
}