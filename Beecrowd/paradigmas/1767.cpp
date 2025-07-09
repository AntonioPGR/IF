#include <iostream>
#include <vector>

using namespace std;

pair<int, int> knapsack(int w_max, vector<int> &v, vector<int> &w) {
  vector<int> dp(w_max + 1, 0);
  for (int i = 0; i < w.size(); i++) {
    for (int j = w_max; j >= w[i]; j--) {
      dp[j] = max(dp[j], dp[j-w[i]] + v[i]);
    }
  }
  int best = w_max;
  while(dp[best] == dp[best-1]) best--;
  return make_pair(dp[w_max], best);
}


int main(){
  int n;
  cin >> n;
  while(n--){
    int pac;
    cin >> pac;
    vector<int> qt(pac), peso(pac);
    for(int i = 0; i < pac; i++){
      cin >> qt[i] >> peso[i];
    }

    pair<int,int> result = knapsack(50, qt, peso);

    cout << result.first << " " << result.second << endl;
  }
  return 0;
}