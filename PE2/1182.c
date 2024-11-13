#include <stdio.h> 

int main() {
  
  int line, lenght = 12;
  char op;
  float matriz[lenght][lenght], temp, sum=0;

  scanf("%d", &line);
  
  scanf("%c", &op);
  if(op == '\n') scanf("%c", &op);

  for(int i = 0; i < lenght; i++){
    for(int j = 0; j < lenght; j++){
      scanf("%f", &temp);
      matriz[i][j] = temp;
    }
  }

  for(int i = 0; i < lenght; i++){
    sum += matriz[i][line];
  }

  if(op == 83) printf("%.1f\n", sum);
  else printf("%.1f\n", sum/lenght);

  return 0;
}
