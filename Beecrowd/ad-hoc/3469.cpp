#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
  int n;
  cin >> n;

  vector<int> v(n);
  for(int i = 0; i < n; i++) cin >> v[i];

  sort(v.begin(), v.end());

  if(n % 2 == 1){
    int pos = n / 2;
    cout << v[pos] << endl;
  } else {
    int n1 = v[n/2];
    int n2 = v[(n-1)/2];
    int media = (n1 + n2) / 2;
    cout << media << endl;
  }
}