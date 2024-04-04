#include <stdio.h>

int main(){
  int number;
  scanf("%i", &number);
  int month_work_hours;
  scanf("%i", &month_work_hours);
  float dollars_per_hour;
  scanf("%f", &dollars_per_hour);

  printf("NUMBER = %i \n", number);
  printf("SALARY = U$ %.2f \n", dollars_per_hour * month_work_hours);

  return 0;
}