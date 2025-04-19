#include <iostream>

using namespace std;

int main(){
  string l;
  while(getline(cin, l)){
    int is_number = true;
    for(int i = 0; i < l.size(); i++){
      if(l[i] == 'o' || l[i] == 'O') l[i] = '0';
      else if(l[i] == 'l') l[i] = '1';
      else if(l[i] == ',' || l[i] == ' ') {
        l.erase(i, 1);
        i--;
      }
    }
    
    for(char c : l){
      if(c < '0' || c > '9'){
        is_number = false;
        break;
      }
    }
    if(l.empty()) is_number = false;
    else if(l[0] == '0'){
      int first_not_of = l.find_first_not_of('0');
      if(first_not_of > l.length()) l = '0';
      else l.erase(0, first_not_of);
    }

    if(l.length() > 10) is_number = false;
    if(l.length() == 10 && is_number){
      long a = stol(l);
      if(a > 2147483647) is_number = false;
    }

    if(is_number) cout << l << endl;
    else cout << "error" << endl;

  }
  return 0;
}