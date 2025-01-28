#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Ligacao{
  int x;
  int y;
  bool operator<(const Ligacao& other) const {
    return x < other.x || (x == other.x && y < other.y);
  }
};

int main(){

  int segmentos, n_ligacoes;
  cin >> segmentos >> n_ligacoes;

  vector<Ligacao> ligacoes_separadas;
  while(n_ligacoes--){
    Ligacao l;
    cin >> l.x >> l.y;
    ligacoes_separadas.push_back(l);
  }

  sort(ligacoes_separadas.begin(), ligacoes_separadas.end());

  vector<vector<int>> ligacoes;
  for(Ligacao l :ligacoes_separadas){
    int added = false;
    for(int i = 0; i < ligacoes.size(); i++){
      if(ligacoes.at(i).at(ligacoes.at(i).size()-1) == l.x){
        ligacoes.at(i).push_back(l.y);
        added=true;
        break;
      }
    }
    if(!added){
      ligacoes.push_back({l.x, l.y});
    }
  }

  int is_completed = true;
  for(vector<int> ligacao : ligacoes){
    if(ligacao.at(0) != 1){
      is_completed = false;
      break;
    }
  }

  if(is_completed) cout << "COMPLETO" << endl;
  else cout << "INCOMPLETO" << endl;

}
