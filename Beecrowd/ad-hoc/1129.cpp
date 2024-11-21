#include <iostream>

using namespace std;

int main(){

  char respostas[] = {'A', 'B', 'C', 'D', 'E'};

  int n;
  while(cin >> n && n!=0){
    while(n--){
      int count = 0, pos = 0, temp;
      for(int i = 0; i < 5; i++){
        cin >> temp;
        if(temp <= 127){
          count++;
          pos = i;
        }
      }
      if(count == 1) cout << respostas[pos] << endl;
      else cout << "*" << endl;
    }
  }

  return 0;
}