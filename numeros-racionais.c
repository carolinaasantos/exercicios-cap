/******************************************************************************
Autor: Carolina da Silva Santos
Data: 02/08/2023
Objetivo: Realizar operações com números racionais
*******************************************************************************/
//Bibliotecas
#include <stdio.h>

//Declarações globais
typedef struct {
    int n; // numerador
    int d; // denominador
} tRacional;

//Protótipos
int MDC (int, int);
int MMC(int, int);
void lerNumero (tRacional*);
void simplificarNumero (int *, int *);
void escreverNumero (tRacional);
void somarNumeros (tRacional, tRacional);
void subtrairNumeros (tRacional, tRacional);
void multiplicarNumeros (tRacional, tRacional);
void dividirNumeros (tRacional, tRacional);

int main()
{
    //Declarações locais
    tRacional numero1;
    tRacional numero2;
    
    //Leitura e escrita dos números
    lerNumero(&numero1);
    escreverNumero(numero1);
    
    lerNumero(&numero2);
    escreverNumero(numero2);
    
    //Soma de dois números racionais
    somarNumeros (numero1, numero2);
    
    //Subtração de dois números racionais
    subtrairNumeros (numero1, numero2);
    
    //Multiplicação de dois números racionais
    multiplicarNumeros (numero1, numero2);
    
    //Divisão de dois números racionais
    dividirNumeros (numero1, numero2);
    
    return 0;
}

//Sub-rotinas
//Calcular o MDC (Máximo Divisor Comum)
int MDC(int n, int d) {
    int resto;
    do {
        resto = n % d;
        n = d;
        d = resto;
    } while (resto != 0);
    return n; //Retorna o máximo divisor comum
}

//Calcular o MMC (Mínimo Múltiplo Comum)
int MMC(int d1, int d2) {
    int resto, a, b;
    a = d1;
    b = d2;
    do {
        resto = a % b;
        a = b;
        b = resto;
    } while (resto != 0);
    return (d1 * d2) / a;
}

//Simplificar um número
void simplificarNumero (int *n, int *d) {
    int mdc;
    mdc = MDC(*n, *d);
    *n = *n / mdc;
    *d = *d / mdc;
}

//Ler um número
void lerNumero (tRacional *numero) {
    printf("Numerador: ");
    scanf("%d", &numero->n);
    printf("Denominador: ");
    scanf("%d", &numero->d);
    printf("\n");
    simplificarNumero(&numero->n, &numero->d);
}

//Escrever um número
void escreverNumero (tRacional numero) {
    if (numero.d == 1)
        printf("Numero: %d\n", numero.n);
    else
        printf("Numero: %d/%d\n", numero.n, numero.d);
}

//Somar dois números racionais
void somarNumeros (tRacional a, tRacional b) {
    tRacional soma;
    int mmc = MMC(a.d, b.d);
    soma.n = (mmc/a.d)*a.n + (mmc/b.d)*b.n;
    soma.d = mmc;
    simplificarNumero(&soma.n, &soma.d);
    if (soma.d == 1)
        printf("Soma: %d\n", soma.n);
    else
        printf("Soma: %d/%d\n", soma.n, soma.d);
}

//Subtrair dois números racionais
void subtrairNumeros (tRacional a, tRacional b) {
    tRacional soma;
    int mmc = MMC(a.d, b.d);
    soma.n = (mmc/a.d)*a.n - (mmc/b.d)*b.n;
    soma.d = mmc;
    simplificarNumero(&soma.n, &soma.d);
    if (soma.d == 1)
        printf("Subtração: %d\n", soma.n);
    else
        printf("Subtração: %d/%d\n", soma.n, soma.d);
}

//Multiplicar dois números racionais
void multiplicarNumeros (tRacional a, tRacional b) {
    tRacional multiplicacao;
    multiplicacao.n = a.n * b.n;
    multiplicacao.d = a.d * b.d;
    simplificarNumero(&multiplicacao.n, &multiplicacao.d);
    if (multiplicacao.d == 1)
        printf("Multiplicação: %d\n", multiplicacao.n);
    else
        printf("Multiplicação: %d/%d\n", multiplicacao.n, multiplicacao.d);
}

//Dividir dois números racionais
void dividirNumeros (tRacional a, tRacional b) {
    tRacional divisao;
    divisao.n = a.n * b.d;
    divisao.d = a.d * b.n;
    simplificarNumero(&divisao.n, &divisao.d);
    if (divisao.d == 1)
        printf("Divisão: %d\n", divisao.n);
    else
        printf("Divisão: %d/%d\n", divisao.n, divisao.d);
}
