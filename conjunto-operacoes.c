/******************************************************************************
Autor: Carolina da Silva Santos
Data: 09/08/2023
Objetivo: Testar operações com conjuntos
*******************************************************************************/
//Bibliotecas
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

//Declarações globais
#define tam 50

typedef struct {
    int elem[tam];
    int qntdElem;
} tConjunto;

//Protótipos
void inicializarConjunto (tConjunto *);
void verificaVazio (tConjunto);
void inserirConjunto (tConjunto *);
void mostrarConjunto (tConjunto);
void buscarElemento (tConjunto);
void uniaoConjunto (tConjunto, tConjunto);
void interseccaoConjunto (tConjunto, tConjunto);
void removeNumero (tConjunto *);
void ordenaConjuntoCrescente(tConjunto *);
void ordenaConjuntoDecrescente(tConjunto *);
void removeRepetido (tConjunto *);
void mostrarConjuntoOrdenado (tConjunto);
void retornarQuantidade(tConjunto);
void inserirElementos (tConjunto *);
bool verificaConjuntosIguais(tConjunto, tConjunto);
void verificaIgualdade(bool);
void diferencaConjuntos (tConjunto, tConjunto);
void conjuntoContido (tConjunto, tConjunto);
void conjuntoContem (tConjunto, tConjunto);

int main()
{
    printf("As operações serão realizadas com 2 conjuntos!\n");
    //Declarações locais
    tConjunto A;
    tConjunto B;
    
    //Inicializar conjuntos
    inicializarConjunto(&A);
    inicializarConjunto(&B);
    
    //Entrada de dados
    printf("\nDigite os dados do conjunto A:\n");
    inserirConjunto(&A);
    printf("\nDigite os dados do conjunto B:\n");
    inserirConjunto(&B);
    
    //Verifica se é um conjunto vazio
    printf("\nConjunto A:\n");
    verificaVazio (A);
    printf("\nConjunto B:\n");
    verificaVazio (B);
    
    //Mostra os conjuntos inseridos
    printf("\nO conjunto A é:\n");
    mostrarConjunto(A);
    printf("O conjunto B é:\n");
    mostrarConjunto(B);
    
    char resp;
    int opcao;
    printf("Você deseja fazer operações com os conjuntos? (Digite 'S' caso queira)\n");
    scanf(" %c", &resp);
    resp = toupper(resp);
    while (resp == 'S') {
        printf("Qual opcao você deseja realizar com os conjuntos?\n");
        printf("Opção 1: Verificar se os conjuntos são iguais\n");
        printf("Opção 2: Verificar a quantidade de elementos do conjunto\n");
        printf("Opção 3: Inserir elementos nos conjuntos\n");
        printf("Opção 4: Remover elementos dos conjuntos\n");
        printf("Opção 5: Ordenar elementos dos conjuntos\n");
        printf("Opção 6: Verificar se um elemento está presente no conjunto\n");
        printf("Opção 7: União dos dois conjuntos\n");
        printf("Opção 8: Interseccção dos dois conjuntos\n");
        printf("Opção 9: Verificar se os conjuntos são iguais\n");
        printf("Opção 10: Verificar se um conjunto está contido no outro\n");
        printf("Opção 11: Verificar se um conjunto contém o outro\n");
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1:
                //Verifica se os conjuntos são iguais
                printf("\nVerificando se os conjuntos são iguais:\n");
                verificaIgualdade(verificaConjuntosIguais(A, B));
                break;
            case 2:
                //Retornar a quantidade de elementos de um conjunto
                printf("\nConjunto A:\n");
                retornarQuantidade(A);
                printf("\nConjunto B:\n");
                retornarQuantidade(B);
                break;
            case 3:
                //Inserir elementos nos conjuntos
                printf("\nInsira elementos no conjunto A:\n");
                inserirElementos (&A);
                printf("O novo conjunto A é:\n");
                mostrarConjunto(A);
                printf("\nInsira elementos no conjunto B:\n");
                inserirElementos (&B);
                printf("O novo conjunto B é:\n");
                mostrarConjunto(B);
                break;
            case 4:
                //Remove elemento
                printf("\nManipulando o conjunto A: ");
                mostrarConjunto(A);
                removeNumero(&A);
                printf("\nManipulando o conjunto B: ");
                mostrarConjunto(B);
                removeNumero(&B);
                break;
            case 5:
                //Ordena os conjuntos inseridos
                printf("\nVamos ordenar os conjuntos!\n");
                printf("Você quer o conjunto A ordenado na ordem crescente (1) ou decrescente (2)?\n");
                mostrarConjuntoOrdenado (A);
                printf("Você quer o conjunto B ordenado na ordem crescente (1) ou decrescente (2)?\n");
                mostrarConjuntoOrdenado (B);
                break;
            case 6:
                //Procura um elemento
                printf("\nVamos verificar se um elemento está presente no conjunto A:\n");
                buscarElemento(A);
                printf("\nVamos verificar se um elemento está presente no conjunto B:\n");
                buscarElemento(B);
                break;
            case 7:
                //União de dois conjuntos
                uniaoConjunto(A, B);
                break;
            case 8:
                //Intersecção de dois conjuntos
                interseccaoConjunto(A, B);
                break;
            case 9:
                //Diferença de dois conjuntos
                printf("\n\nCalculando a diferença A - B:\n");
                diferencaConjuntos (A, B);
                printf("\nCalculando a diferença B - A:\n");
                diferencaConjuntos (B, A);
                break;
            case 10:
                //Verificando se um conjunto está contido no outro
                printf("\nVerificando se B está contido em A:\n");
                conjuntoContido(A, B);
                printf("\nVerificando se A está contido em B:\n");
                conjuntoContido(B, A);
                break;
            case 11:
                //Verificando se um conjunto contém outro
                printf("\nVerificando se A contém B:\n");
                conjuntoContem(A, B);
                printf("\nVerificando se B contém A:\n");
                conjuntoContem(B, A);
                break;
            default: "Selecione uma opção válida!";
        }
        printf("\nVocê deseja fazer outras operações com os conjuntos? (Digite 'S' caso queira e 'N' caso não)\n");
        scanf(" %c", &resp);
        resp = toupper(resp);
    }
    
    return 0;
}

/* 
  Nome: retornarQuantidade
  Objetivo: Retornar a quantidade de elementos
  Parâmetro Formais
  - tConjunto A: conjunto que terá sua quantidade de elementos retornada (parametro de entrada)
  Valor de retorno: Quantidade de elementos do conjunto
*/
void retornarQuantidade(tConjunto A) {
    printf("A quantidade de elementos do conjunto é %d\n", A.qntdElem);
}

/* 
  Nome: inicializarConjunto
  Objetivo: Inicializar um conjunto, ou seja, sua quantidade de elementos inicial é 0
  Parâmetro Formais
  - tConjunto A: conjunto que será inicializado (parametro de saída)
  Valor de retorno: Nulo
*/
void inicializarConjunto (tConjunto *A) {
    A->qntdElem = 0;
}

/* 
  Nome: verificaVazio
  Objetivo: Verificar se um conjunto é vazio
  Parâmetro Formais
  - tConjunto A: Conjunto que será analisado (parametro de entrada)
  Valor de retorno: Retorna se o conjunto é vazio ou não
*/
void verificaVazio (tConjunto A) {
    if (A.qntdElem == 0) {
        printf("É um conjunto vazio!\n");
    }
    else {
        printf("Não é um conjunto vazio!\n");
    }
}

/* 
  Nome: ordenaConjuntoCrescente
  Objetivo: Ordenar um conjunto na ordem crescente
  Parâmetro Formais
  - tConjunto *A: ponteiro do conjunto que será analisado (parametro de saída)
  Valor de retorno: Conjunto ordenado na ordem crescente
*/
void ordenaConjuntoCrescente(tConjunto *A) { 
    int menor = 10000, temp, menor_i;
    for(int j = 0; j < A->qntdElem; j++) {
        for (int i = 0 + j; i < A->qntdElem; i++) {
            if (A->elem[i] < menor) {
                menor_i = i;
                menor = A->elem[i];
            }
        }
        temp = A->elem[j];
        A->elem[j] = A->elem[menor_i];
        A->elem[menor_i] = temp;
        menor = 10000;
    }
}

/* 
  Nome: ordenaConjuntoDecrescente
  Objetivo: Ordenar um conjunto na ordem decrescente
  Parâmetro Formais
  - *tConjunto A: ponteiro do conjunto que será analisado (parametro de saída)
  Valor de retorno: Conjunto ordenado na ordem decrescente
*/
void ordenaConjuntoDecrescente(tConjunto *A) { 
    int maior = -10000, temp, maior_i;
    for(int j = 0; j < A->qntdElem; j++) {
        for (int i = 0 + j; i < A->qntdElem; i++) {
            if (A->elem[i] > maior) {
                maior_i = i;
                maior = A->elem[i];
            }
        }
        temp = A->elem[j];
        A->elem[j] = A->elem[maior_i];
        A->elem[maior_i] = temp;
        maior = -10000;
    }
}

/* 
  Nome: inserirConjunto
  Objetivo: Inserir os elementos de um conjunto
  Parâmetro Formais
  - tConjunto *A: ponteiro do conjunto que terá elementos inseridos (parametro de entrada e saída)
  Valor de retorno: Conjunto com os elementos inseridos
*/
void inserirConjunto (tConjunto *A) {
    printf("Digite a quantidade de elementos do conjunto: ");
    scanf("%d", &A->qntdElem);
    if (A->qntdElem == 0) {
        printf("É um conjunto é vazio!\n");
    }
    else {
        printf("Digite os valores: \n");
        for (int i = 0; i < A->qntdElem; i++) {
            scanf("%d", &A->elem[i]);
            if (i != 0) {
                for (int j = 0; j < i; j++) {
                    while (A->elem[j] == A->elem[i]) {
                    printf("O valor já está contido no conjunto, digite novamente: ");
                    scanf("%d", &A->elem[i]);
                    }
                }
            }
        }   
    }
}

/* 
  Nome: inserirElementos
  Objetivo: Inserir elementos a mais em um conjunto
  Parâmetro Formais
  - tConjunto *A: ponteiro do conjunto que terá elementos inseridos (parametro de entrada e saída)
  Valor de retorno: Conjunto com elementos inseridos
*/
void inserirElementos (tConjunto *A) {
    int qntd;
    printf("Digite a quantidade de elementos que você deseja inserir: ");
    scanf("%d", &qntd);
    printf("Digite os valores a serem inseridos: \n");
        for (int i = A->qntdElem; i < A->qntdElem + qntd; i++) {
            scanf("%d", &A->elem[i]);
                for (int j = 0; j < i; j++) {
                    while (A->elem[j] == A->elem[i]) {
                    printf("O valor já está contido no conjunto, digite novamente: ");
                    scanf("%d", &A->elem[i]);
                    }
                }
        }
        A->qntdElem = A->qntdElem + qntd;
        ordenaConjuntoCrescente(A);
}

/* 
  Nome: mostrarConjuntoOrdenado
  Objetivo: Mostrar os elementos dos conjuntos ordenados
  Parâmetro Formais
  - tConjunto A: Conjunto que será ordenado (parametro de entrada e saída) dependendo
                    da opcao selecionada pelo usuário
  Valor de retorno: Mostra o conjunto ordenado
*/
void mostrarConjuntoOrdenado (tConjunto A) {
    int opcao;
    scanf("%d", &opcao);
    printf("O conjunto ordenado é:\n");
    if (opcao == 1) {
        ordenaConjuntoCrescente(&A);
    }
    else if (opcao == 2) {
        ordenaConjuntoDecrescente(&A);
    }
    mostrarConjunto(A);
    ordenaConjuntoCrescente(&A);
}

/* 
  Nome: mostrarConjunto
  Objetivo: Mostrar os elementos de um conjunto
  Parâmetro Formais
  - tConjunto A: Conjunto que será mostrado (parametro de entrada)
  Valor de retorno: Mostra o conjunto
*/
void mostrarConjunto (tConjunto A) {
    if (A.qntdElem == 0)
        printf("É um conjunto vazio!\n");
    else {
        for (int i = 0; i < A.qntdElem; i++) {
            printf("%d ", A.elem[i]);
        }
        printf("\n"); 
    }
}

/* 
  Nome: buscarElemento
  Objetivo: Procurar e verificar se um elemento está presente em um conjunto
  Parâmetro Formais
  - tConjunto A: Conjunto que será utilizado para procurar o elemento desejado
                    (parametro de entrada)
  Valor de retorno: Retorna se o elemento está presente ou não
*/
void buscarElemento (tConjunto A) {
    int elemProcurado;
    bool achou = false;
    printf("Qual elemento você deseja procurar?\n");
    scanf("%d", &elemProcurado);
    for (int i = 0; i < A.qntdElem; i++) {
        if (A.elem[i] == elemProcurado)
            achou = true;
    }
    if (achou)
        printf("O elemento está presente no conjunto.\n");
    else
        printf("O elemento não está presente no conjunto.\n");
}

/* 
  Nome: uniaoConjunto
  Objetivo: Realiza a uniáo de dois conjuntos
  Parâmetro Formais
  - tConjunto A: Conjunto que será unido com outro (parametro de entrada)
  - tConjunto B: Conjunto que será unido com outro (parametro de entrada)
  Valor de retorno: União dos dois conjuntos
*/
void uniaoConjunto (tConjunto A, tConjunto B) {
    tConjunto uniao;
    inicializarConjunto(&uniao);
    uniao.qntdElem = A.qntdElem + B.qntdElem;
    int i_b = 0;
    for (int i = 0; i < uniao.qntdElem; i++) {
        if (A.qntdElem != 0 || B.qntdElem != 0) {
            if (i < A.qntdElem) {
                uniao.elem[i] = A.elem[i];
            }
            else {
                uniao.elem[i] = B.elem[i_b];
                i_b++;
            }
        }
        else {
            uniao.elem[i] = A.elem[i];
        }
    }
    removeRepetido(&uniao);
    printf("\nA união dos dois conjuntos eh:\n");
    for (int i = 0; i < uniao.qntdElem; i++) {
        printf("%d ", uniao.elem[i]);
    }
}

/* 
  Nome: interseccaoConjunto
  Objetivo: Realiza a interseccao de dois conjuntos
  Parâmetro Formais
  - tConjunto A: Conjunto que será interssecionado com outro (parametro de entrada)
  - tConjunto B: Conjunto que será interssecionado com outro (parametro de entrada)
  Valor de retorno: Interseccao dos dois conjuntos
*/
void interseccaoConjunto (tConjunto A, tConjunto B) {
    int menorTamanho, tamanho = 0;
    int interseccao[tam];
    if (A.qntdElem < B.qntdElem) {
        for (int i = 0; i < A.qntdElem; i++) {
            for (int j = 0; j < B.qntdElem; j++) {
                if (A.elem[i] == B.elem[j]) {
                    interseccao[tamanho] = A.elem[i];
                    tamanho++;
                }
            } 
        }
    }
    else {
        for (int i = 0; i < B.qntdElem; i++) {
            for (int j = 0; j < A.qntdElem; j++) {
                if (B.elem[i] == A.elem[j]) {
                    interseccao[i] = B.elem[i];
                    tamanho++;
                }
            } 
        }
    }
    printf("\n\nA intersecçao dos dois conjuntos eh: \n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", interseccao[i]);
    }  
}

/* 
  Nome: removeNumero
  Objetivo: Remover um elemento de um conjunto
  Parâmetro Formais
  - tConjunto *A: Ponteiro do conjunto que terá seu elemento removido (parametro de entrada e saída)
  Valor de retorno: Conjunto com o elemento removido
*/
void removeNumero (tConjunto *A) {
    int numero, temp;
    printf("Qual número você deseja remover?\n");
    scanf("%d", &numero);
    for (int i = 0; i < A->qntdElem; i++) {
        if (numero == A->elem[i]) {
            temp = A->elem[A->qntdElem-1];
            A->elem[A->qntdElem-1] = A->elem[i];
            A->elem[i] = temp;
            A->qntdElem--;
        }
    }
    ordenaConjuntoCrescente(A);
    printf("O conjunto com o número %d removido eh:\n", numero);
    mostrarConjunto(*A);
}

/* 
  Nome: removeRepetido
  Objetivo: Remover os elementos repetidos de um conjunto
  Parâmetro Formais
  - tConjunto *A: Ponteiro do conjunto que terá seus elementos repetidos removidos (parametro de entrada
                        e saída)
  Valor de retorno: Conjunto com elementos repetidos removidos
*/
void removeRepetido (tConjunto *A) {
    int temp;
    for (int i = 0; i < A->qntdElem; i++) {
        for (int j = 1 + i; j < A->qntdElem; j++) {
           if (A->elem[i] == A->elem[j]) {
            temp = A->elem[A->qntdElem-1];
            A->elem[A->qntdElem-1] = A->elem[i];
            A->elem[i] = temp;
            A->qntdElem--;
            i--;
            } 
        }
    }
    ordenaConjuntoCrescente(A);
}

/* 
  Nome: verificaConjuntosIguais
  Objetivo: Verificar se dois conjuntos são iguais
  Parâmetro Formais
  - tConjunto A: Primeiro conjunto a ser comparado (parametro de entrada)
  - tConjunto B: Segundo conjunto a ser comparado (parametro de entrada)
  Valor de retorno: Retorna se eles são iguais ou não
*/
bool verificaConjuntosIguais(tConjunto A, tConjunto B) {
    bool iguais = true;
    if (A.qntdElem == B.qntdElem) {
        for (int i = 0; i < A.qntdElem; i++) {
            if (A.elem[i] != B.elem[i]) {
                iguais = false;
                break;
            }
        }
    }
    else {
        iguais = false;
    }
    return iguais;
}

/* 
  Nome: verificaIgualdade
  Objetivo: Mostra a verificacão de igualdade
  Parâmetro Formais
  - a: Variável booleana que sinaliza true se forem iguais e false se não
        forem iguais
  Valor de retorno: Mostra se são iguais ou não
*/
void verificaIgualdade(bool a) {
    if (a)
        printf("Os conjuntos A e B são iguais!\n");
    else
        printf("Os conjuntos A e B não são iguais!\n");
}

/* 
  Nome: diferencaConjuntos
  Objetivo: Realiza a subtracao de dois conjuntos (diferenca)
  Parâmetro Formais
  - tConjunto A: Conjunto que será subtraído (parametro de entrada)
  - tConjunto B: Conjunto que vai subtrair o outro (parametro de entrada)
  Valor de retorno: A diferenca dos conjuntos
*/
void diferencaConjuntos (tConjunto A, tConjunto B) {
    tConjunto diferenca;
    bool diferentes = true;
    inicializarConjunto(&diferenca);
    diferenca.qntdElem = 0;
    for (int i = 0; i < A.qntdElem; i++) {
        for (int j = 0; j < B.qntdElem; j++) {
            if (A.elem[i] == B.elem[j]) {
                diferentes = false;
            }
        }
        if (diferentes) {
            diferenca.elem[diferenca.qntdElem] = A.elem[i];
            diferenca.qntdElem++;
        }
        diferentes = true;
    }
    mostrarConjunto(diferenca);
}

/* 
  Nome: conjuntoContido
  Objetivo: Verifica se um conjunto está contido no outro
  Parâmetro Formais
  - tConjunto A: Conjunto que vai verificar se contém (parametro de entrada)
  - tConjunto B: Conjunto que vai ser verificado se está contido (parametro de entrada)
  Valor de retorno: Retorna se B está contido em A
*/
void conjuntoContido (tConjunto A, tConjunto B) {
    int tem = 0;
    for (int i = 0; i < A.qntdElem; i++) {
        for (int j = 0; j < B.qntdElem; j++) {
            if (A.elem[i] == B.elem[j]) {
                tem++;
            }
            
        }
    }
    if (tem == B.qntdElem) {
        printf("O conjunto está contido\n");
    }
    else {
        printf("O conjunto não está contido\n");
    }
}

/* 
  Nome: conjuntoContem
  Objetivo: Verifica se um conjunto contém o outro
  Parâmetro Formais
  - tConjunto A: Conjunto que vai verificar se contém (parametro de entrada)
  - tConjunto B: Conjunto que vai ser verificado se está contido (parametro de entrada)
  Valor de retorno: Retorna se A contém B
*/
void conjuntoContem (tConjunto A, tConjunto B) {
    int tem = 0;
    for (int i = 0; i < A.qntdElem; i++) {
        for (int j = 0; j < B.qntdElem; j++) {
            if (A.elem[i] == B.elem[j]) {
                tem++;
            }
            
        }
    }
    if (tem == B.qntdElem) {
        printf("O conjunto contém\n");
    }
    else {
        printf("O conjunto não contém\n");
    }
}
