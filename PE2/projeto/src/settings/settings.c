#include <stdio.h>
#include <locale.h>
#ifdef _WIN32
#include <windows.h> 
#endif

void loadSettings() {
  setlocale(LC_ALL, "en_US.UTF-8");
  #ifdef _WIN32
  SetConsoleOutputCP(65001);
  #endif
}