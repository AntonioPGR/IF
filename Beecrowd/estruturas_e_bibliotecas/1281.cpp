#include <iostream>
#include <map>
#include <string>


using namespace std;

int main(){

  int n;
  cin >> n;
  while(n--){
    map<string, float> products;
    string s;

    int m;
    float price;
    cin >> m;
    for(int i = 0; i < m; i++){
      cin >> s >> price;
      products[s] = price;
    }

    int p, amount;
    float total = 0;
    cin >> p;
    for(int i = 0; i < p; i++){
      cin >> s >> amount;
      total += products[s] * amount;
    }

    cout << fixed;
    cout.precision(2);
    cout << "R$ " << total << endl;

  }

}