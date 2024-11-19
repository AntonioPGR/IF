#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){

  int qnt_titans, tita_p, tita_m, tita_g, tamanho_muralha;
  string ordem_titans;

  cin >> qnt_titans >> tamanho_muralha;
  cin >> ordem_titans;
  cin >> tita_p >> tita_m >> tita_g;

  reverse(ordem_titans.begin(), ordem_titans.end());
  vector<int> muralhas = {tamanho_muralha};
  for(char tita : ordem_titans){
    int vida_tirada;
    switch (tita){
      case 'P': vida_tirada = tita_p;
        break;
      case 'M': vida_tirada = tita_m;
        break;
      case 'G': vida_tirada = tita_g;
        break;
    }
    for(int i = 0; i < muralhas.size(); i++){
      if(vida_tirada <= muralhas.at(i)){
        muralhas.at(i) -= vida_tirada;
        break;
      } else if(vida_tirada > muralhas.at(i) && i+1 == muralhas.size()){
        muralhas.push_back(tamanho_muralha - vida_tirada);
        break;
      }
    }
  }

  if(muralhas.at(muralhas.size()-1) == 0) muralhas.push_back(tamanho_muralha);

  cout << muralhas.size() << endl;

}


/*
3 20
MPG
3 8 10
2
----
8 20
MGGPGGGP
3 8 10
4
----
4 6
GPMP
3 4 5
3
----
30 20
PPMMGPGGMMPMGPMMGGGGPPMMPGMPPP
5 7 9
12
---
10 30
MMMMMGPMGG
6 10 24
6

---
1000 650
MGGGPPPGPPPMPMMGMGMGMPGMPMGPPMGGMMMMPGPGGGGGPPGMGGGGPGPPPPGGPMMGGMMPGPPPGGGMPPGMGMGPPMGPPPMMGPPGPPPMPPGGPGPPMMPMMMPGMPGPPMMGGMMMPGMPMPMGGPMGGMPMPGGMMMPMGMMMGMGPGGMMGMMGPMGGMGGPMMMPPGGPMMMGMMPGGGMPPGMPPMMPGGMMGGMMPPGGGMGPPMPGGPGMPPGMGPGPGMPPPMPPPMPPGPMPMGGPPPPPMMGMMMPGGPPGGMMMGGGMMMPMPPPGPGPGPMGPMMPPPPGMMPPPPPGPPGMMGPGGPPMPMGGGPGPMPPMGMGMMPMGPMPMMMPGGGMPPPGMPMPPPGPPMPPGPPGMMMGGMPPPGGMGGGPGGPMPGMGGMGGMPGPMGMPMPMPMMGGGMMMGPPMPPPGMPPMGGGMPMPPPMPGGMMPGMMGGPGPGGMMMMGMPPMGMPPGMPMPGGPPGGMMPPGMMPPPMPGMGMPGGGMPGPMPGPMMMMPGMGGPGPGGGGGPPPGMMMMPMPMMPPMMMPGMGGPPMPMPGPGGGGMMPPPPGMMGGPMPGPMMGPMPMGMMPGMGPPGPPPGGGPGMMPPMMGMMPGMGPPGMGMPPPMPMMPGPPMPGGPMPMMPPPGMGMPPPMGMPMMPGGPPPMGGGPPPMGPGMMPGMGPGMGPPPMGGGMMGGPMGGGPPPPPMGMGGMMMGPGMPGPMGMMMGGMPGGMMMGPMMGPMPMGGPPMGGGGMGMPGMMMPGMPPPPPMGGMPPGMMPGGPPMPPMPGPMMGGMGMPGGGPPMGPMMGPPMPGPMMMPGMPGMGMGGMGGPMGGMMPPGPMPGPMMMPMPGGGMMGGMGMMMGMPGGMGGGPMGPPGMGPMMPPPGGGGGMGGPPPMPGMGGMGGGGGPGGMMPMPMPGGGPGPMGMPPGGPGMMPGGPMGMPMPGGPPGMGMPPMPPGGGMMGPMGMMPMPGMPPGMGGMMPPGMPGGGMGMGMPP
57 148 265
252
*/