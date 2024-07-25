/*
Recebe n mapas de calor numa matriz 6x3 contendo apenas os digitos 0 e 1 e retorna a região das matrizes com maior recorrência do número 1. Sendo as regiões definidas por:

Região (Col inic, Linha inic, Col. final, Linha final)

Superior (0, 0, 2, 0)
Esquerda (0, 1, 0, 4)
Centro 	 (1, 1, 1, 4)
Direita  (2, 1, 2, 4)
Inferior (0, 5, 2, 5)
-------------------------------

Entradas:
1. Número de matrizes a serem inseridas n (3<=100)
2. n matrizes 6x3 contendo apenas 0s e 1s

Saída:
Nome da região que contêm maior incidêndia do dígito 1
- Se empate, exibe na ordem de região acima

-------------------------------

Exemplo:

Entrada:
3
0 1 0
0 0 0
1 0 0
1 0 0
0 0 0
1 1 1
0 0 1
1 0 0
1 0 0
0 0 0
0 0 0
0 1 0
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0
1 1 1

Saída: 
inferior
*/

#include <stdio.h>

#define ROWS 6
#define COLS 3
#define MAX 100

int main(void) {
    int num_users;
    int inputs[MAX][ROWS][COLS];
    int map[5] = {0};
    int most_viewed, most_viewed_index;
    char regions[5][10] = {"superior", "esquerda", "centro","direita", "inferior"};
    
    scanf("%d", &num_users);

    for(int n=0; n < num_users; n++) {
        for(int i=0; i < ROWS; i++) {
            for(int j=0; j < COLS; j++) {
                scanf("%d", &inputs[n][i][j]);

                if (inputs[n][i][j] == 1) {
                    if (i == 0)
                        // Superior
                        map[0]++;
                    else if (j == 0 && (i >= 1 && i <= 4))
                        // Esquerda
                        map[1]++;
                    else if (j == 1 && (i >= 1 && i <= 4))  
                        // Centro
                        map[2]++;
                    else if (j == 2 && (i >= 1 && i <= 4))
                        // Direita
                        map[3]++;
                    else if (i == 5)
                        // Inferior
                        map[4]++;
                }
            }
        }
    }

    // Get most viewed region
    most_viewed = map[0];
    for(int i=1; i < 5; i++) {
        if (map[i] > most_viewed) {
            most_viewed = map[i];
            most_viewed_index = i;
        }
    }

    printf("%s", regions[most_viewed_index]);
    
    return 0;
}
