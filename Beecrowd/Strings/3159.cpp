#include <iostream>
#include <map>

using namespace std;

map<char, string> alpha = {
  {'a', "2"},
  {'b', "22"},
  {'c', "222"},
  {'d', "3"},
  {'e', "33"},
  {'f', "333"},
  {'g', "4"},
  {'h', "44"},
  {'i', "444"},
  {'j', "5"},
  {'k', "55"},
  {'l', "555"},
  {'m', "6"},
  {'n', "66"},
  {'o', "666"},
  {'p', "7"},
  {'q', "77"},
  {'r', "777"},
  {'s', "7777"},
  {'t', "8"},
  {'u', "88"},
  {'v', "888"},
  {'w', "9"},
  {'x', "99"},
  {'y', "999"},
  {'z', "9999"},
  {' ', "0"}
};


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); 

  int n;
  cin >> n;
  cin.ignore();
  while(n--){
    string s;
    getline(cin, s);
    char last_char = '\0';
    for(char c : s){
      if('A' <= c && c <= 'Z') cout << "#";
      else if(last_char != '\0' && alpha[tolower(last_char)][0] == alpha[tolower(c)][0]) cout << "*";
      cout << alpha[tolower(c)];
      last_char = c;
    }
    cout << endl;
  }

  return 0;
}