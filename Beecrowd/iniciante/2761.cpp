#include <iostream>
#include <iomanip>

using namespace std;

int main(){

  int n_int;
  float n_float;
  char chr;
  string str;

  cin >> n_int >> n_float >> chr;
  getline(cin, str);

  str.erase(0, 1);

  cout << fixed;
  cout.precision(6);

  cout << n_int << n_float << chr << str << endl;
  cout << n_int << '\t' << n_float << '\t' << chr << '\t' << str << endl;
  cout << setw(10) << n_int << setw(10) << n_float << setw(10) << chr << setw(10) << str << endl;
  

}