#include <iostream>
#include <vector>

using namespace std;

int unboundedKnapsack(int max, vector<int> &values, vector<int> comp){
  vector<int> dp(max+1, 0);

  for(int i = 0; i < comp.size(); i++){
    for(int j = 1; j <= max; j++){
      int take = 0;
      if(j - comp[i] >= 0){
        take = values[i] + dp[j - comp[i]];
      }
      int noTake = dp[j];

      dp[j] = std::max(take, noTake);
    }
  }

  return dp[max];
}

int main(){

  int n, t;
  cin >> n >> t;

  vector<int> comp(n), values(n);
  for(int i = 0; i < n; i++){
    cin >> comp[i] >> values[i];
  }

  int value = unboundedKnapsack(t, values, comp);

  cout << value << endl;

  return 0;
}