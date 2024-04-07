#include <stdio.h>

void main(){
  printHeader();
  printLine();
  printStudentGrade("ALINE   ", 9);
  printStudentGrade("MARIO   ", 10);
  printStudentGrade("SÉRGIO  ", 4.5);
  printStudentGrade("SHIRLEY ", 7);
}

void printHeader(){
  printf("ALUNO(A)          NOTA\n");
}

void printLine(){
  printf("========          =====\n");
}

void printStudentGrade(char name[], float grade){
  printf("%s          %.2f\n", name, grade);
}