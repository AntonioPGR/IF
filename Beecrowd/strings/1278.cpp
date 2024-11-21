#include <iostream>
#include <vector>

using namespace std;

string trim(string str){
  str.erase(str.find_last_not_of(' ')+1);        
  str.erase(0, str.find_first_not_of(' '));      
  return str;
}

string removeMiddleSpaces(string str){
  for(int i = 0; i < str.size(); i++){
    if((i == 0 && str.at(i) == ' ') || (i > 0 && str.at(i-1) == ' ' && str.at(i) == ' ')){
      str.erase(str.begin() + i);
      i--;
    }
  }
  return str;
}

string cleanStr(string str){
  string cleaned_string = trim(str);
  cleaned_string = removeMiddleSpaces(cleaned_string);
  return cleaned_string;
}

int main(){

  int c = 0;
  int n;
  while(cin >> n && n!=0){
    vector<string> lines;
    
    if(c != 0) {
      cout << endl;
    } else {
      c++;
    }

    do{
      string temp;
      getline(cin, temp);
      lines.push_back(temp);
    } while(n--);

    vector<string> cleaned_lines;
    int biggest_string_size = 0;
    for(string line : lines){
      string clean = cleanStr(line);
      cleaned_lines.push_back(clean);
      if(clean.size() > biggest_string_size) biggest_string_size = clean.size();
    }

    for(string line : cleaned_lines){
      if(line.size() == 0) continue;
      for(int i = 0; i < biggest_string_size - line.size(); i++) cout << " ";
      cout << line << endl;
    }

  }

}

/*

Entrada
A primeira linha de cada caso de teste contém um inteiro N (1 ≤ N ≤ 100) que indica o número de linhas de texto que virão a seguir. 
Cada uma destas N linhas de texto contém de 1 a 50 letras maiúsculas (‘A’-‘Z’) ou espaços (‘ ’). 
Todas as linhas de texto contém no mínimo uma letra. 
Poderá haver mais de um espaço entre as palavras. 
É também possível haver espaços no início e no final da linha. O fim da entrada é indicado por N = 0.

Saída
Para cada caso de teste imprima o texto com apenas um espaço entre as palavras, e inserindo tantos espaços quanto forem necessários à esquerda de cada linha do texto, para que elas apareçam alinhadas à margem direita daquele texto, e na mesma ordem da entrada. Deixe uma linha em branco entre os casos de testes. Não imprima espaços no final de cada linha, nem espaços desnecessários à esquerda, de modo que pelo menos uma das linhas impressa em cada texto inicie com uma letra.

3
     ROMEO      AND
      JULIET WERE  
        IN LOVE    

  ROMEO AND
JULIET WERE
    IN LOVE


4
WHO
ELSE
LOVES
STAIRS

   WHO
  ELSE
 LOVES
STAIRS


3
A TEXT CAN BE JUSTIFIED
ON   BOTH   SIDES    OR
JUST   TO   THE   RIGHT


A TEXT CAN BE JUSTIFIED
       ON BOTH SIDES OR
      JUST TO THE RIGHT


0
*/