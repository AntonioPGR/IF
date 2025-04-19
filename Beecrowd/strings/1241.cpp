#include <iostream>
#include <string>

using namespace std;

int main(){
  int n;
  cin >> n;
  while(n--){
    string a, b;
    cin >> a >> b;

    int a_len = a.length();
    int b_len = b.length();

    if(b_len > a_len){
      cout << "nao encaixa" << endl;
      continue;
    }

    bool encaixa = true;
    for(int i = 0; i < b_len; i++){
      if(a[a_len-1-i] != b[b_len-1-i]){
        encaixa = false;
        break;
      }
    }

    if(encaixa) cout << "encaixa" << endl;
    else cout << "nao encaixa" << endl;
  }

  return 0;
}