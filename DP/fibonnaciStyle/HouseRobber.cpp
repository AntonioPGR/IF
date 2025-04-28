#include <iostream>
#include <vector>

using namespace std;

int main(){
  int n;
  cin >> n;

  vector<int> houses(n);
  for(int i = 0; i < n; i++) cin >> houses[i];

  vector<int> dp(n+1, -1);
  dp[0] = houses[0];
  dp[1] = houses[1];
  dp[2] = houses[0] + houses[2];
  for(int i = 3; i <= n; i++){
    if(i < n) dp[i] = houses[i] + max(dp[i - 2], dp[i - 3]);
    else dp[i] = max(dp[i - 1], dp[i - 2]);
  }

  cout << dp[n] << endl;

}

/*


[10, 2, 4, 100, 6, 3, 11]
  0  1  2    3  4  5   6


roubar 11
  -> 6 ou 100
roubar 3
  -> 100 ou 4

[2,7,9,3,1]
12

*/
