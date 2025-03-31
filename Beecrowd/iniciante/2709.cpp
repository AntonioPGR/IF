#include <iostream>
#include <vector>

using namespace std;

bool teste(int n){ 
	if (n == 1) return false;
	for (int i = 2; i * i <= n; i++){
		if (n % i == 0) return false;
	}
	return true;
}

int main(){
  int m;
  while(cin >> m){

    vector<int> coins(m);
    for(int i = 0; i < m; i++){
      cin >> coins[i];
    }

    int n;
    cin >> n;

    int sum = 0;
    for(int i = coins.size() - 1; i >= 0; i -= n){
      sum += coins[i];
    }

    if(teste(sum)) cout << "You’re a coastal aircraft, Robbie, a large silver aircraft." << endl;
    else cout << "Bad boy! I’ll hit you." << endl;

  }
}