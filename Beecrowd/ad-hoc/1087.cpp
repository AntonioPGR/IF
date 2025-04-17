#include <iostream>

using namespace std;

int main(){
  
  int x1, y1, x2, y2;
  while(cin >> x1 >> y1 >> x2 >> y2 && x1 != 0){

    int dx = x1 - x2;
    if(dx < 0) dx *= -1;
    int dy = y1 - y2;
    if(dy < 0) dx *= -1;


    if(x1 == x2 && y1 == y2) cout << 0 << endl;
    else if(
      x1 == x2 ||
      y1 == y2 ||
      dx == dy
    ) cout << 1 << endl;
    else cout << 2 << endl;

  }
  
  return 0;
}