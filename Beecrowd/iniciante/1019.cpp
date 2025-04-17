#include <stdio.h>
#include <math.h>

int main() {

  int input_seconds;
  scanf("%d", &input_seconds);
  
  int hours = input_seconds / 3600;
  int left_seconds = input_seconds % 3600;
  int minutes = left_seconds / 60;
  int seconds = left_seconds % 60;
  
  printf("%d:%d:%d\n", hours, minutes, seconds);
    
}