#include <iostream>
#include <vector>

using namespace std;

int main(){
  int n;
  cin >> n;

  vector<int> numbers(n);
  for(int i = 0; i < n; i++) cin >> numbers[i];

  if(n == 1){
    cout << 1 << endl;
    return 0;
  }

  // 1: peak (higher), 0: valley (lower), -1: undefined yet
  int last_was_peak = -1; 
  bool it_works = true;
  for(int i = 0; i < n; i++){
    if(last_was_peak == -1){
      if(numbers[0] == numbers[1]){
        it_works = false;
        break;
      } else if(numbers[0] > numbers[1]) last_was_peak = 1;
      else last_was_peak = 0;
      continue;
    }

    if(
      (last_was_peak && numbers[i] >= numbers[i-1]) ||
      (!last_was_peak && numbers[i] <= numbers[i-1])
    ){
      it_works = false;
      break;
    }

    last_was_peak = 1 - last_was_peak;
  }

  if(it_works) cout << 1 << endl;
  else cout << 0 << endl;


  return 0;
}