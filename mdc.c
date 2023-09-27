/******************************************************************************
Autor: Carolina da Silva Santos
Data: 16/08/2023
Objetivo: Encontrar o máximo divisor comum (MDC) entre dois números
*******************************************************************************/
//Bibliotecas
#include <stdio.h>

// Protótipos
int mdc(int, int);

int main() {
    //Declarações locais
    int num1, num2;
    
    //Entrada de dados
    printf("Digite dois números inteiros: ");
    scanf("%d %d", &num1, &num2);
    
    //Chamada da sub-rotina mdc
    int resultado = mdc(num1, num2);
    
    //Saída de dados
    printf("O MDC de %d e %d é: %d\n", num1, num2, resultado);
    
    return 0;
}

/* 
  Nome: mdc
  Objetivo: Encontrar o máximo divisor comum (MDC) entre dois
            números por meio de uma sub-rotina recursiva
  - n: Posição do elemento que deseja-se encontrar
  Valor de retorno: MDC entre dois números
*/
int mdc(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return mdc(b, a % b);
    }
}
