/******************************************************************************
Autor: Carolina da Silva Santos
Data: 27/07/2023
Objetivo: TAD Círculo
*******************************************************************************/

// bibliotecas
#include <stdio.h>
#include <math.h>

// declarações globais
#define pi 3.14159

typedef struct {
  double x; // coordenada do eixo x
  double y; // coordenada do eixo y
} tPonto; // ponto no espaço Euclidiano bidimensional

typedef struct {
    tPonto centro;
    double raio;
} tCirculo;

// protótipos
void leiaCirculo(tCirculo *);
void escrevaCirculo(tCirculo);
double areaCirculo(tCirculo);
double perimetroCirculo(tCirculo);
double distanciaCentroCirculo(tCirculo, tCirculo);
double distanciaMinimaCirculos(int, tCirculo, tCirculo);

// função principal
int main()
{
  // declarações locais
  tCirculo circulo1;
  tCirculo circulo2;
  double area, perimetro, distanciaCentro, distanciaMinima;
  
  // leitura de dados
  printf("Circulo 1\n");
  leiaCirculo(&circulo1);
  escrevaCirculo(circulo1);
  
  printf("Circulo 2\n");
  leiaCirculo(&circulo2);
  escrevaCirculo(circulo2);
  
  // operações com círculo
  area = areaCirculo(circulo1);
  printf("Area do circulo 1 = %lf\n", area);
  
  area = areaCirculo(circulo2);
  printf("Area do circulo 2 = %lf\n", area);
  
  perimetro = perimetroCirculo(circulo1);
  printf("Perimetro do circulo 1 = %lf\n", perimetro);

  perimetro = perimetroCirculo(circulo2);
  printf("Perimetro do circulo 2 = %lf\n", perimetro);

  distanciaCentro = distanciaCentroCirculo(circulo1, circulo2);
  printf("Distancia entre os centros de circulo1 e circulo2 = %lf\n", distanciaCentro);
  
  distanciaMinima = distanciaMinimaCirculos(distanciaCentro, circulo1, circulo2);
  printf("Distancia mínima entre circulo1 e circulo2 = %lf\n", distanciaMinima);    
  
  // finalização do programa
  return 0;
}

/* 
  Nome: leiaCirculo
  Objetivo: ler os dados de um círculo, ou seja, ler as
            coordenadas de seu ponto central e o valor
            do seu raio.
  Parâmetro Formais
  - circulo: circulo que terá os seus dados lidos
             (parâmetro de saída de dados)
  Valor de retorno: nenhum.
*/

void leiaCirculo(tCirculo *circulo)
{
  printf("Digite as coordenadas do circulo:\n");
  printf("Digite o valor da coordenada x: ");
  // scanf("%lf", &(*circulo).centro.x);
  scanf("%lf", &circulo->centro.x);
  printf("Digite o valor da coordenada y: ");
  // scanf("%lf", &circulo->centro.y);
  scanf("%lf", &(*circulo).centro.y);
  printf("Digite o valor do raio do circulo: ");
  // scanf("%lf", &(*circulo).raio);
  scanf("%lf", &circulo->raio);

}

/* 
  Nome: escrevaCirculo
  Objetivo: escrever os dados de um círculo, ou seja, as
            coordenadas de seu ponto central e o valor
            do seu raio.
  Parâmetro Formais
  - c: circulo que terá os seus dados escritos
             (parâmetro de entrada de dados)
  Valor de retorno: nenhum.
*/
 
void escrevaCirculo(tCirculo c)
{
  printf("Dados do circulo:\n");
  printf("Coordenada x = %.2lf\n", c.centro.x);
  printf("Coordenada y = %.2lf\n", c.centro.y);
  printf("Raio = %.2lf\n", c.raio);
}

/* 
  Nome: areaCirculo
  Objetivo: Calcular a área de um círculo
  Parâmetro Formais
  - c: circulo que terá sua área calculada
  Valor de retorno: área do círculo
*/
double areaCirculo(tCirculo c) {
    double area;
    area = pi * c.raio * c.raio;
    return area;
}

/* 
  Nome: perimetroCirculo
  Objetivo: Calcular o perímetro de um círculo
  Parâmetro Formais
  - c: circulo que terá seu perímetro calculado
  Valor de retorno: perímetro do círculo
*/
double perimetroCirculo(tCirculo c) {
    double perimetro;
    perimetro = 2 * pi * c.raio;
    return perimetro;
}

/* 
  Nome: distanciaCentroCirculo
  Objetivo: Calcular a  distância entre os
            centros de dois círculos 
  - a: círculo 1
  - b: círculo 2
  Valor de retorno: distância entre os centros 
                    dos dois círculos
*/
double distanciaCentroCirculo(tCirculo a, tCirculo b) {
    double distanciaCentro;
    distanciaCentro = sqrt(pow(b.centro.x - a.centro.x, 2) + pow(b.centro.y - a.centro.x, 2));
    return distanciaCentro;
}

/* 
  Nome: distanciaMinimaCirculos
  Objetivo: Calcular a distância mínima entre
            dois círculos
  - distanciaEntreCentros: distância previamente calculada a partir da 
                            sub-rotina distanciaCentroCirculo
  - a: círculo 1
  - b: circulo 2
  Valor de retorno: distância mínima entre os dois círculos
*/
double distanciaMinimaCirculos(int distanciaEntreCentros, tCirculo a, tCirculo b) {
    double distanciaMinima = distanciaEntreCentros - a.raio - b.raio;
    return fabs(distanciaMinima);
}
