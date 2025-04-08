#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int counter = 0;
vector<int> index, lowlink;
vector<bool> onStack;
stack<int> stk;
vector<vector<int>> sccs;

void tarjansDFS(vector<vector<int>>& adj, int u){
  index[u] = lowlink[u] = counter++;
  stk.push(u);
  onStack[u] = true;

  for(int v : adj[u]){
    if(index[v] == -1){
      tarjansDFS(adj, v);
      lowlink[u] = min(lowlink[u], lowlink[v]);
    } else if (onStack[v]){
      lowlink[u] = min(lowlink[u], lowlink[v]);
    }
  }

  if(lowlink[u] == index[u]){
    vector<int> scc;
    int w;
    do{
      w = stk.top();
      stk.pop();
      onStack[w] = false;
      scc.push_back(w);
    } while(w != u);
    sccs.push_back(scc);
  }
}

void tarjans(vector<vector<int>> adj){
  int n = adj.size();
  counter = 0;
  index.assign(n, -1);
  lowlink.assign(n, -1);
  onStack.assign(n, false);

  for(int v = 0; v < n; v++){
    if(index[v] == -1){
      tarjansDFS(adj, v);
    }
  }
}

int main(){
  int n;

  cin >> n;
  for(int i = 1; i <= n; i++){
    int v, e;
    cin >> v >> e;

    vector<vector<int>> adj(v);
    char a, b;
    int a_number, b_number;
    for(int i = 0; i < e; i++){
      cin >> a >> b;
      a_number = a - 'a';
      b_number = b - 'a';
      adj[a_number].push_back(b_number);
      adj[b_number].push_back(a_number);
    }

    tarjans(adj);

    cout << "Case " << "#" << i << ":" << endl;
    for(vector<int> scc : sccs){
      sort(scc.begin(), scc.end());
      for(int comp : scc){
        char c_comp = comp + 'a';
        cout << c_comp << ",";
      }
      cout << endl;
    }
    cout << sccs.size() << " connected components" << endl << endl;
    
    sccs.clear();
  }

  return 0;
}