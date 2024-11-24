#include <iostream>
#include <vector>

using namespace std;

int main(){

  int t;
  cin >> t;
  while(t--){

    int n, m;
    cin >> n >> m;

    vector<int> gifts;
    for(int i = 0; i<n; i++){
      int temp;
      cin >> temp;
      gifts.push_back(temp);
    }

    int travels = 0;
    while(gifts.size() != 0){
      int sum = 0;
      for(int i = 0; i < gifts.size(); i++){
        if(sum + gifts[i] <= m){
          sum+=gifts[i];
          gifts.erase(gifts.begin()+i);
          i--;
          if(sum == m) break;
        } else if(sum + gifts[i] > m){
          break;
        }
      }
      travels++;
    }
    cout << travels << endl;

  }

  return 0;
}

/*

2 362
234 97
1

6 260
187 85 101 154 199 24
4

3 884
252 120 97
1

1 114
112
1

4 245
190 59 126 97
1


*/