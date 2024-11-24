#include <iostream>
#include <vector>

using namespace std;

struct Carta{
  int valor;
  char naipe;
};

struct Anao {
  int valor;
  char naipe;
  char faz;
};

int mudarCartaParaPontos(char card){
  int value;
  switch (card){
    case '4': value = 10;
      break;
    case '5': value = 20;
      break;
    case '6': value = 30;
      break;
    case '7': value = 40;
      break;
    case 'Q': value = 50;
      break;
    case 'J': value = 60;
      break;
    case 'K': value = 70;
      break;
    case 'A': value = 80;
      break;
    case '2': value = 90;
      break;
    case '3': value = 100;
      break;
  }
  return value;
}

int mudarPontosParaVira(char naipe){
  int value;
  switch (naipe){
    case 'O': value = 201;
      break;
    case 'E': value = 202;
      break;
    case 'C': value = 203;
      break;
    case 'P': value = 204;
      break;
  }
  return value;
}

int main(){
  
  vector<Anao> anoes;
  for(int i = 0; i < 7; i++){
    string card;
    char faz;
    cin >> card >> faz;
    Anao anao;
    anao.valor = mudarCartaParaPontos(card.at(0));
    anao.naipe = card.at(1);
    anao.faz = faz;
    anoes.push_back(anao);
  }

  string card;
  cin >> card;
  Carta vira;
  vira.valor = mudarCartaParaPontos(card.at(0));
  vira.naipe = card.at(1);

  int winner_points = 0;
  for(Anao &anao : anoes){
    if(anao.valor == (vira.valor + 10) || anao.valor == (vira.valor - 90)){
      anao.valor = mudarPontosParaVira(anao.naipe);
    }
    if(anao.valor > winner_points) winner_points = anao.valor;
  }

  int total_of_winners = 0;
  int total_of_losers = 0;
  for(int i = 1; i < anoes.size(); i++){
    Anao anao = anoes.at(i);
    if(
      (anao.valor == winner_points && anao.faz == 'S')
      ||
      (anao.valor != winner_points && anao.faz == 'N')
    ) total_of_winners++;
    else if(
      (anao.valor == winner_points && anao.faz == 'N')
      ||
      (anao.valor != winner_points && anao.faz == 'S')
    ) total_of_losers++;
  }

  bool dengoso_ganhou = false;
  if(
    (anoes.at(0).valor == winner_points && anoes.at(0).faz == 'S')
    ||
    (anoes.at(0).valor != winner_points && anoes.at(0).faz == 'N')
  ) dengoso_ganhou=true;

  if(
    (dengoso_ganhou && total_of_winners == 0) 
    ||
    (!dengoso_ganhou && total_of_losers == 0)
  ) cout << "Ficou envergonhado." << endl;
  else cout << "Nao ficou envergonhado." << endl;

  return 0;
}

/*

4  5  6  7  Q  J  K  A  2  3
10 20 30 40 50 60 70 80 90 100

O E C P
201 202 203 204



Quando ele perde pontos sozinho, ele fica envergonhado. Mas quando ele é o único que não perde pontos, ele também fica envergonhado. Sua tarefa é verificar se Dengoso ficará envergonhado ou não.

A entrada contém 7 expressões do tipo "CN X" em que C é o valor da carta, N é o naipe (já pré-definidos na descrição do problema) e X indicando S caso o jogador faça a rodada, ou N caso contrário. 
A primeira expressão representa a carta de Dengoso e se ele ganha a rodada ou não, as 6 seguintes dos outros 6 anões. 
A última linha contém uma expressão "CN" que indica a carta vira. 
No jogo, não existem duas cartas iguais.

Contém apenas uma frase do tipo "Ficou envergonhado." ou "Nao ficou envergonhado.".


4P N
3O N
KC N
AE N
5E N
7C N
QP N
3C

Ficou envergonhado.

5E S  
4E S  
6C S  
7P S  
QC S  
JE S  
KE S  
4O  
*/