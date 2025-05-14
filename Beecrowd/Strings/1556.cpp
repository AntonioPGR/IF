#include <iostream>
#include <string>

using namespace std;

int main(){

  string s;
  while(getline(cin, s)){

    for (int i = 0; i < s.length(); i++)
      for (int len = 1; len <= s.length() - i; len++)
        cout << s.substr(i, len) << endl;

  }

}