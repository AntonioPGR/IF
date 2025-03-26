#include <iostream>

using namespace std;

int main(){

  int n, m;
  long n_fat, m_fat;
  while(cin >> n >> m){

    n_fat = 1;
    m_fat = 1;

    for(int i = 1; i <= n; i++){
      n_fat *= i;
    }

    for(int i = 1; i <= m; i++){
      m_fat *= i;
    }

    long sum = n_fat + m_fat;

    cout << sum << endl;

  }

  return 0;
}