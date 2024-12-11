// 4) A prefeitura de uma cidade fez uma pesquisa entre os seus habitantes, coletando dados sobre o salário e número de filhos. Faça uma função que leia esses dados para um número não determinado de pessoas e retorne a média de salário da população, a média do número de filhos, o maior salário e o percentual de pessoas com salário até R$350,00.

#include <stdio.h>
#include <stdlib.h>

typedef struct {
  float salario;
  int n_de_filhos;
} Pessoa;

void calculaMediaSalarial(Pessoa* habitantes, int tamanho, int* media){
  int sum = 0;
  for(int i = 0; i < tamanho; i++){
    sum += habitantes[i].salario;
  }
  *media = sum / tamanho;
}

int main(){

  int tamanho = 0, capacidade = 1;
  Pessoa* habitantes = malloc(capacidade * sizeof(Pessoa));

  while(1){
    int n_filhos, salario;
    scanf("%d %d", &n_filhos, &salario);

    if(n_filhos == -1 && salario == -1) break;

    if(tamanho == capacidade){
      capacidade++;
      habitantes = realloc(habitantes, capacidade * sizeof(Pessoa));
    }

    Pessoa habitante;
    habitante.n_de_filhos = n_filhos;
    habitante.salario = salario;
    habitantes[tamanho] = habitante;
    tamanho++;
  }

  int media;
  calculaMediaSalarial(habitantes, tamanho, &media);
  printf("%d \n", media);

  // fazer outros calculos

}