#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateQuestion(int level, int *a, int *b, char *op, int *correctAnswer) {
    switch(level) {

case 1: // Level Mudah (penjumlahan & pengurangan)
            *a = rand() % 10 + 1;
            *b = rand() % 10 + 1;
            *op = (rand() % 2 == 0) ? '+' : '-';
            *correctAnswer = (*op == '+') ? (*a + *b) : (*a - *b);
            break;
case 2: // Level Sedang (perkalian & pembagian)
            *a = rand() % 20 + 1;
            *b = rand() % 20 + 1;
            *op = (rand() % 2 == 0) ? '*' : '/';
            if (*op == '*') {
                *correctAnswer = (*a * *b);
            } else {
                // Pastikan pembagian habis
                *correctAnswer = rand() % 10 + 1;
                *b = rand() % 10 + 1;
                *a = *correctAnswer * *b;
            }
            break;
case 3: // Level Sulit (campuran operasi dengan bilangan besar)
            *a = rand() % 50 + 1;
            *b = rand() % 50 + 1;
            int opType = rand() % 4;
            switch(opType) {
                case 0: *op = '+'; *correctAnswer = *a + *b; break;
                case 1: *op = '-'; *correctAnswer = *a - *b; break;
                case 2: *op = '*'; *correctAnswer = *a * *b; break;
                case 3: *op = '/'; 
                        *correctAnswer = rand() % 10 + 1;
                        *b = rand() % 10 + 1;
                        *a = *correctAnswer * *b;
                        *op = '/';
                        break;
            }
            break;
    }
}



int main (){




return 0;
}
