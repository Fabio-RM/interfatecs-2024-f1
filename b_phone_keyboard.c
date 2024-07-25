/*
O teclado de um celular tinha letras associadas a cada um dos números, saber:

2 - ABC
3 - DEF
4 - GHI
5 - JKL
6 - MNO
7 - PQRS
8 - TUV
9 - WXYZ

O programa recebe n (1 <= n <= 100) palavras e mostra o número associado à essas palavras
------

Entradas:
1. Um número n indicando quantas palavras serão digitadas
2. n palavras em letras maiúsculas

Saídas:
- O número associado a cada palavra

-------
Exemplo 1:

Entrada:
3
PORTOSEGURO
TRICOLOR
CENTROPAULASOUZA

Saídas:
76786734876
87426567
2368767285276892

---
Exemplo 2:

Entradas:
1
FATEC

Saída:
32832

---
Exemplo 3:

Entradas:
2
SOS
AMBULANCIA

Saídas:
767
2628526242
*/

#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX 100
#define MAX_CHARS 255

int main(void) {
    int n, exp;
    char words[MAX][MAX_CHARS];
    unsigned long int result = 0;

    // Data input
    scanf("%d", &n);
    getchar();
    
    for(int i=0; i < n; i++) {
        fgets(words[i], MAX_CHARS, stdin);
        words[i][strlen(words[i])-1] = '\0';
    }

    // Associate letters to numbers
    for(int word=0; word < n; word++) {
        exp = strlen(words[word])-1;
        result = 0;
        
        for(int letter=0; letter < strlen(words[word]); letter++) {
            switch(words[word][letter]) {
                case 'A': 
                case 'B': 
                case 'C':
                    result += 2*pow(10, exp);
                    break;
                case 'D': 
                case 'E': 
                case 'F':
                    result += 3*pow(10, exp);
                    break;
                case 'G': 
                case 'H': 
                case 'I':
                    result += 4*pow(10, exp);
                    break;
                case 'J': 
                case 'K': 
                case 'L':
                    result += 5*pow(10, exp);
                    break;
                case 'M': 
                case 'N': 
                case 'O':
                    result += 6*pow(10, exp);
                    break;
                case 'P': 
                case 'Q': 
                case 'R':
                case 'S':
                    result += 7*pow(10, exp);
                    break;
                case 'T': 
                case 'U': 
                case 'V':
                    result += 8*pow(10, exp);
                    break;
                case 'X': 
                case 'Y': 
                case 'Z':
                case 'W':
                    result += 9*pow(10, exp);
                    break;
            }

            exp--;
        }

        printf("%ld\n", result);
    }
    
    return 0;
}
