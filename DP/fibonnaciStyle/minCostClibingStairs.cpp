#include <iostream>
#include <vector>

using namespace std;

int main(){
  int n;
  cin >> n;

  vector<int> steps(n);
  for(int i = 0; i < n; i++) cin >> steps[i];

  vector<int> dp(n+1, -1);
  dp[0] = steps[0];
  dp[1] = steps[1];

  for(int i = 2; i <= n; i++){
    if(i < n) dp[i] = steps[i] + min(dp[i-1], dp[i-2]);
    else dp[i] = min(dp[i-1], dp[i-2]);
  }

  cout << dp[n] << endl;

}
