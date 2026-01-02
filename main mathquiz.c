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

//fungsi biar bisa nerima jawaban dari pengguna
int getUserAnswer (int a, int b, char op){
  int answer;
  printf("Berapakah %d %c %d", a, op, b);
  scanf("%d, &answer");
  return answer;
}
  
//fungsi buat meriksa jawaban
int checkAnswer (int userAnswer, int correctAnswer){
  return userAnswer == correctAnswer;
}

//fungsi untuk nampilin skor akhir per level 
void showScore(int score, int total, int level){
  printf("\n=== HASIL LEVEL ===\n", level);
  printf("Skor Akhir Kamu: %d dari %d\n", score, total);
  if (score == total){
    printf ("Sempurna!\n");
  } else if (score >= total/2){
    printf("Lumayan, kamu lulus.\n");
  } else {
    printf ("Belajar lagi...\n");
  }
}

int main (){
srand (time(NULL));
    int totalQuestions = 5;
    int level, retry;
    int totalScore = 0;
    int totalPlayed = 0;

    printf("===KUIS MATEMATIKA===\n");
    do { 
        printf("\nPilih Level Kesulitan:\n");
        printf("1. Mudah\n2. Sedang\n3. Sulit\n");
        printf("{{Pilih (1-3): ");
        scanf("%d, &level);

        if (level < 1 || level > 3) {
            printf("Pilihan ga ada");
    } else {
        int score = 0;
        printf ("\n---Level %d ---\n", level);

int main (){




return 0;
}
