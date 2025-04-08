#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool bfs(vector<vector<int>>& map, int start, int end){
  vector<bool> visited(map.size(), false);
  queue<int> q;

  q.push(start);
  visited[start] = true;

  while(!q.empty()){
    int cur = q.front();
    q.pop();
    for(int i : map[cur]){
      if(i == end) return true;
      if(!visited[i]){
        visited[i] = true;
        q.push(i);
      }
    }
  }

  return false;
}

int main(){
  int n, m;
  while(cin >> n >> m && n != 0 && m != 0){
    vector<vector<int>> map(n, vector<int>());

    int v, w, p;
    for(int i = 0; i < m; i++){
      cin >> v >> w >> p;
      v--;
      w--;
      map[v].push_back(w);
      if(p == 2) map[w].push_back(v);
    }

    bool exists = true;
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        if(!bfs(map, i, j)){
          exists = false;
          break;
        }
      }
      if(!exists) break;
    }

    if(exists) cout << 1 << endl;
    else cout << 0 << endl;
  }
}