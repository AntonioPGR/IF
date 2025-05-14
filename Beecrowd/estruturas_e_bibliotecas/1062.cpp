#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int main(){

  int n;
  while(cin >> n && n != 0){
    while(true){
      queue<int> ordem_desejada;
      queue<int> fila;
      int temp;
      for(int i = 0; i < n; i++){
        cin >> temp;
        if(i == 0 && temp == 0) break;
        ordem_desejada.push(temp);
        fila.push(i+1);
      }

      if(ordem_desejada.size() == 0) break;

      bool possible = true;
      stack<int> pilha;
      while(!ordem_desejada.empty()){
        int next = ordem_desejada.front();
        ordem_desejada.pop();

        if(!pilha.empty() && pilha.top() == next){
          pilha.pop();
          continue;
        }

        if(!pilha.empty() && fila.empty()){
          possible = false;
          break;
        }

        if(!fila.empty() && fila.front() == next){
          fila.pop();
          continue;
        }

        if(next < fila.front()){
          possible = false;
          break;
        }

        while(!fila.empty() && fila.front() != next){
          pilha.push(fila.front());
          fila.pop();
        }
        fila.pop();
      };

      if(possible) cout << "Yes" << endl;
      else cout << "No" << endl;
    }
    cout << endl;
  }

}