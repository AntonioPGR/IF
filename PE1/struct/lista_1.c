#include <stdio.h>
#include <string.h>

typedef struct _Admissao{
  int dia;
  int mes;
  int ano;
} Admissao;

typedef struct _Funcionario{
  char name[20];
  char cargo[20];
  float salario;
  Admissao admissao;
} Funcionario;

int main(){

  int n;
  char tmp;
  printf("Digite o numero de funcionarios: ");
  scanf("%d", &n);
  scanf("%c", &tmp);
  
  printf("\n--- CADASTRO ---\n");
  Funcionario funcionarios[n];
  for(int i = 0; i < n; i++){
    printf("Funcionario %d.\n", i+1);
    printf("Digite o nome: ");
    fgets(funcionarios[i].name, sizeof(funcionarios[i].name), stdin);
    funcionarios[i].name[strlen(funcionarios[i].name)-1] = '\0';

    printf("Digite o cargo: ");
    fgets(funcionarios[i].cargo, sizeof(funcionarios[i].cargo), stdin);
    funcionarios[i].cargo[strlen(funcionarios[i].cargo)-1] = '\0';

    printf("Digite o salario: ");
    scanf("%f", &funcionarios[i].salario);
    scanf("%c", &tmp);

    printf("Digite o dia, mes e ano de admissão: ");
    scanf("%d %d %d", &funcionarios[i].admissao.dia, &funcionarios[i].admissao.mes, &funcionarios[i].admissao.ano);
    scanf("%c", &tmp);

    printf("\n");
  }

  char search[20];
  printf("\n--- BUSCA ---\n");
  while(1){
    printf("Digite o name do funcionário que deseja pesquisar: [-1 para sair]\n");
    fgets(search, sizeof(search), stdin);
    search[strlen(search)-1] = '\0';
    
    if(strcmp(search,"-1") == 0){
      break;
    }

    int finded = 0;
    for(int i = 0; i < n; i++){
      if(strcmp(search, funcionarios[i].name) == 0){
        Funcionario f = funcionarios[i];
        printf("\nInformações do funcionario:\nNome: %s\nCargo: %s\nSalario: %.2f\nTempo de empresa (anos): %d\n\n", f.name, f.cargo, f.salario, 2024 - f.admissao.ano);
        finded = 1;
      }
    }
    if(finded == 0) printf("\nNão encontramos nenhum funcionario com esse name!\n\n");
  }

  return 0;
}