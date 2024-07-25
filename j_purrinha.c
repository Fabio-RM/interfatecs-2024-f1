/*
No jogo de purrinha, cada jogador segura na sua mão uma quantidade de palitos. 
Então a cada rodada, cada jogador dá um palpite do total de palitos que todos 
os jogadores estão na mão. Ganha a rodada quem acertar o número total de palitos 
na mesa. Se ninguém acertar, ninguém pontua. Se mais de um jogador acertar, há 
empate entre os jogadores que acertaram o palpite. Ganha o jogo quem vencer o 
maior número de rodadas, caso os jogadores tenham o mesmo número de vitórias/empates,
o jogo termina empatado.

O programa recebe os dados dos jogadores, quantas rodadas serão, a quantidade de 
palitos que cada jogador possui na mão e o palpite de cada um dos jogadores. Ao 
final, calcula quem venceu o jogo ou se o mesmo terminou empatado.

Entradas:
1. Número de jogadores (2 <= n <= 6)
2. Nomes de cada um dos jogadores
3. Número de rodadas (5 <= n <= 50)
4. Pares de linhas n vezes representando:
    - Linha 1: mão de cada jogador
    - Linha 2: palpite de cada jogador

Saída: Nome do jogador vencedor ou EMPATE

Exemplo 1:
2       Número de jogadores
LILO    Nome do jogador 1
STITCH	Nome do jogador 2
3	    Número de Rodadas
2 0	    Mão de cada jogador na rodada 1
3 2	    Palpite de cada jogador - STITCH Ganhou
1 0     Mão de cada jogador na rodada 2
4 1     Palpite de cada jogador - STITCH Ganhou
2 1     Mão de cada jogador na rodada 3
3 1     Palpite de cada jogador - LILO Ganhou

Saída:
STITCH GANHOU

-------------------

Exemplo 2:
2
LILO
STITCH
3
2 3
5 6
2 2
2 3
1 3
2 4

Saída:
EMPATE

-------------------

Exemplo 3:

3
HOUSE
MONK
SHELDON
6
1 2 0
6 3 5
0 3 1
2 4 5
0 0 3
6 1 8
1 3 3
5 7 9
2 0 0
2 1 6
2 3 2
5 3 7

Saída:
MONK GANHOU

*/

#include <stdio.h>
#include <string.h>

#define MAX_NAME 255
#define MAX_PLAYER 6
#define MAX_ROUNDS 50

int main(void) {
    char names[MAX_PLAYER][MAX_NAME];
    int hands[MAX_PLAYER];
    int guesses[MAX_PLAYER];
    int points[MAX_PLAYER] = {0};
    int num_players, num_rounds, round;
    int winner = -1;
    int sum = 0, highest_points = 0;

    scanf("%d", &num_players);
    getchar();

    for(int i=0; i < num_players; i++) {
        fgets(names[i], MAX_NAME, stdin);
        names[i][strlen(names[i])-1] = '\0';
    }

    scanf("%d", &num_rounds);

    round = 1;
    while (round <= num_rounds) {
        sum = 0;
        for(int i=0; i < num_players; i++) {
            scanf("%d", &hands[i]);
            sum += hands[i];
        }

        for(int i=0; i < num_players; i++) {
            scanf("%d", &guesses[i]);

            if (guesses[i] == sum) {
                points[i]++;
            }
        }
        
        round++;
    }

    highest_points = points[0];
    for(int i=1; i < num_players; i++) {
        if (points[i] > highest_points) {
            highest_points = points[i];
            winner = i;
        }
        else if (points[i] == highest_points)
            winner = -1;
    }

    if (winner != -1)
        printf("%s GANHOU", names[winner]);
    else
        printf("EMPATE");
    
    return 0;
}
