#include <iostream>

using namespace std;

int main(){

  int n, temp;

  while(cin >> n && n != 0){
    int contador_de_toques = 0;
    int posicao_atual = 2;

    for(int i = 0; i < n; i++){
      int n1, n2, n3;
      cin >> n1 >> n2 >> n3;
      if(n1 != 0 || n2 != 0 || n3!= 0){
        if(n1 == 0 && posicao_atual != 1){
          contador_de_toques++;
          if(posicao_atual == 3) contador_de_toques++;
          posicao_atual = 1;
        }else if(n2 == 0 && posicao_atual != 2){
          contador_de_toques++;
          posicao_atual = 2;
        }else if(n3 == 0 && posicao_atual != 3){
          contador_de_toques++;
          if(posicao_atual == 1) contador_de_toques++;
          posicao_atual = 3;
        }
      }
    }
    cout << contador_de_toques << endl;
  }
}