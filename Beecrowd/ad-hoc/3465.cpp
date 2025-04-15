#include <iostream>
#include <cmath>

using namespace std;

int main(){
  double a, b, c;
  cin >> a >> b >> c;

  double cos = (pow(b, 2) + pow(c, 2) - pow(a, 2)) / (2 * b * c);
  double sin = sqrt(1 - pow(cos, 2));
  double area = (b * c * sin) / 2;

  cout << fixed;
  cout.precision(3);
  cout << area << " m2" << endl;

  return 0;
}