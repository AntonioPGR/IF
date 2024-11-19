#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main(){

  int t, n, index, sum;
  string str;
  vector<int> steps;

  cin >> t;
  while(t--){
    steps.clear();
    cin >> n;
    while(n--){
      cin >> str;
      if(str == "LEFT"){
        steps.push_back(-1);
      } else if(str == "RIGHT"){
        steps.push_back(1);
      } else {
        cin >> str >> index;
        steps.push_back(steps.at(index-1));
      }
    }

    sum = 0;
    for(int i : steps) sum+= i;

    cout << sum << endl;

  }
}