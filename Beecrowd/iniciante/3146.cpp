#include <iostream>

using namespace std;

int main(){

  float r;
  cin >> r;

  float result = 2 * 3.14 * r;
  cout << fixed;
  cout.precision(2);
  cout << result << endl;

}