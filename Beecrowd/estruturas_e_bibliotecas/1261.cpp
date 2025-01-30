#include <iostream>
#include <unordered_map>
#include <cctype>

using namespace std;

string limpaPalavra(const string &str){
  string result;
  for(char c : str){
    if(isalpha(c)) result += c;
  }
  return result;
}

int main(){
  int m, n;
  cin >> m >> n;

  unordered_map<string, float> cargos;

  for(int i = 0; i < m; i++){
    string cargo;
    float salario;
    cin >> cargo >> salario;
    cargos[cargo] = salario;
  }

  for(int i = 0; i < n; i++){
    string palavra;
    int soma = 0;
    while(cin >> palavra && palavra != "."){
      string palavra_limpa = limpaPalavra(palavra);
      if(cargos.count(palavra_limpa)){
        soma += cargos[palavra_limpa];
      }
    }
    cout << soma << endl;
  }

  return 0;
}
