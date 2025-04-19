#include <iostream>
#include <vector>

using namespace std;

int main(){

  vector<int> valores = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

  int n;
  cin >> n;
  while(n--){
    string number;
    cin >> number;
    int sum = 0;
    for(char c : number){
      sum += valores[c - '0'];
    }
    cout << sum << " leds" << endl;
  }

  return 0;
}