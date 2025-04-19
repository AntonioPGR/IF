#include <iostream>

using namespace std;

int main(){

  int n;
  cin >> n;
  cin.ignore();
  while(n--){

    string s;
    getline(cin, s);

    int s_len = s.length();

    for(int i = 0; i < s_len; i++){
      if(
        (s[i] >= 65 && s[i] <= 90) ||
        (s[i] >= 97 && s[i] <= 122)
      ) s[i] += 3;
    }

    for(int i = 0; i < s_len / 2; i++){
      char temp = s[s_len - i - 1];
      s[s_len - i - 1] = s[i];
      s[i] = temp;
    }

    for(int i = s_len/2; i < s_len; i++){
      s[i] -= 1;
    }
    cout << s << endl;

  }

  return 0;
}