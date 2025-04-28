#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main(){
  int n, m;
  while(cin >> n >> m){
    map<int, vector<int>> numbers;
    int temp;
    for(int i = 0; i < n; i++){
      cin >> temp;
      numbers[temp].push_back(i+1);
    }

    int k, v;
    for(int i = 0; i < m; i++){
      cin >> k >> v;  
      if(
        (numbers.find(v) == numbers.end()) ||
        (numbers[v].size() < k)
      ){
        cout << 0 << endl;
        continue;
      }
      cout << numbers[v][k-1] << endl;
    }
  }

  return 0;
}