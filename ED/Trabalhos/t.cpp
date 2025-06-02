#include <iostream>
#include <string>
#include <algorithm>
#include <bitset>

using namespace std;

string decimalToBinary(long long decimal) {
  if (decimal == 0) return "0";
  string full = bitset<64>(decimal).to_string();
  return full.substr(full.find('1'));
}

bool check(const std::string& str) {
  size_t size = str.size();
  size_t count = size/2;
  for (int i = 0; i < count; i++) {
    if (str[i] != str[size - i - 1]) return false;
  }
  return true;
}

int main() {
  long long n;
  cin >> n;

  string n_binary = decimalToBinary(n);
  bool isPalindrome = check(n_binary);
  long long result = n;
  long long step = 0;
  while(!check(n_binary)){
    step++;
    long long prev_number = n - step;
    if(prev_number % 2 == 0) continue;
    n_binary = decimalToBinary(prev_number);
    result = prev_number;
  }

  cout << result << endl;

  return 0;
}