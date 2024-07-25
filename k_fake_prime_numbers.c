/*
Dado um número natural, verificar se ele possui exatamente 3 divisores, o 1, o próprio número e mais um divisor.

Exemplos:
Entradas    Saídas
7            não
4            sim
9            sim
994009       sim
999983       não
*/

#include <stdio.h>
#include <math.h>

int main(void) {
    int num;
    int dividers = 0;
    int prime = 1;

    scanf("%d", &num);

    for(int i=2; i <= num/2; i++) {
        if (num % i == 0) {
            dividers++;
        }

        if (dividers > 1) {
            prime = 0;
            break;
        }
    }

    if (dividers == 0)
        prime = 0;

    if (prime)
        printf("sim");
    else
        printf("nao");
    return 0;
}
