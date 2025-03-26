#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

  int n;
  cin >> n;

  vector<int> pares, impares;
  while(n--){
    
    int temp;
    cin >> temp;
    if(temp % 2 == 0) pares.push_back(temp);
    else impares.push_back(temp);

  }

  sort(pares.begin(), pares.end());
  sort(impares.begin(), impares.end(), greater<>());

  for(auto i : pares) cout << i << endl;
  for(auto i : impares) cout << i << endl;

  return 0;
}