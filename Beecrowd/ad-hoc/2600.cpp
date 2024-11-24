#include <iostream>
#include <vector>

using namespace std;

int main(){

  int n;
  cin >> n;
  while(n--){
    vector<int> faces;
    for(int i = 0; i < 6; i++){
      int temp;
      cin >> temp;
      faces.push_back(temp);
    }

    vector<bool> numbers(6, false);
    for(int face : faces){
      if(face <= 6 && face >= 1){
        numbers.at(face-1) = true;
      }
    }

    bool has_all_numbers = true;
    for(bool number : numbers){
      if(!number){
        has_all_numbers = false;
        break;
      }
    }

    if(
      has_all_numbers && 
      faces.at(0) + faces.at(5) == 7 && 
      faces.at(1) + faces.at(3) == 7 &&
      faces.at(2) + faces.at(4) == 7
    ) cout << "SIM" << endl;
    else cout << "NAO" << endl;

  }
}

/*


3
5 2 2 5
4

0
1 5 6 2
7
4
5 1 6 2
3
2
1 5 6 2
5
4
1 5 6 2
1000
4
6 1 1 6
3
1
3 5 4 2
6
5
3 5 4 2
2
5
3 1 4 6
2

NAO
NAO
NAO
NAO
NAO
NAO
SIM
NAO
SIM

*/