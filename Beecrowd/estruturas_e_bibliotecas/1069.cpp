#include <iostream>
#include <stack>

using namespace std;

int main(){

  int n;
  cin >> n;
  cin.ignore();

  while(n--){
    string s;
    getline(cin, s);

    stack<char> st;
    int amount = 0;
    for(char c : s){
      if(c == '<') st.push(c);
      else if(c == '>' && !st.empty()){
        st.pop();
        amount++;
      }
    }

    cout << amount << endl;
  }

}