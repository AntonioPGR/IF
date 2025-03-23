#include <iostream>
#include <vector>

using namespace std;

int knapsack(int W, vector<int> &val, vector<int> &wt) {
  vector<int> dp(W + 1, 0);

  for (int i = 0; i < wt.size(); i++) {
    for (int j = W; j >= wt[i]; j--) {
      dp[j] = max(dp[j], dp[j - wt[i]] + val[i]);
    }
  }
  
  return dp[W];
}


int main(){
  int n;
  while(cin >> n && n != 0){

    int max;
    cin >> max;

    vector<int> tempo;
    vector<int> pizzas;
    int temp1, temp2;
    for(int i = 0; i < n; i++){
      cin >> temp1 >> temp2;
      tempo.push_back(temp1);
      pizzas.push_back(temp2);
    }

    cout << knapsack(max, tempo, pizzas) << " min." << endl;

  }
}