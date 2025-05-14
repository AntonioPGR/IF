#include <iostream>

using namespace std;

int main(){

  int n;
  cin >> n;
  while(n--){

    int min, max;
    cin >> min >> max;

    for(int i = min; i<= max; i++){
      cout << i;
    }
    for(int i = max; i >= min; i--){
      string number = to_string(i);
      for(int j = number.size()-1; j >= 0; j--){
        cout << number.at(j);
      }
    }
    cout << endl;
  }

}