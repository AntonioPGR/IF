#include <iostream>
#include <vector>

using namespace std;

int main(){

  int n, k;
  cin >> n >> k;

  vector<int> numbers(n);
  for(int i = 0; i < n; i++) cin >> numbers[i];

  int value;
  for(int pos = 0; pos < n; pos++){
    value = numbers[pos];
    int count = pos;

    while(value <= numbers[count]){
      value += k;
      count++;
      if(count == n) count = 0;
    }

    cout << count + 1 << " ";
  }
  cout << endl;

}
