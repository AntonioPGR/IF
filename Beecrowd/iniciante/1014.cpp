#include <iostream>

using namespace std;

int main(){

  float x, y;
  cin >> x >> y;

  float kml = x/y;

  cout << fixed;
  cout.precision(3);
  cout << kml << " km/l" << endl;
}