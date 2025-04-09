#include <iostream>
#include <math.h>

using namespace std;

int main(){

  double a, b, c;
  cin >> a >> b >> c;

  double delta = (b*b) - (4*a*c);
  if(delta < 0 || a == 0){
    cout << "Impossivel calcular"<< endl;
  } else {
    double raiz1 = (-b + sqrt(delta)) / (2 * a);
    double raiz2 = (-b - sqrt(delta)) / (2 * a);

    cout << fixed;
    cout.precision(5);
    cout << "R1 = " << raiz1 << endl;
    cout << "R2 = " << raiz2 << endl;
    
  }

  return 0;
}