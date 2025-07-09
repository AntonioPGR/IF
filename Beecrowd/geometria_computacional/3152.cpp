#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

typedef struct Land{
  int x1;
  int y1;
  int x2;
  int y2;
  int x3;
  int y3;
  int x4;
  int y4;
} Land;


int main(){

  Land l1 = Land();
  cin >> l1.x1 >> l1.y1;
  cin >> l1.x2 >> l1.y2;
  cin >> l1.x3 >> l1.y3;
  cin >> l1.x4 >> l1.y4;
  int area1 = abs(
    (l1.x1*l1.y2 + l1.x2*l1.y3 + l1.x3*l1.y4 + l1.x4*l1.y1) -
    (l1.x2*l1.y1 + l1.x3*l1.y2 + l1.x4*l1.y3 + l1.x1*l1.y4)
  ) / 2;

  Land l2 = Land();
  cin >> l2.x1 >> l2.y1;
  cin >> l2.x2 >> l2.y2;
  cin >> l2.x3 >> l2.y3;
  cin >> l2.x4 >> l2.y4;
  int area2 = abs(
    (l2.x1*l2.y2 + l2.x2*l2.y3 + l2.x3*l2.y4 + l2.x4*l2.y1) -
    (l2.x2*l2.y1 + l2.x3*l2.y2 + l2.x4*l2.y3 + l2.x1*l2.y4)
  ) / 2;

  if(area1 > area2) cout << "terreno A" << endl;
  else cout << "terreno B" << endl;

}