// A primeira linha de um caso de teste contém dois números inteiros G e P separados por um espaço em branco, indicando respectivamente o número de Grandes Prêmios (1 ≤ G ≤ 100) e o número de pilotos (1 ≤ P ≤ 100). 
// Os pilotos são identificados por inteiros de 1 a P. Cada uma das G linhas seguintes indica o resultado de uma corrida, e contém P inteiros separados por espaços em branco. Em cada linha, o i-ésimo número indica a ordem de chegada do pilodo i na corrida (o primeiro número indica a ordem de chegada do piloto 1 naquela corrida, o segundo número indica a ordem de chegada do piloto 2 na corrida, e assim por diante). 
// A linha seguinte contém um único número inteiro S indicando o número de sistemas de pontuação (1 ≤ S ≤ 10), e após, cada uma das S linhas seguintes contém a descrição de um sistema de pontuação. A descrição de um sistema de pontuação inicia com um inteiro K (1 ≤ K ≤ P), indicando a última ordem de chegada que receberá pontos, seguido de um espaço em branco, seguido de K inteiros k0, k1, ... , kn−1 (1 ≤ ki ≤ 100) separados por espaços em branco, indicando os pontos a serem atribuídos (o primeiro inteiro indica os pontos do primeiro colocado, o segundo inteiro indica os pontos do segundo colocado, e assim por diante).

// Para cada caso de sistema de pontuação da entrada seu programa deve imprimir uma linha, que deve conter o identificador do Campeão Mundial de Pilotos. Se houver mais de um Campeão Mundial Pilotos (ou seja, se houver empate), a linha deve conter todos os Campeões Mundiais de Pilotos, em ordem crescente de identificador, separados por um espaço em branco.

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> leResultados(int corridas, int pilotos){
  vector<vector<int>> resultados;
  while(corridas--){
    vector<int> corrida;
    for(int j = 0; j < pilotos; j++){
      int posicao;
      cin >> posicao;
      corrida.push_back(posicao);
    }
    resultados.push_back(corrida);
  }
  return resultados;
}

vector<vector<int>> leSistemas(){
  int num_sistemas;
  cin >> num_sistemas;

  vector<vector<int>> sistemas;
  while(num_sistemas--){
    int last_position;
    cin >> last_position;
    
    vector<int> sistema;
    while(last_position--){
      int ponto;
      cin >> ponto;
      sistema.push_back(ponto);
    }
    sistemas.push_back(sistema);
  }
}

int main(){
  int corridas, pilotos;
  while(cin >> corridas >> pilotos && corridas != 0 && pilotos != 0){
    vector<vector<int>> resultados = leResultados(corridas, pilotos);
    vector<vector<int>> sistemas = leSistemas();
  }
  return 0;
}

/*
  TEST CASE 1:
  1 3
  3 2 1
  3
  3 5 3 2
  3 5 3 1
  3 1 1 1


  3
  3
  1 2 3

  TEST CASE 2:
  3 10
  1 2 3 4 5 6 7 8 9 10
  10 1 2 3 4 5 6 7 8 9
  9 10 1 2 3 4 5 6 7 8
  2
  5 5 4 3 2 1
  3 10 5 1


  3
  3

  TEST CASE 3:
  2 4
  1 3 4 2
  4 1 3 2
  2
  3 3 2 1
  3 5 4 2


  2 4
  4
*/