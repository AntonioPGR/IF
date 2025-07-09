#include <iostream>

using namespace std;

int main(){
  int n;
  cin >> n;

  float s = 0, b = 0, a = 0;
  float s1 = 0, b1 = 0, a1 = 0;
  float tempS, tempB, tempA;
  while(n--){
    cin.ignore();

    string name;
    getline(cin, name);

    cin >> tempS >> tempB >> tempA;
    s += tempS;
    b += tempB;
    a += tempA;

    cin >> tempS >> tempB >> tempA;
    s1 += tempS;
    b1 += tempB;
    a1 += tempA;
  }

  cout << fixed;
  cout.precision(2);
  cout << "Pontos de Saque: " << (s1 / s) * 100 << " %." << endl;
  cout << "Pontos de Bloqueio: " << (b1 / b) * 100 << " %." << endl;
  cout << "Pontos de Ataque: " << (a1 / a) * 100 << " %." << endl;
}