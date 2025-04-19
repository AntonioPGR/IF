#include <iostream>

using namespace std;

int main(){

  string d, n;
  while(cin >> d >> n){
    if(d == n && d[0] == '0') break;

    char digit = d[0];
    int printed_numbers = 0;
    for(char c : n){
      if(
        (c == digit) ||
        (c == '0' && !printed_numbers)
      ) continue;
      cout << c;
      printed_numbers++;
    }
    if(!printed_numbers) cout << '0';
    cout << endl;
  }

}