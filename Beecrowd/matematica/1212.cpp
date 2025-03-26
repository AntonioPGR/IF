#include <iostream>

using namespace std;

int main(){

  string n1, n2;
  while(cin >> n1 >> n2 && !(n1 == "0" && n2 == "0")){
    int carry_count = 0;
    int carry_to_next = 0;
    int n1_len = n1.length();
    int n2_len = n2.length();
    int max_length = max(n1_len, n2_len);

    for (int i = 1; i <= max_length; i++) { 
      int n1_n = (i <= n1_len) ? (n1[n1_len - i] - '0') : 0; 
      int n2_n = (i <= n2_len) ? (n2[n2_len - i] - '0') : 0;

      if (n1_n + n2_n + carry_to_next >= 10) {
        carry_to_next = 1;
        carry_count++;
      } else {
        carry_to_next = 0;
      }
    }

    if(carry_count == 0) cout << "No carry operation." << endl;
    else if(carry_count == 1) cout << "1 carry operation." << endl;
    else cout << carry_count << " carry operations." << endl;
  }

  return 0;
}