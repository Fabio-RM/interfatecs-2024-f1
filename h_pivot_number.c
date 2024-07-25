/*
Dados 3 valores inteiros, retornar aquele que não é o maior e nem o menor entre os 3 e que não está sozinho.

Entrada:
3 valores inteiros de -2.000.000.000 a 2.000.000.000

Saída:
Valor selecionado

Exemplos:

Entradas        Saída
23 42 37         37
15 30 15         15
10 20 30         20
*/


#include <stdio.h>

int main(void) {
    int nums[3];
    int maior, menor, pivo;

    // Data input
    for(int i=0; i < 3; i++) {
        scanf("%d", &nums[i]);
    }

    maior = nums[0];
    menor = nums[0];

    // Find the largest and smallest number 
    for(int i=1; i < 3; i++) {
        if (nums[i] > maior)    maior = nums[i];
        if (nums[i] < menor)    menor = nums[i];
    }

    // Find the pivot if numbers are different
    for(int i=0; i < 3; i++) {
        if (nums[i] != maior && nums[i] != menor)
            pivo = nums[i];
    }

    // Find the pivot if numbers some numbers are the same
    for(int i=0; i < 3; i++) {
        for(int j=i+1; j < 3; j++) {
            if (nums[i] == nums[j]) {
                pivo = nums[i];
            }
        }
    }

    printf("%d", pivo);
    
    return 0;
}
