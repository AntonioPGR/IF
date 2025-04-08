#include <iostream>
#include <math.h>

using namespace std;

int main(){

  int r, l;
  cin >> r >> l;

  double v = (4 * 3.1415 * pow(r, 3)) / 3;
  int amount = l/v;

  cout << amount << endl;

}