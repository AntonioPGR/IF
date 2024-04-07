#include <stdio.h>

void main(){

  float n1 = readGrade(1);
  float n2 = readGrade(2);
  float n3 = readGrade(3);
  float n4 = readGrade(4);

  float media = (n1*1 + n2*2 + n3*3 +n4*4)/10;

  printf("Media: %.2f", media);

}

float readGrade(int grade_num){
  float grade;
  printf("Digite a %d° nota: ", grade_num);
  scanf("%lf", grade);
  return grade;
}