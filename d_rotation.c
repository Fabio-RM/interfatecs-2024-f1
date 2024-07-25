/*
Programa que recebe n coordenadas (x, y) e um ângulo theta em graus e retorna as coordenadas (x, y) rotacionadas em theta graus.

Entradas:
1. n: quantas coordenadas serão recebidas
2. ângulo de rotação
3. coordenadas x y

Processamento:
- As coordenadas rotacionadas são resultado da multiplicação matricial abaixo:

| x' | = | x | . | cos(t)   -sen(t) |
| y' |   | y |   | sen(t)    cos(t) |   

Saída:
- Coordenadas x, y depois de rotacionadas

=============
Exemplos:

Entrada 1:
5 40
20 50
10 50
35 75
-5 -7
-2 4

Saída:
-16.82  51.16
-24.48  44.73
-21.40  79.95
  0.67  -8.58
 -4.10   1.78

-------
Entrada 2:
3 100
20 250
35 4
66 50

Saída:
-249.68  -23.70
 -10.02   33.77
 -60.70   56.32

-------
Entrada 3:
2 30
100 5
55 35

Saída:
84.10  54.33
30.13  57.81

*/

#include <stdio.h>
#include <math.h>

#define MAX 100

int main(void) {
    int n, angle;
    int coordinates[MAX][2];
    float rot[2][2];
    float result[MAX][2] = {0};
    float theta;

    scanf("%d", &n);
    scanf("%d", &angle);

    for(int k=0; k < n; k++) {
        for(int xy=0; xy < 2; xy++) {
            scanf("%d", &coordinates[k][xy]);
        }
    }

    theta = (float)(angle * 3.1415) / 180;

    rot[0][0] = cos(theta);    rot[0][1] = -sin(theta);
    rot[1][0] = sin(theta);    rot[1][1] =  cos(theta);
    
    for(int k=0; k < n; k++) {
        for(int i=0; i < 2; i++) {
            for(int j=0; j < 2; j++) {   
                result[k][i] += (coordinates[k][j] * rot[i][j]);
            }
        }
    }

    for(int k=0; k < n; k++) {
        for(int i=0; i < 2; i++) {
            printf("%.2f\t", result[k][i]);
        }
        printf("\n");
    }
    
    return 0;
}
