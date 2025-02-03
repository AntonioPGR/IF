#include <iostream>
#include <vector>

using namespace std;

int main(){

  int n;
  cin >> n;
  while(n--){

    int m, c;
    cin >> m >> c;
    vector<vector<int>> map(m, vector<int>());
    for(int i = 0; i < c; i++){
      int key;
      cin >> key;
      map.at(key % m).push_back(key);
    }

    int idx = 0;
    for(vector<int> i : map){
      cout << idx << " -> ";
      for(int j : i){
        cout << j << " -> ";
      }
      cout << "\\" << endl;
      idx++;
    }

    if (n > 0) cout << endl;
  }

  return 0;
}

