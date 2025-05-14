#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  int n;
  cin >> n;

  vector<int> numbers(n);
  for(int i = 0; i < n; i++) cin >> numbers[i];

  sort(numbers.begin(), numbers.end());

  int odd = 0, even = 0, last_number = 0;
  char last_add = 'o';
  for(int num : numbers){
    if(num % 2 == 0) {
      odd += num;
    } else {
      even += num;
    }
  }

  cout << max(odd, even) << endl;

  return 0;
}

/*

10
8 10 4 9 1 3 5 9 4 10
36
*/