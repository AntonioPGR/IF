#include <iostream>

using namespace std;

int main(){

  int n_linhas, n_colunas, pokemon_line, pokemon_column, my_line, my_column, temp;

  while(cin >> n_linhas >> n_colunas){
    for(int i = 0; i < n_linhas; i++){
      for(int j = 0; j < n_colunas; j++){
        cin >> temp;
        if(temp == 1){
          my_line = i;
          my_column = j;
        } else if(temp == 2){
          pokemon_line = i;
          pokemon_column = j;
        }
      }
    }

    cout << abs(my_line - pokemon_line) + abs(my_column - pokemon_column) << endl;
  }

}