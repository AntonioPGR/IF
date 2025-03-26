#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int main(){

  int n;
  while(cin >> n && n != 0){
    
    deque<int> dq;
  	
    // 1 = topo, n = fundo
    for(int i = 1; i <= n; i++){
      dq.push_back(i);
    }

    vector<int> discarted;
    while(dq.size() >= 2){
      discarted.push_back(dq.front());
      dq.pop_front();
      dq.push_back(dq.front());
      dq.pop_front();
    }

    cout << "Discarded cards:";
    for(int i = 0; i < discarted.size() - 1; i++){
      cout << " " << discarted[i] << ",";
    }
    cout << " " << discarted[discarted.size() - 1] << endl;

    cout << "Remaining card: " << dq.front() << endl;

  }

  return 0;
}