#include <iostream>
#include <vector>

using namespace std;

int knapsack(int W, vector<int> &val, vector<int> &wt) {
  // Representa o valor máximo que pode ser obtido usando uma capacidade j da mochila
  vector<int> dp(W + 1, 0);

  // Percorre o vetor de items disponiveis
  for (int i = 0; i < wt.size(); i++) {
    // Percorre os pesos do maior para o menor
    for (int j = W; j >= wt[i]; j--) {
      // Aqui temos duas escolhas: incluir o item ou nao
      // Se não, mantem o atual (dp[j]) 
      // Se incluir, Adicionamos o item val[i-1] e a mochila tera a capacidade de j - wt[i-1]
      dp[j] = max(dp[j], dp[j - wt[i]] + val[i]);
    }
  }
  
  return dp[W];
}

int main(){
  vector<int> val = {15, 23, 21, 16, 19, 18};
  vector<int> wt = {5, 4, 2, 4, 5, 2};
  int W = 10;

  cout << knapsack(W, val, wt) << endl;

  return 0;
}