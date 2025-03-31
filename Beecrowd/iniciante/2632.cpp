#include <iostream>
#include <cmath>

using namespace std;

int getRadius(string magic, int level){
  if(magic == "fire") switch (level){
    case 1: return 20;
    case 2: return 30;
    case 3: return 50;
  }
  if(magic == "water") switch (level){
    case 1: return 10;
    case 2: return 25;
    case 3: return 40;
  }
  if(magic == "earth") switch (level){
    case 1: return 25;
    case 2: return 55;
    case 3: return 70;
  }
  if(magic == "air") switch (level){
    case 1: return 18;
    case 2: return 38;
    case 3: return 60;
  }
}

int getDamage(string magic){
  if(magic == "fire") return 200;
  if(magic == "water") return 300;
  if(magic == "earth") return 400;
  if(magic == "air") return 100;
}

int main(){
  int t;
  cin >> t;
  while (t--){
    // Canto inferior esquerdo
    int w, h, x0, y0;
    cin >> w >> h >> x0 >> y0;

    string magic;
    int n, cx, cy;
    cin >> magic >> n >> cx >> cy;

    int radius = getRadius(magic, n);

    int px = max(x0, min(cx, x0+w));
    int py = max(y0, min(cy, y0+h));

    int d = (px - cx) * (px - cx) + (py - cy) * (py - cy);

    if(d <= radius * radius) cout << getDamage(magic) << endl;
    else cout << 0 << endl;

  }
}