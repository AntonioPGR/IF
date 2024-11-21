#include <iostream>
#include <cmath>

using namespace std;

struct Magia{
  int dano;
  int raio;
};

Magia calculaMagia(string tipo, int nivel){
  Magia magia;
  if (tipo == "fire") {
    magia.dano = 200;
    if(nivel == 1) magia.raio = 20;
    else if(nivel == 2) magia.raio = 30;
    else if(nivel == 3) magia.raio = 50;
  } else if (tipo == "water") {
    magia.dano = 300;
    if(nivel == 1) magia.raio = 10;
    else if(nivel == 2) magia.raio = 25;
    else if(nivel == 3) magia.raio = 40;
  } else if (tipo == "earth") {
    magia.dano = 400;
    if(nivel == 1) magia.raio = 25;
    else if(nivel == 2) magia.raio = 55;
    else if(nivel == 3) magia.raio = 70;
  } else{
    magia.dano = 100;
    if(nivel == 1) magia.raio = 18;
    else if(nivel == 2) magia.raio = 38;
    else if(nivel == 3) magia.raio = 60;
  }
  return magia;
}

int main(){
  int casos_de_teste;
  cin >> casos_de_teste;

  int w, h, x0, y0, nivel, cx, cy;
  string magia;
  for(int i = 0; i < casos_de_teste; i++){
    int w, h, x0, y0;
    cin >> w >> h >> x0 >> y0;

    string tipoMagia;
    int nivel, cx, cy;
    cin >> tipoMagia >> nivel >> cx >> cy;

    int nearestX = max(x0, min(cx, x0 + w));
    int nearestY = max(y0, min(cy, y0 + h));

    int dx = cx - nearestX;
    int dy = cy - nearestY;
    double distancia = sqrt(dx * dx + dy * dy);

    Magia mg = calculaMagia(tipoMagia, nivel);

    if(distancia < mg.raio) cout << mg.dano << endl;
    else cout << 0 << endl;

  }

}