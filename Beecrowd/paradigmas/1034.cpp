#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int blocos(vector<int> &val, int goal){

  if(goal % val.back() == 0) return goal / val.back();

  vector<int> pd(goal + 1, 999999);
  pd[0] = 0;
  for(int i = 0; i < val.size(); i++){
    int k = val[i];
    for(int j = k; j <= goal; j++){
      pd[j] = min(pd[j], pd[j-k] + 1);
    }
  }

  return pd[goal];
}

int main(){

  int n;
  cin >> n;
  while(n--){
    int types_amount, goal;
    cin >> types_amount >> goal;

    vector<int> sizes(types_amount);
    for(int i = 0; i < types_amount; i++){
      cin >> sizes[i];
    }
    sort(sizes.begin(), sizes.end());
    int amount = blocos(sizes, goal);

    cout << amount << endl;
  }
}