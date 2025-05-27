#include <iostream>

using namespace std;

int main(){

  float n, x;
  cin >> n >> x;

  float result = (x / (n+2));
  cout << fixed;
  cout.precision(2);
  cout << result << endl;

}