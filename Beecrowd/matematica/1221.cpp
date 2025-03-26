#include <iostream>

using namespace std;

bool teste(int n){ // O(sqrt(N))
	if (n == 1) return false;
	for (int i = 2; i*i <= n; i++){
		if (n%i == 0) return false;
	}
	return true;
}

int main(){

  int n;
  cin >> n;

  while(n--){

    int t;
    cin >> t;

    if(teste(t)) cout << "Prime" << endl;
    else cout << "Not Prime" << endl; 

  }

}