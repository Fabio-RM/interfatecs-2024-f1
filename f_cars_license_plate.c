/*
Recebe uma string com números de placas e informa qual tipo é de acordo com a lista abaixo:

1) Placa muito antiga: A999 ou P99999
    Inicia com a letra A ou P
    Seguida de uma sequência de 1 a 5 dígitos
2) Placa numérica: 999 ou 99999 ou 9999999
    Sequência de até 7 dígitos numérico
3) Padrão AA-9999
    Inicia com 2 letras obrigatoriamente
    Seguida de 4 dígitos numéricos
4) Padrão AAA-9999
    Inicia com 3 letras obrigatoriamente
    Seguida de 4 dígitos numéricos
5) Padrão mercosul: AAA9A99
    Inicia com 3 letras
    Seguida de 1 dígito numérico
    Seguido de uma letra
    Seguida de 2 dígitos numéricos

Entrada: uma string de até 50 caracteres alfanuméricos com o valor da placa

Exemplos:
Entrada:            Saída
A1234               Placa muito antiga
12345               Placa numerica
AB1234              Placa AA-9999
ABC1234             Placa AAA-9999
ABC1D34             Placa mercosul
X0S0X0X0009         Placa invalida
*/

#include <stdio.h>
#include <regex.h>

#define MAX 50

int main(void) {
    char placa[MAX];
    int muito_antiga = 1;
    int numerica = 1;
    int aa9999 = 1;
    int aaa9999 = 1;
    int mercosul = 1;
    regex_t re;

    printf("Digite a placa: ");
    fgets(placa, MAX, stdin);

    muito_antiga = regcomp(&re, "^(A|P)[0-9]{1,5}$", REG_EXTENDED | REG_NEWLINE);
    muito_antiga = regexec(&re, placa, 0, NULL, 0);

    numerica = regcomp(&re, "^[0-9]{1,7}$", REG_EXTENDED | REG_NEWLINE);
    numerica = regexec(&re, placa, 0, NULL, 0);

    aa9999 = regcomp(&re, "^[A-Z]{2}[0-9]{4}$", REG_EXTENDED | REG_NEWLINE);
    aa9999 = regexec(&re, placa, 0, NULL, 0);

    aaa9999 = regcomp(&re, "^[A-Z]{3}[0-9]{4}$", REG_EXTENDED | REG_NEWLINE);
    aaa9999 = regexec(&re, placa, 0, NULL, 0);

    mercosul = regcomp(&re, "^[A-Z]{3}[0-9]{1}[A-Z]{1}[0-9]{2}$", REG_EXTENDED | REG_NEWLINE);
    mercosul = regexec(&re, placa, 0, NULL, 0);
   
    if(muito_antiga == 0)
        printf("Placa muito antiga");
    else if (numerica == 0)
        printf("Placa numerica");
    else if (aa9999 == 0)
        printf("Placa AA-9999");
    else if (aaa9999 == 0)
        printf("Placa AAA-9999");
    else if (mercosul == 0)
        printf("Placa mercosul");
    else
        printf("Placa invalida");
    
    return 0;
}
