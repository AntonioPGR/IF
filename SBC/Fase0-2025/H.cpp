#include <iostream>
#include <string>
#include <algorithm>
#include <bitset>
#include <unordered_map>

using namespace std;

string decimalToBinary(long long n, unordered_map<int, string>& memo) {
  if(n == 0) return "0";
  if(n == 1) return "1";
  if (memo.count(n)) return memo[n];
  memo[n] = decimalToBinary(n/2, memo) + to_string(n % 2);
  return memo[n];
}

bool check(const std::string& str, unordered_map<string, bool>& memo) {
  if (memo.find(str) != memo.end()) return memo[str];;

  if (memo.find(str) != memo.end()) return memo[str];

  size_t size = str.size();
  size_t count = size / 2;
  
  for (size_t i = 0; i < count; i++) {
    if (str[i] != str[size - i - 1]) {
      memo[str] = false;
      return false;
    }
  }

  memo[str] = true; 
  return true;
}

int main() {
  long long n;
  cin >> n;

  unordered_map<int, string> memoBinary;
  unordered_map<string, bool> memoPalindrome;

  string n_binary = decimalToBinary(n, memoBinary);
  bool isPalindrome = check(n_binary, memoPalindrome);
  long long result = n;
  long long step = 0;

  bool isPalindrome = check(n_binary, memoPalindrome);
  while(!isPalindrome){
    step++;
    long long prev_number = n - step;
    if(prev_number % 2 == 0) continue;
    n_binary = decimalToBinary(prev_number, memoBinary);
    isPalindrome = check(n_binary, memoPalindrome);
    result = prev_number;
  }

  cout << result << endl;

  return 0;
}