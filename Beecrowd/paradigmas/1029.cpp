#include <iostream>

using namespace std;

int calls = 0;

int fibonacci(int n){
  calls++;
  if(n == 0) return 0;
  if(n == 1) return 1;
  return fibonacci(n-1) + fibonacci(n-2);
}

int main(){

  int n;
  cin >> n;

  while(n--){

    calls = -1;

    int temp;
    cin >> temp;

    int result = fibonacci(temp);

    cout << "fib(" << temp << ") = " << calls << " calls = " << result << endl;

  }

}