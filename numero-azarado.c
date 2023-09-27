/******************************************************************************
Autor: Carolina da Silva Santos
Data: 30/08/23
Objetivo: Verificar se um número é azarado (má sorte) ou não
*******************************************************************************/
//Bibliotecas
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

//Declarações globais
#define max 20

//Protótipos de sub-rotinas
bool analisaNumero(char []);

int main()
{
    //Declarações locais
    bool ehMaSorte; //Valor booleano dizendo se um número é azarado ou não
    char numero[max]; //Char que vai conter o número lido
    
    //Entrada do numero a ser analisado
    scanf("%s", numero);
    
    //Chamada da sub-rotina analisaNumero para verificar se um número é azarado ou não
    ehMaSorte = analisaNumero(numero);
    
    //Caso ehMaSorte seja igual a "true", o número é azarado. Caso contrário, não é azarado
    if (ehMaSorte) {
        printf("%s eh azarado\n", numero);
    }
    else {
        printf("%s NAO eh azarado\n", numero);
    }
    return 0;
}

//Sub-rotinas
/* 
  Nome: analisaNumero
  Objetivo: Verificar se um número é azarado (má sorte) ou não
  Parâmetros:
  - a: Char que contém o número a ser analisado
*/
bool analisaNumero(char a[]) {
    bool ehMaSorte = false;
    for (int i = 0; i < strlen(a); i++) {
        if (i != 0) {
            if (a[i-1] == '1' && a[i] == '3') {
                ehMaSorte = true;
                break;
            } 
        } 
    }
    return ehMaSorte;
}
