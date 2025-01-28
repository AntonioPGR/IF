#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int calculateTabuas(int c, int l, vector<int> tabuas){
  // tem c linhas com l de comprimento
  int lines_count = 0;
  for(int i = 0; i < tabuas.size(); i++){
    // int biggest = 
  }
}

int main(){
  int m, n;
  while(cin >> m >> n && n != 0){
    int l_tabuas, k;
    cin >> l_tabuas;
    cin >> k;

    vector<int> tabuas;
    while(k--){
      int temp;
      cin >> temp;
      tabuas.push_back(temp);
    }

    sort(tabuas.begin(), tabuas.end());

    int num_tabuas = 0;
    if(m%l_tabuas==0){
      num_tabuas = calculateTabuas(m, n, tabuas);
    }
    if(n%l_tabuas==0){
      int temp = calculateTabuas(n, m, tabuas);
      if(temp < l_tabuas){
        num_tabuas = temp;
      }
    }

    cout << num_tabuas << endl;

  }
}

/*

5x4

A entrada contém vários casos de teste. A primeira linha de um caso de teste contém dois inteiros M e N indicando as dimensões, em metros, do salão (1 ≤ N,M ≤ 104). 
A segunda linha contém um inteiro L, representando a largura das tábuas, em centímetros(1 ≤ L ≤ 100). 
A terceira linha contém um inteiro, K, indicando o número de tábuas doadas (1 ≤ K ≤ 105). 
A quarta linha contém K inteiros Xi, separados por um espaço, cada um representando o comprimento, em metros, de uma tábua (1 ≤ Xi ≤ 104 para 1 ≤ i ≤ K). 
O final da entrada é indicado por uma linha que contém apenas dois zeros, separados por um espaço em branco.  

Saída
Para cada um dos casos de teste da entrada, seu programa deve imprimir uma única linha, contendo o menor número de tábuas necessário para cobrir todo o piso do salão, obedecendo às restrições estabelecidas. Caso não seja possível cobrir todo o piso do salão obedecendo às restrições estabelecidas, imprima uma linha com a palavra ‘impossivel’ (letras minúsculas, sem acento).  

*/