#include <iostream>
#include <vector>

using namespace std;

int main(){
  int t;
  cin >> t;
  while(t--){

    int d, ingr, b;
    cin >> d >> ingr >> b;

    vector<int> ingredients_price(ingr);
    for(int i = 0; i < ingr; i++){
      cin >> ingredients_price[i];
    }

    int q, max_cakes = 0, price;
    for(int i = 0; i < b; i++){
      cin >> q;
      price = 0;
      for(int j = 0; j < q; j++){
        int index, amount;
        cin >> index >> amount;
        price += ingredients_price[index] * amount;
      }
      if((d / price) > max_cakes) max_cakes = (d / price);
    }

    cout << max_cakes << endl;
  }
}