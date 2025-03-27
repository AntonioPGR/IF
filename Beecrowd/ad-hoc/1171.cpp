#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

  int n;
  cin >> n;

  vector<int> numbers(n);
  for(int i = 0; i < n; i++){
    cin >> numbers[i];
  }

  sort(numbers.begin(), numbers.end());

  int current_number = 0;
  int amount = 0;
  for(int i = 0; i < n; i++){
    current_number = numbers[i];

    while (i < n && numbers[i] == current_number) {
      amount++;
      i++; 
    }

    cout << current_number << " aparece " << amount << " vez(es)" << endl;
    amount = 1;
  }
  

}