#include <iostream>

using namespace std;

int main(){

  int nota = 70*160;
  int b, t;
  cin >> b;
  cin >> t;

  int area_cort = (b+t)*70/2;

  if(area_cort > nota / 2) cout << 1 << endl;
  else if(area_cort < nota/2) cout << 2 << endl;
  else cout << 0 << endl;

}