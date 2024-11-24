#include <iostream>
#include <cmath>

using namespace std;

string normalizeNumber(string str){
  string normalized = str;
  while(normalized.size() > 4){
    normalized.erase(normalized.begin());
  }
  while(normalized.size() < 4){
    normalized.insert(0, "0");
  }
  return normalized;
}

int main(){

  double valor;
  string n, m;
  while(cin >> valor >> n >> m && valor != 0){
    
    string formated_n = normalizeNumber(n);
    string formated_m = normalizeNumber(m);

    double multiplicador = 0;
    if(formated_m.at(3) == formated_n.at(3) && formated_m.at(2) == formated_n.at(2)){
      multiplicador = 50;
      if(formated_m.at(1) == formated_n.at(1)){
        multiplicador = 500;
        if(formated_m.at(0) == formated_n.at(0)){
          multiplicador = 3000;
        }
      }
    }

    if(multiplicador == 0){
      double n_group = double(stoi(string(1, formated_n.at(2)) + string(1, formated_n.at(3))));
      double m_group = double(stoi(string(1, formated_m.at(2)) + string(1, formated_m.at(3))));
      if(
        ceil(n_group/4.0) == ceil(m_group/4.0) ||
        n_group == 0 && m_group >= 97 ||
        m_group == 0 && n_group >= 97
      ){
        multiplicador = 16;
      }
    }

    double result = valor * multiplicador;

    cout << fixed;
    cout.precision(2);
    cout << result << endl;

  }

}

/*

Se M e N têm os mesmos quatro últimos dígitos (milhar, centena, dezena e unidade), o apostador recebe V × 3000 (por exemplo, N = 99301 e M = 19301);
Se M e N têm os mesmos três últimos dígitos (centena, dezena e unidade), o apostador recebe V × 500 (por exemplo, N = 38944 e M = 83944);
Se M e N têm os mesmos dois últimos dígitos (dezena e unidades), o apostador recebe V × 50 (por exemplo, N = 111 e M = 552211);
Se M e N têm os dois últimos dígitos no mesmo grupo, correspondendo ao mesmo animal, o apostador recebe V × 16 (por exemplo, N = 82197 and M = 337600);
Se nenhum dos casos acima ocorrer, o apostador não recebe nada.

74.580 588411 318411
Ta dando: 372900.00
Deve dar: 223740.00

*/