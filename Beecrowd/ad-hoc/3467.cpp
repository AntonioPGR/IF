#include <iostream>

using namespace std;

int main(){

  string l;
  while(cin >> l){
    if(l[2] == 'L') cout << "Esse eh o meu lugar" << endl;
    else cout << "Oi, Leonard" << endl;
  }

  return 0;
}