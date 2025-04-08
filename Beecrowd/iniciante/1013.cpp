#include <iostream>

using namespace std;

int main(){

  int n1, n2, n3, maior;
  cin >> n1 >> n2 >> n3;

  maior = n1;
  if(n2 > maior) maior = n2;
  if(n3 > maior) maior = n3;

  cout << maior << " eh o maior" << endl;

}