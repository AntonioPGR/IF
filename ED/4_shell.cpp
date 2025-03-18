#include <iostream>
#include <vector>

using namespace std;

int main(){

  vector<int> a= {4, 8, 1, 0, 9, 0, 2, 7, 3, 6};

  for(int i = 0; i < a.size(); i++){
    cout << a.at(i) << " ";
  }
  cout << endl;

  // ShellSort 
  // 
  // Melhor: O(n logn)
  // Médio: O(n logn)
  // Pior: O(n2) 
  int n, gap, i, j, temp;
  n = a.size();
  for(gap=n/2; gap >0; gap /= 2){
    for(j = gap; j < n; j += 1){
      temp = a.at(j);
      for(i = j; i >= gap &&  a.at(i-gap) > temp; i -= gap){
        a.at(i) = a.at(i - gap);
      }
      a.at(i) = temp;
    }
  }

  for(int i = 0; i < a.size(); i++){
    cout << a.at(i) << " ";
  }
  cout << endl;

}