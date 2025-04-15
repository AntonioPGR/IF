#include <iostream>

using namespace std;

int main(){

  double a, b, c;
  cin >> a >> b >> c;

  double result = 1 / (1/a + 1/b + 1/c);

  cout << fixed;
  cout.precision(3);
  cout << result << endl;

  return 0;
}