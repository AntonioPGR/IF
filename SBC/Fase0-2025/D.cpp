#include <iostream>
#include <string>

using namespace std;

int main(){

  int n;
  string s1, s2;
  cin >> n;
  cin.ignore();
  getline(cin, s1);
  getline(cin, s2);

  float ast_1 = 0;
  for(int i = 0; i < n; i++){
    if(s1[i] == '*') ast_1++;
  }

  float ast_2 = 0;
  for(int i = 0; i < n; i++){
    if(s2[i] == '*') ast_2++;
  }

  float ast = ((ast_1 - ast_2)/ (ast_1));
  cout << fixed;
  cout.precision(2);
  cout << ast << endl;

}