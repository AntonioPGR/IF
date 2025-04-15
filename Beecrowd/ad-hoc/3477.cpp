#include <iostream>
#include <cmath>

using namespace std;

int main(){
  float x, y, z;
  cin >> x >> y >> z;

  if(((y*y) + (z*z)) != (x*x)){
    cout << "Nao eh retangulo!" << endl;
  } else {
    float r = z / 2;
    float semicirculo = (3 * r * r) / 2;
    float triangulo = (z*y) / 2;

    cout << "AREA = " << floor(semicirculo + triangulo) << endl;
  }
}