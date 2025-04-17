#include <iostream>

using namespace std;

int main(){

  int a, b, c, n;
  cin >> a >> b >> c >> n;
  int q = b - a;
  cout << (a + ((n-1)*q)) << endl;

}