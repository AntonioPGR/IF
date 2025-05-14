#include <iostream>

using namespace std;

int trebonacci(int n){
  if(n == 0) return 0;
  if(n <= 2) return 1;

  int t0 = 0;
  int t1 = 1;
  int t2 = 1;
  int cur = 0;
  for(int i = 3; i <= n; i++){
    cur = t0 + t1 + t2;
    t0 = t1;
    t1 = t2;
    t2 = cur;
  }

  return cur;
}

int main(){

  int n;
  cin >> n;

  

}