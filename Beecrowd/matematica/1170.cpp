#include <iostream>

using namespace std;

int main(){

  int n;
  cin >> n;

  while(n--){
    float kg;
    cin >> kg;

    int amount = 0;
    while(kg > 1){
      kg /= 2;
      amount++;
    }

    cout << amount << " dias" << endl;

  }

  return 0;
}