#include <iostream>
#include <vector>

using namespace std;

int main(){

  vector<int> valores;
  int n=1, temp, maior=0, menor=0;
  while(n!=0){
    valores.clear();
    maior = 0;
    menor = 0;
    cin >> n;
    if(n == 0) break;
    for(int i = 0; i < 2*n; i++){
      cin >> temp;
      valores.push_back(temp);
    }
    for(int i = 0; i < n; i++){
      int end_value = valores.at(valores.size()-1-i);
      int start_value = valores.at(i);
      int sum = end_value + start_value;
      if(sum > maior || maior == 0) maior = sum;
      if(sum < menor || menor == 0) menor = sum;
    }
    cout << maior << " " << menor << endl;
  }

  return 0;
}
