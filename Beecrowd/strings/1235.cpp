#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;

int main(){

  int n;
  cin >> n;
  cin.ignore();
  while(n--){
    
    string s;
    getline(cin, s);

    int s_size = s.size();
    int mid = floor(s_size / 2);
    string s1 = s.substr(0, mid);
    string s2 = s.substr(mid, s_size);

    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());

    cout << s1 << s2 << endl;;

  }

}