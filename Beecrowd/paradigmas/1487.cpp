#include <iostream>
#include <vector>

using namespace std;

int unboundedKnapSack(int capacity, vector<int> &val, vector<int> &wt) {
  vector<int> dp(capacity + 1, 0);

  for (int i = val.size() - 1; i >= 0; i--) {
    for (int j = 1; j <= capacity; j++) {

      int take = 0;
      if (j - wt[i] >= 0) {
        take = val[i] + dp[j - wt[i]];
      }
      int noTake = dp[j];

      dp[j] = max(take, noTake);
    }
  }

  return dp[capacity];
}

int main(){

  int n, t, instance = 1;
  while(cin >> n >> t && n != 0){

    vector<int> tempo(n), nota(n);
    for(int i = 0; i < n; i++){
      cin >> tempo[i] >> nota[i];
    }

    int amount = unboundedKnapSack(t, nota, tempo);

    cout << "Instancia " << instance << endl;
    cout << amount << endl << endl;

    instance++;

  }

}