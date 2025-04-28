#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace std::chrono;

// Tabulation / Bottom up
long long tabulation(int n){
  if(n == 0) return 0;
  if(n == 1) return 1;
  long long last = 0;
  long long cur = 1;
  for(int i = 1; i < n; i++){
    long long temp = last;
    last = cur;
    cur += temp;
  }
  return cur;
}

// Memoization / Top Down
long long memoization(int n, vector<long long>& memo){
  if(n == 0) return 0;
  if(n == 1) return 1;
  if(memo[n] != -1) return memo[n];
  memo[n] = memoization(n-1, memo) + memoization(n-2, memo);
  return memo[n];
}

int main(){

  int n;
  cin >> n;

  // Memoization / Top Down
  cout << "Memoization: " << endl;
  auto start = high_resolution_clock::now();
  vector<long long> memo(n+1, -1);
  cout << "Result: " << memoization(n, memo) << endl;
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start).count();
  cout << "Time: " << duration << " microseconds" << endl << endl;

  // Tabulation / Bottom up
  cout << "Tabulation: " << endl;
  start = high_resolution_clock::now();
  cout << "Result: " << tabulation(n) << endl;
  stop = high_resolution_clock::now();
  duration = duration_cast<microseconds>(stop - start).count();
  cout << "Time: " << duration << " microseconds" << endl << endl;

}