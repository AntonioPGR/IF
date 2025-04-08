#include <iostream>
#include <math.h>

using namespace std;

int main(){

  int C, L, R1, R2;
  while(cin >> L >> C >> R1 >> R2 && C != 0){

    if (2 * R1 > L || 2 * R1 > C || 2 * R2 > L || 2 * R2 > C) {
      cout << "N" << endl;
      continue;
    }

    int maxX = L - R1 - R2; 
    int maxY = C - R1 - R2;
    double dist = sqrt(maxX * maxX + maxY * maxY);

    if (dist >= R1 + R2) 
      cout << "S" << endl;
    else 
      cout << "N" << endl;
  }

  return 0;
}