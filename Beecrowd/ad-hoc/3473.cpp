#include <iostream>

using namespace std;

int main(){
  double n1;
  double n2;
  cin >> n1 >> n2;

  cout << fixed;
  cout.precision(2);
  cout << (n1/n2) << endl;
}