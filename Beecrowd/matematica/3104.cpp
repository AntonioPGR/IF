#include <iostream>

using namespace std;

long bigMod(string A, long B) {
  long rem = 0;
  for (char digit : A) {
    rem = (rem * 10 + (digit - '0')) % B;
  }
  return rem;
}

int main(){

  string a;
  long b;
  cin >> a >> b;

  cout << bigMod(a, b) << endl;

  return 0;
}