/******************************************************************************
Autor: Carolina da Silva Santos
Data: 16/08/2023
Objetivo: Mostrar o nº elemento da sequência de Fibonacci
*******************************************************************************/
//Bibliotecas
#include <stdio.h>
#include <stdlib.h>

//Protótipos
int recursao (int);
void mostraFibonacci (int);

int main () {
    //Declarações locais
	int posicao, elemento;
	
	//Entrada de dados
	printf("Insira a posição do elemento na sequência de Fibonacci: ");
	scanf("%d", &posicao);
	
	//Chamada da sub-rotina
	elemento = recursao(posicao);
	
	//Saída de dados
	printf("O elemento localizado na %dº posição é %d\n", posicao, elemento);
	mostraFibonacci(posicao);
	return 0;
}

/* 
  Nome: recursao
  Objetivo: Encontrar o nº elemento da sequência de Fibonacci
  Parâmetro Formais
  - n: Posição do elemento que deseja-se encontrar
  Valor de retorno: nº elemento da sequência de Fibonacci
*/
int recursao (int n) {
    int resultado;
    if (n == 1 || n == 2)
        return 1;
    else if (n >= 3) {
        resultado = recursao(n - 1) + recursao(n - 2);
        return resultado;
    }
}

/* 
  Nome: mostraFibonacci
  Objetivo: Mostrar todos os elementos da sequência de Fibonacci
            até o nº elemento
  - n: Posição do último elemento
  Valor de retorno: Todos os elementos da sequência até o elemento n
*/
void mostraFibonacci (int n) {
    int sequencia[n];
    sequencia[0] = 1;
    sequencia[1] = 1;
    for (int s = 2; s <= n; s++) {
        sequencia[s] = sequencia[s-1] + sequencia [s-2];
    }
    //Printando a sequência
    for (int i = 0; i < n; i++) {
        printf("%d ", sequencia[i]);
    }
}
