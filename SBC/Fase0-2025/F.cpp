#include <iostream>
#include <vector>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> n_numbers(n);
  for(int i = 0; i < n; i++) cin >> n_numbers[i];

  int q, max_q;
  cin >> q;
  vector<int> q_numbers(q);
  for(int j = 0; j < q; j++){
    cin >> q_numbers[j];
    if(j == 0) max_q = q_numbers[j];
    else if(q_numbers[j] > max_q) max_q = q_numbers[j];
  }

  vector<int> q_result(q, 0);
  int count = 0;
  for(int a1 = 0; a1 < n - 3; a1++){
    for(int a2 = a1 + 1; a2 < n - 2; a2++){
      for(int a3 = a2 + 1; a3 < n - 1; a3++){
        for(int a4 = a3 + 1; a4 < n; a4++){
          int value = n_numbers[a1] + n_numbers[a2] + n_numbers[a3] + n_numbers[a4];
          for(int i = 0; i < q_numbers.size(); i++){
            if(value == q_numbers[i]) q_result[i]++;
          }
        }
      }
    }
  }

  for(int v : q_result) cout << v << endl;

  return 0;
}