#include <iostream>
#include <vector>

using namespace std;

int knapsack(int W, vector<int> &val, vector<int> &wt){
  vector<int> dp(W+1, 0);

  for(int i = 0; i < wt.size(); i++){
    for(int j = W; j >= wt[i]; j--){
      dp[j] = max(dp[j], dp[j - wt[i]] + val[i]);
    }
  }

  return dp[W];
}

int main(){

  int cases;
  cin >> cases;
  while(cases--){

    int n;
    cin >> n;

    vector<int> power(n), weight(n);
    for(int i = 0; i < n; i++){
      cin >> power[i] >> weight[i];
    }

    int k, r;
    cin >> k >> r;

    int damage = knapsack(k, power, weight);

    if(damage >= r) cout << "Missao completada com sucesso" << endl;
    else cout << "Falha na missao" << endl;

  }

}