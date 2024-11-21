#include <iostream>

using namespace std;

int main(){

  int k;
  while(cin >> k && k!=0){
    int n, m;
    cin >> n >> m;
    while(k--){
      int x, y;
      cin >> x >> y;
      if(x == n || y == m) cout << "divisa";
      else if(x > n && y > m) cout << "NE";
      else if(x > n && y < m) cout << "SE";
      else if(x < n && y > m) cout << "NO";
      else if(x < n && y < m) cout << "SO";
      cout << endl;
    }
  }
}