#!/bin/bash
CLASS=$1
LAB=$2
SUSY="https://susy.ic.unicamp.br:9999/$CLASS/$LAB/dados"

echo "Compilando o programa..."
gcc -std=c99 -pedantic -Wall -Werror *.c -o lab${LAB} -lm
if [ $? -ne 0 ]; then
  echo "Erro na compilação. Abortando testes."
  exit
fi

mkdir -p "inputs"
mkdir -p "outputs"

echo "Baixando os testes..."

for i in 0{1..9} {10..15};
do
  if [ ! -f "inputs/arq$i.in" ]
  then
    curl -ks "$SUSY/arq$i.in" -o "inputs/arq$i.in"
  fi
  if [ ! -f "outputs/arq$i.out" ]
  then
    curl -ks "$SUSY/arq$i.out" -o "outputs/arq$i.out"
  fi
done

echo "Executando os testes..."

for i in 0{1..9} {10..15};
do
  ./lab${LAB} < inputs/arq${i}.in > outputs/${i}.out
  DIFF=$(diff outputs/arq${i}.out outputs/${i}.out)
  if [ "$DIFF" != "" ]; then
    echo "Teste ${i}: ERRO"
    echo "Saída esperada:"
    cat outputs/arq${i}.out
    echo "Saída do seu programa:"
    cat outputs/${i}.out
  else
    echo "Teste ${i}: OK"
  fi
  printf "\n\n"
done

