#include <iostream>
#include <string>

using namespace std;

int main(){

  int n;
  cin >> n;
  cin.ignore();
  while(n--){
    string s;
    getline(cin, s);

    if(s.size() == 5){
      cout << 3 << endl;
      continue;
    }

    if(s[0] == 'o' || s[2] == 'e'){
      cout << 1 << endl;
      continue;
    }

    cout << 2 << endl;
  }

}