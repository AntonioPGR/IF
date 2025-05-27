#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main(){
  long long M;
  cin>>M;
  M *= 8;
  M *= pow(10,6);

  cout << ceil(log2(M)) << endl;

  return 0;
}