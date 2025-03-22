#include <iostream>
#include <stack>

using namespace std;

int main(){

  string s;
  while(getline(cin, s)){
    
    stack<char> st;

    bool error = false;
    for(char c : s){
      if(c == '(') st.push('(');
      else if(c == ')'){
        if(st.empty()){
          error = true;
          break;
        }
        st.pop();
      }
    }

    if(error || !st.empty()) cout << "incorrect" << endl;
    else cout << "correct" << endl;

  }

}