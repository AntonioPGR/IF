#include <iostream>
#include <vector>

using namespace std;

int main(){
  
  int n_pontos, n_medicoes, compr_min;
  while(cin >> n_pontos >> n_medicoes >> compr_min && n_pontos != 0){
    vector<vector<int>> dados(n_medicoes, vector<int>(n_pontos, 0));
    for(int i = 0; i < dados.size(); i++){
      for(int j = 0; j < dados.at(i).size(); j++){
        int temp;
        cin >> temp;
        dados.at(i).at(j) = temp;
      }
    }
    int n_palitos = 0;
    for(int j = 0; j < dados.at(0).size(); j++){
      bool resetou = true;
      int count = 0;
      for(int i = 0; i < dados.size(); i++){
        if(dados.at(i).at(j) == 1)count ++; 
        else {
          count = 0;
          resetou = true;
        }
        if(count >= compr_min && resetou) {
          resetou = false;
          n_palitos++;
        }
      }
    }

    cout << n_palitos << endl;
  }
}

/*

Uma sequência ininterrupta de bits 1 de um mesmo ponto de processamento ao longo do tempo é denominada de palito. O comprimento de um palito é o número de bits 1 que o compõe (note que o comprimento dos palitos de um experimento pode variar entre um e o número de medições efetuadas). Uma característica importante de um experimento com o CBD é a quantidade e o comprimento dos palitos gerados. A figura abaixo mostra o resultado de um experimento realizado com um CBD de seis pontos de processamento, em que foram efetuadas quatro medições, contendo três palitos de comprimento um, um palito de comprimento dois e um palito de comprimento quatro.


Entrada
A entrada contém vários casos de teste. A primeira linha de um caso de teste contém três inteiros P, N e C que indicam respectivamente o número de pontos de processamento (1 ≤ P ≤ 1000), o número de medições efetuadas (1 ≤ N ≤ 1000) e o comprimento mínimo de palitos de interesse (1 ≤ C ≤ N). Cada uma das próximas N linhas contém sequências de P dígitos {0, 1}, separados por um espaço em branco. O final da entrada é indicado por P = N = C = 0.

Saída
Para cada caso de teste da entrada seu programa deve produzir uma única linha da saída, contendo o número de palitos de comprimento maior ou igual a C produzidos pelo experimento.

CASO 1:
2 2 2
1 1
1 1

2


CASO 2:
4 5 3
0 1 0 1
1 1 1 1
1 0 0 1
1 0 1 1
1 1 0 0
0 0 0

2
*/