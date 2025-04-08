#include <iostream>
#include <vector>
#include <deque>

using namespace std;

typedef struct Coord{
  int line;
  int column;
} Coord;

deque<Coord> toxic_water;

void contamine(vector<string> &map, int lines, int columns){

  for(int i = 0; i < lines; i++){
    for(int j = 0; j < columns; j++){
      if(map[i][j] == 'T'){
        Coord c;
        c.line = i;
        c.column = j;
        toxic_water.push_back(c);
      }
    }
  }

  while(!toxic_water.empty()){
    Coord cur = toxic_water.front();
    toxic_water.pop_front();

    Coord c;
    if(cur.line - 1 >= 0 && map[cur.line - 1][cur.column] == 'A'){
      map[cur.line - 1][cur.column] = 'T';
      c.line = cur.line - 1;
      c.column = cur.column;
      toxic_water.push_back(c);
    }
    if(cur.line + 1 < lines && map[cur.line + 1][cur.column] == 'A'){
      map[cur.line + 1][cur.column] = 'T';
      c.line = cur.line + 1;
      c.column = cur.column;
      toxic_water.push_back(c);
    }
    if(cur.column - 1 >= 0 && map[cur.line][cur.column - 1] == 'A'){
      map[cur.line][cur.column - 1] = 'T';
      c.line = cur.line;
      c.column = cur.column - 1;
      toxic_water.push_back(c);
    }
    if(cur.column + 1 < columns && map[cur.line][cur.column + 1] == 'A'){
      map[cur.line][cur.column + 1] = 'T';
      c.line = cur.line;
      c.column = cur.column + 1;
      toxic_water.push_back(c);
    }
  }
}

int main(){

  int n, m;
  while(cin >> n >> m && n != 0 && m != 0){

    vector<string> map(n);
    char temp;
    cin.ignore();
    for(int i = 0; i < n; i++){
      getline(cin, map[i]);
    }

    contamine(map, n, m);

    for(auto i : map)cout << i << endl;
    cout << endl;

  }
}