#include "../include/posfixa.hpp"

#include <cctype>

#include "../include/fila.hpp"
#include "../include/pilha.hpp"
#include <iostream>

int posfixa(Fila<char> &entrada) {
  Pilha<int> pilha(entrada.capacidade);

  while (!entrada.esta_vazia()) {
    char token = entrada.desenfileirar();

    if (std::isdigit(token)) {
      pilha.empilhar(token - '0');
    } else {
      if (pilha.esta_vazia())
        throw std::runtime_error("erro de operador, pilha vazia");
      int b = pilha.desempilhar();

      if (pilha.esta_vazia())
        throw std::runtime_error("erro de operador, pilha vazia");
      int a = pilha.desempilhar();

      int resultado;

      switch (token) {
        case '+':
          resultado = a + b;
          break;
        case '-':
          resultado = a - b;
          break;
        case '*':
          resultado = a * b;
          break;
        case '/':
          if (b == 0)
            throw std::runtime_error("um elemento esta vazio, divicao por 0");
          resultado = a / b;
          break;
        default:
          throw std::runtime_error(
              std::string("operador invalido, ou nao reconhecido") + token);
      }
      pilha.empilhar(resultado);
    //   std::cout<<"pilha"<<pilha.topo();
    }
  }
    if (pilha.esta_cheia()) throw std::runtime_error ("a pilha esta cheia");

    if (pilha.esta_vazia()) throw std::runtime_error("ERRO, pilha esta vazia");
        int resultado = pilha.desempilhar();

    return resultado;
}