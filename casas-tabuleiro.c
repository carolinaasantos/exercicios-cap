/******************************************************************************
Autor: Carolina da Silva Santos
Data: 30/08/23
Objetivo: Verificar a quantidade de casas brancas e pretas de um tabuleiro de xadrez
*******************************************************************************/
//Bibliotecas
#include <stdio.h>
#include <math.h>

//Declarações globais
//Struct de dados de um tabuleiro de xadrez
typedef struct {
    int tamanho, casasBrancas, casasPretas;
} tXadrez;

//Protótipos de sub-rotinas
void verificaCasas (tXadrez*);

int main() {
    //Declarações locais
    tXadrez tabuleiro;
    
    //Entrada de dados do tamanho de um tabuleiro
    scanf("%d", &tabuleiro.tamanho);
    
    //Chamada da sub-rotina para verificar a quantidade de casas brancas e pretas
    verificaCasas(&tabuleiro);
    
    //Saída de dados com a quantidade de casas brancas e pretas
    printf("%d casas brancas e %d casas pretas\n", tabuleiro.casasBrancas, tabuleiro.casasPretas);
    return 0;
}

/* 
  Nome: verificaCasas
  Objetivo: Encontrar a quantidade de casas brancas e pretas de um tabuleiro de xadrez
  Parâmetros:
  - *a: Ponteiro do tipo struct tXadrez que irá alterar a quantidade de casas brancas e pretas de
    um determinado tabuleiro
*/
void verificaCasas (tXadrez *a) {
    a->casasPretas = pow(a->tamanho, 2)/2;
    a->casasBrancas = pow(a->tamanho, 2) - a->casasPretas;
}
