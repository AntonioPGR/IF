#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){

  long long n, d;
  while(cin >> n >> d && n != 0 && d != 0){
    cin.ignore();
    string number;
    getline(cin, number);

    int delete_amount = d;
    string result;
    for(char c : number){
      while(delete_amount > 0 && !result.empty() && c > result.back()){
        result.pop_back();
        delete_amount--;
      }
      result.push_back(c);
    }
    result.resize(result.size() - delete_amount);

    cout << result << endl;

  }

}