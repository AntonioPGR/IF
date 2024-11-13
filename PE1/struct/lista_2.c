#include <stdio.h>
#include <string.h>

typedef struct _produto{
  int id;
  char desc[20];
  int stock_amount;
  float price;
} product;

void showProducts(product products[5], int n){
  printf("DESC | ID | QUANTIDADE | PRECO\n");
  for(int i = 0; i < n; i++){
    product current = products[i];
    printf("%s | %d | %d | %.2f\n", current.desc, current.id, current.stock_amount, current.price);
  }
}

int main(){

  int n;
  char tmp;
  printf("Quantidade de produtos: ");
  scanf("%d", &n);
  scanf("%c", &tmp);

  printf("\n--- CADASTRO ---\n");
  product products[n];
  for(int i = 0; i < n; i++){
    printf("Produto %d.\n", i+1);
    printf("Descricao: ");
    fgets(products[i].desc, sizeof(products[i].desc), stdin);
    products[i].desc[strlen(products[i].desc)-1] = '\0';
    printf("Codigo: ");
    scanf("%d", &products[i].id);
    scanf("%c", &tmp);
    printf("Quantidade em estoque: ");
    scanf("%d", &products[i].stock_amount);
    scanf("%c", &tmp);
    printf("Preco: ");
    scanf("%f", &products[i].price);
    scanf("%c", &tmp);
    printf("\n");
  }

  printf("--- MANIPULAR ESTOQUE ---\n");
  int id, quantity;
  while(id != -1){
    showProducts(products, n);
    printf("Adicione / Remova o produto (id quantidade) [id = -1 para parar]: ");
    scanf("%d %d", &id, &quantity);
    scanf("%c", &tmp);
    for(int i = 0; i < n; i++){
      if(products[i].id == id){
        products[i].stock_amount += quantity;
      }
    }
    printf("\n");
  }

  printf("\n--- CONTROLE DE ESTOQUE ---\n");
  showProducts(products, n);

  float stock_value = 0;
  for(int i = 0; i < n; i++){
    stock_value += products[i].stock_amount * products[i].price;
  }
  printf("\nValor em estoque: R$%.2f\n", stock_value);

  return 0;
}


