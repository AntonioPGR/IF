#include <iostream>
#include <queue>

using namespace std;

int main(){

  int rounds;
  while(cin >> rounds && rounds != 0){
    queue<int> mark;
    for(int i = 0; i < rounds; i++){
      int temp;
      cin >> temp;
      mark.push(temp);
    }
    queue<int> leti;
    for(int i = 0; i < rounds; i++){
      int temp;
      cin >> temp;
      leti.push(temp);
    }

    int last_m = 0, count_m = 0, points_m = 0;
    int last_l = 0, count_l = 0, points_l = 0;
    bool already_earned = false;

    for(int i = 0; i < rounds; i++){
      if(i == 0) {
        count_m++;
        last_m = mark.front();
      } else if(last_m == mark.front()) count_m++;
      else {
        last_m = mark.front();
        count_m = 1;
      }
      points_m += mark.front();
      mark.pop();

      if(i == 0) {
        count_l++;
        last_l = leti.front();
      } else if(last_l == leti.front()) count_l++;
      else {
        last_l = leti.front();
        count_l = 1;
      }
      points_l += leti.front();
      leti.pop();

      if(count_m == 3 && count_l == 3) already_earned = true;
      else if(count_m == 3 && !already_earned){
        points_m += 30;
        already_earned = true;
      } else if(count_l == 3 && !already_earned){
        points_l += 30;
        already_earned = true;
      }
    }


    if(points_m == points_l) cout << "T";
    else if(points_m > points_l) cout << "M";
    else cout << "L";
    cout << endl;
  }

}