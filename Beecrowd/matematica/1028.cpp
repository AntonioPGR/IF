#include <iostream>

using namespace std;

int mdc(int n1, int n2){
  if(n1 % n2 == 0){
    return n2;
  } else {
    return mdc(n2, n1%n2);
  }
}

int main(){

  int n;
  cin >> n;

  while(n--){

    int f1, f2;
    cin >> f1 >> f2;

    int result = mdc(f1, f2);

    cout << result << endl;

  }

  return 0;
}