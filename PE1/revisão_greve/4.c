#include <stdio.h>

int main(){

  int init_h, init_m, end_h, end_m;
  scanf("%d %d %d %d", &init_h, &init_m, &end_h, &end_m);

  int elapsed_minutes = end_m - init_m;
  if(elapsed_minutes < 0){
    elapsed_minutes += 60;
    end_h --;
  }

  int elapsed_hours = end_h - init_h;
  if(elapsed_hours < 0){
    elapsed_hours += 24;
  }

  if(elapsed_hours == 0 && elapsed_minutes == 0){
    elapsed_hours = 24;
  }
  
  printf("O JOGO DUROU %d HORA(S) E %d MINUNTO(S)\n", elapsed_hours, elapsed_minutes);

  return 0;

}