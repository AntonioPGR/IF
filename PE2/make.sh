#!/bin/bash

# Verifica se um nome foi passado como argumento
if [ "$#" -ne 1 ]; then
    echo "Uso: $0 nome_do_projeto"
    exit 1
fi

# Nome do projeto
PROJETO=$1

# Cria o arquivo main.cpp
cat <<EOL > "$PROJETO.c"
#include <stdio.h> 

int main() {

  return 0;
}
EOL

