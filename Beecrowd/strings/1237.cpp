#include <iostream>
#include <string>

using namespace std;

int main(){
  string s1, s2;
  while(getline(cin, s1) && getline(cin, s2)){

    int max = 0;
    for(int i = 0; i < s1.size(); i++){
      for(int j = 0; j < s2.size(); j++){
        if(s1[i] == s2[j]){
          int amount = 1;
          for(int k = 1; k < (s2.size() - j) && k < (s1.size() - i); k++){
            if(s1[i+k] != s2[j+k]) break;
            amount++;
          }
          if(amount > max) max = amount;
        }
      }
    }

    cout << max << endl;

  }
}