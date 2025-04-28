#include <iostream>
#include <vector>

using namespace std;

int climbingStairs(int n, vector<int>& memo){
  if(n == 1) return 1;
  if(n == 2) return 2;
  if(memo[n] == -1){
    memo[n] = climbingStairs(n-1, memo) + climbingStairs(n-2, memo);
  }
  return memo[n];
}

int main(){

  int n;
  cin >> n;

  vector<int> memo(n+1, -1);
  cout << climbingStairs(n, memo) << endl;

}