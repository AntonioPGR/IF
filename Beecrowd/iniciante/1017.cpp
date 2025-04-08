#include <iostream>

using namespace std;

int main(){

  float x, y;
  cin >> x >> y;

  float km = x*y;
  float cons = km / 12;

  cout << fixed;
  cout.precision(3);
  cout << cons << endl;
}