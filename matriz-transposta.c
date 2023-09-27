/******************************************************************************
Autor: Carolina da Silva Santos
Data: 10/07/2023
Objetivo: Achar a transposta de uma matriz
*******************************************************************************/
//Constantes
#include <stdio.h>
#define max_linhas 2
#define max_colunas 2

int main()
{
    //Declarações locais
    int matriz[max_linhas][max_colunas];
    int transposta[max_linhas][max_colunas];
    
    //Entrada de dados
    for (int i = 0; i < max_linhas; i++)
    {
        for (int j = 0; j < max_colunas; j++)
        {
            printf("Digite os valores da linha %d e coluna %d da matriz 1: ", i + 1, j + 1);
            scanf("%d", &matriz[i][j]);
        }
    }
    
    //Calcular a matriz transposta
    for (int j = 0; j < max_linhas; j++)
    {
        for (int i = 0; i < max_colunas; i++)
        {
            transposta[j][i] = matriz[i][j];
        }
    }
    
    //Mostrar o resultado
    printf("A matriz transposta é: \n");
     for (int i = 0; i < max_linhas; i++)
    {
        for (int j = 0; j < max_colunas; j++)
        {   
            printf("%d \t", transposta[i][j]);
        }
        printf("\n");
    }

    return 0;
}
