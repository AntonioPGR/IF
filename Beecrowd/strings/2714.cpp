#include <iostream>

using namespace std;

int main(){

  int n;
  cin >> n;
  while(n--){
    string ra;
    cin >> ra;
    
    int is_numeric = true;
    int is_all_0 = true;
    for(int i = 2; i < ra.size() && ra.size() > 2; i++){
      if(ra.at(i) < 48 || ra.at(i) > 57){
        is_numeric = false;
      }
      if(ra.at(i) != '0') is_all_0 = false;
    }

    if(ra.at(0) != 'R' || ra.at(1) != 'A' || ra.size() != 20 || is_all_0){
      cout << "INVALID DATA" << endl;
      continue;
    }

    bool passed = false;
    for(int i = 2; i < ra.size(); i++){
      if(ra.at(i) != '0' || passed) {
        cout << ra.at(i);
        passed = true;
      }
    }
    cout << endl;

  }

  return 0;
}

/*

10
RA000000000000000001
RA000000000000000100
RA000000000000012345
RA123456789012345678
ra000000000000000333
RA12345
12345678901234567890
RA000000000000000000
RA000000000000000009
rA000000000000000000

*/
