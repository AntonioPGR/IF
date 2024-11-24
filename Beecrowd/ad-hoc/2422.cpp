#include <iostream>
#include <vector>

using namespace std;

int main(){

  int n;
  cin >> n;

  vector<int> numbers;
  while(n--){
    int temp;
    cin >> temp;
    numbers.push_back(temp);
  }

  int sum = 0;
  cin >> sum;

  int left = 0, right = numbers.size() - 1;
  int n1 = 0, n2 = 0;

  while (left < right) {
    int current_sum = numbers[left] + numbers[right];
    if (current_sum == sum) {
      n1 = numbers[left];
      n2 = numbers[right];
      break;
    } else if (current_sum < sum) {
      left++;
    } else {
      right--;
    }
  }

  if(n1 < n2) cout << n1 << " " << n2 << endl;
  else cout << n2 << " " << n1 << endl;

}

/*

A soma dos números das casas em que escondi teus brinquedos é igual a K. Além disso, escolhi as casas de tal forma que não existe outro par de casas cuja soma tenha esse mesmo valor.

A primeira primeira linha da entrada contém um número inteiro N (2 ≤ N ≤ 105), que representa o número de casas que existem na rua. Cada uma das N linhas seguintes contém um número inteiro, representando o número de uma casa (Para cada casa Ci , 0 ≤ Ci ≤ 109 , i = 1, 2, . . . , N). Note que esses N números estão ordenados, do menor para o maior. A última linha da entrada contém um inteiro K, que é a soma dos números das duas casas onde os brinquedos estão escondidos , (os números das casas estão em ordem crescente, do menor para o maior número, e casas distintas têm números distintos).

CASO 1:
4
1
2
3
5
8

3 5

CASO 2:
4
1
2
3
5
5

2 3

CASO 3:
4
1
4
4
5
8

4 4

*/