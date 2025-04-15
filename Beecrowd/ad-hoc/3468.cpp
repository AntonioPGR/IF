#include <iostream>

using namespace std;

int main(){

  string l;
  cin >> l;
  for(int i = 0; i < l.size(); i++){
    l[i] = tolower(l[i]);
  }

  if(
    l == "oposicao" ||
    l == "contrariedade"
  ) cout << "mas" << endl;
  else cout << "mais" << endl;
  
  return 0;
}