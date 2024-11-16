#include <iostream>
#include <cmath>

using namespace std;

int main(){

  int n;
  cin >> n;

  long long int r = (pow(n, 4.0) - (6.0 * pow(n, 3.0)) + (23.0 * pow(n, 2.0)) - (18.0 * n) + 24.0 ) / 24.0;

  cout << r << endl;

}