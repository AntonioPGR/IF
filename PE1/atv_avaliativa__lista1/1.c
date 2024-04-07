#include <stdio.h>

void main(){
  displayFullLine();
  displayBorders();
  displayBorders();
  displayBorders();
  displayFullLine();
}

void displayFullLine(){
  printf("XXXXX\n");
}

void displayBorders(){
  printf("X   X\n");
}