#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef struct Pair{
  int x, y;
  Pair(int _x, int _y) : x(_x), y(_y) {}
} Pair;

bool isValid(int newX, int newY){
  return newX >= 0 && newX <= 4 && newY >= 0 && newY <= 4;
}

// INVERTER X Y
bool verifyPath(vector<vector<int>> map){

  vector<vector<bool>> visited(5, vector<bool>(5, false));
  vector<Pair> movements = {Pair(1, 0), Pair(0, 1), Pair(-1, 0), Pair(0, -1)};
  queue<Pair> q;
  Pair goal = Pair(4, 4);

  q.push(Pair(0, 0));
  
  while(!q.empty()){
    Pair cur = q.front();
    q.pop();

    if(cur.x == goal.x && cur.y == goal.y) return 1;

    for(Pair mov : movements){
      int newX = cur.x + mov.x;
      int newY = cur.y + mov.y;
      if(isValid(newX, newY) && !visited[newX][newY] && map[newX][newY] != 1){
        q.push(Pair(newX, newY));
        visited[newX][newY] = true;
      }
    }
  }
  return 0;
}

int main(){
  int n;
  cin >> n;
  while(n--){
    
    vector<vector<int>> map(5, vector<int>(5));
    char temp;
    for(int i = 0; i < 5; i++){
      for(int j = 0; j < 5; j++){
        cin >> temp;
        if(temp != '1' && temp != '0'){
          j--;
          continue;
        }
        map[i][j] = temp - '0';
      }
    }

    bool path_exists = verifyPath(map);

    if(path_exists) cout << "COPS" << endl;
    else cout << "ROBBERS" << endl;

  }

  return 0;
}