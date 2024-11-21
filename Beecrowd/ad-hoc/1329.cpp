#include <iostream>

using namespace std;

int main(){

  int n;
  while(cin >> n && n!=0){
    int mary=0, john=0, temp;
    while(n--){
      cin >> temp;
      if(temp == 0) mary++;
      else john++;
    }
    cout << "Mary won " << mary << " times and John won " << john << " times" << endl;
  }

  return 0;
}