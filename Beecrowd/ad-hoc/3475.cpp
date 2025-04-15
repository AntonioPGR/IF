#include <iostream>

using namespace std;

int main(){
  string value;
  cin >> value;

  for(int i = 0; i < value.size(); i++){
    value[i] = tolower(value[i]);
  }
  
  if(value[0] == '0') cout << "zero" << endl;
  else if(value[0] == '1') cout << "um" << endl;
  else if(value[0] == '2') cout << "dois" << endl;
  else if(value[0] == '3') cout << "tres" << endl;
  else if(value[0] == '4') cout << "quatro" << endl;
  else if(value[0] == '5') cout << "cinco" << endl;
  else if(value[0] == '6') cout << "seis" << endl;
  else if(value[0] == '7') cout << "sete" << endl;
  else if(value[0] == '8') cout << "oito" << endl;
  else if(value[0] == '9') cout << "nove" << endl;

  else if(value[0] == 'z') cout << "0" << endl;
  else if(value[0] == 'u') cout << "1" << endl;
  else if(value[0] == 'd') cout << "2" << endl;
  else if(value[0] == 't') cout << "3" << endl;
  else if(value[0] == 'q') cout << "4" << endl;
  else if(value[0] == 'c') cout << "5" << endl;
  else if(value[0] == 's' && value[2] == 'i') cout << "6" << endl;
  else if(value[0] == 's' && value[2] == 't') cout << "7" << endl;
  else if(value[0] == 'o') cout << "8" << endl;
  else if(value[0] == 'n') cout << "9" << endl;

}