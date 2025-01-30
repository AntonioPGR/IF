#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

  int n;
  cin >> n;
  
  while(n--){
    int m;
    cin >> m;

    vector<int> fila_chegada;
    for(int i = 0; i < m; i++){
      int temp;
      cin >> temp;
      fila_chegada.push_back(temp);
    }

    vector<int> fila_saida = fila_chegada;
    sort(fila_saida.begin(), fila_saida.end(), greater<>());
    
    int count = 0;
    for(int i = 0; i < m; i++){
      if(fila_chegada[i] == fila_saida[i]) count++;
    }
    cout << count << endl;
  }

  return 0;
}