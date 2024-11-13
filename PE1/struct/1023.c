#include <stdio.h>

typedef struct _casa{
  int moradores;
  int consumo;
} casa;

int main(){
  int n_de_casas, moradores, consumo;

  for(int i = 0; i >= 0; i++){
    moradores = 0;
    consumo = 0;

    scanf("%d", &n_de_casas);
    if(n_de_casas == 0) break;
    casa vetor_de_casas[n_de_casas];

    for(int j = 0; j < n_de_casas; j++){
      scanf("%d %d", &vetor_de_casas[j].moradores, &vetor_de_casas[j].consumo);
      moradores += vetor_de_casas[j].moradores;
      consumo += vetor_de_casas[j].consumo;
    }

    printf("Cidade #%d\n", i);
    for(int j = 0; j < n_de_casas; j++){
      float consumo_medio = vetor_de_casas[j].consumo / vetor_de_casas[j].moradores;
      printf("%d-%.2f ", vetor_de_casas[j].moradores, consumo_medio);
    }
    
    float consumo_medio_geral = consumo/moradores;
    printf("\nConsumo medio: %.2f", consumo_medio_geral);

  }

  return 0;
}