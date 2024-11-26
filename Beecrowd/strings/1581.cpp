#include <iostream>
#include <vector>

using namespace std;

int main(){
  int n;
  cin >> n;
  while(n--){
    int k;
    cin >> k;
    vector<string> idiomas;
    while(k--){
      string temp;
      cin >> temp;
      idiomas.push_back(temp);
    }
    bool unique = true;
    string idioma_inicial = idiomas.at(0);
    for(int i = 1; i < idiomas.size(); i++){
      if(idioma_inicial != idiomas.at(i)){
        unique = false;
        break;
      }
    }
    if(unique) cout << idioma_inicial << endl;
    else cout << "ingles" << endl;
  }
}