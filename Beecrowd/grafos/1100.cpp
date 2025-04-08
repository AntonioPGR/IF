#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef struct Point{
  int x;
  int y;
  Point(int _x, int _y) : x(_x), y(_y){}
} Point;

bool isValid(Point cur, Point mov){
  if(
    cur.x + mov.x > 7 ||
    cur.x + mov.x < 0 ||
    cur.y + mov.y > 7 ||
    cur.y + mov.y < 0
  ) return false;
  return true;
}

int calculateDistance(string s, string e){

  Point start(s[0] - 'a', s[1] - '1');
  Point end(e[0] - 'a', e[1] - '1');

  if(start.x == end.x && start.y == end.y) return 0;

  vector<vector<bool>> visited(8, vector<bool>(8, false));
  queue<Point> q;
  vector<Point> movements = {Point(1, 2), Point(2, 1), Point(-1, 2), Point(-2, 1), Point(1, -2), Point(2, -1), Point(-1, -2), Point(-2, -1)};

  q.push(start);
  visited[start.x][start.y] = true;
  int count = 1;

  while(!q.empty()){
    int size = q.size();
    for(int i = 0; i < size; i++){
      Point cur = q.front();
      q.pop();
      for(Point mov : movements){
        if(isValid(cur, mov) && !visited[cur.x + mov.x][cur.y + mov.y]){
          Point newPoint = Point(cur.x + mov.x, cur.y + mov.y);
          if(newPoint.x == end.x && newPoint.y == end.y) return count;
          q.push(newPoint);
          visited[newPoint.x][newPoint.y] = true;
        }
      }
    }
    count++;
  }

  return -1;
}

int main(){
  string x, y;
  while(cin >> x >> y){
    int n = calculateDistance(x, y);
    cout << "To get from " << x << " to " << y << " takes " << n << " knight moves." << endl;
  }
}