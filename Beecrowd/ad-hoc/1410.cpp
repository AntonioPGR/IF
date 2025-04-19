#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

  int a, d;
  while(cin >> a >> d){
    if(a == d && a == 0) break;

    vector<int> attackers(a);
    for(int i = 0; i < a; i++){
      cin >> attackers[i];
    }
    sort(attackers.begin(), attackers.end());

    vector<int> defensors(d);
    for(int i = 0; i < d; i++){
      cin >> defensors[i];
    }
    sort(defensors.begin(), defensors.end());

    if(attackers[0] >= defensors[1]) cout << "N" << endl;
    else cout << "Y" << endl;
  }

  return 0;
}