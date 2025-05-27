#include <iostream>

using namespace std;

int main(){

  int caixa, estado;
  cin >> caixa >> estado;

  if(caixa == 1) cout << "vivo e morto" << endl;
  else if(estado == 0) cout << "morto" << endl;
  else cout << "vivo" << endl;

  return 0;
}