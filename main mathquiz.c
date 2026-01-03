#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct {
    char username[50];
    int points;
} Player;

void recordScore(char username[], int points);
void showLeaderboard();
void findPlayer(char target[]);

int main() {
    char playerName[50];
    int choice, difficulty, userAnswer, correctAnswer;
    int numA, numB, rangeMin, rangeMax, totalPoints = 0;
    int playAgain = 1;

	srand(time(NULL)); 

    printf("Enter your name to start: ");
    scanf("%s", playerName);

	// menu utamanya
 do {
        printf("\n=== Welcome to the Math Quiz ===\n");
        printf("1. Start the quiz\n");
        printf("2. View the Leaderboard\n");
        printf("3. Search for a Player\n");
        printf("4. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);
       
    // tingkat kesulitan nya
	if (choice == 1) {
            printf("\nSelect Mode: \n");
            printf("1. Easy (10 Points)\n");
            printf("2. Medium (20 Points)\n");
            printf("3. Hard (30 Points)\n");
            printf("Choice:\n");
            scanf("%d", &difficulty);

            if (difficulty == 1) {
                rangeMin = 1; rangeMax = 20;
            } else if (difficulty == 2) {
                rangeMin = 21; rangeMax = 50;
            } else if (difficulty == 3) {
                rangeMin = 51; rangeMax = 100;
            } else {
                printf("Invalid mode!\n");
                continue;
            }

            numA = rand() % (rangeMax - rangeMin + 1) + rangeMin;
            numB = rand() % (rangeMax - rangeMin + 1) + rangeMin;

            if (difficulty == 1) {
                correctAnswer = numA + numB;
            } else {
                correctAnswer = numA * numB;
            }

            // kuis berulang (tetep pertanyaan ini sampai bener)
            while (1) {
                printf("What is %d %s %d? ", numA, (difficulty == 1 ? "+" : "x"), numB);
                scanf("%d", &userAnswer);

                if (userAnswer == correctAnswer) {
                    int earned = (difficulty == 1) ? 10 : (difficulty == 2 ? 20 : 30);
                    totalPoints += earned;
                    printf("Correct! +%d points. Current Total: %d\n", earned, totalPoints);
                    break; // keluar dari pertanyaan ulangan
                } else {
                    printf("Incorrect. Try Again!\n");
                }
            }
        }
	else if (choice == 2) {
            showLeaderboard();
        }
        else if (choice == 3) {
            char search[50];
            printf("Enter name to search: ");
            scanf("%s", search);
            findPlayer(search);
        }
        else if (choice == 4) {
            recordScore(playerName, totalPoints);
            printf("Score saved. Goodbye %s!\n", playerName);
            playAgain = 0;
        }
    } while (playAgain);

    return 0;
}

void saveScore(char name[], int score) {
    FILE *fp = fopen("leaderboard.txt", "a");
    if (fp == NULL) return;
    fprintf(fp, "%s %d\n", name, score);
    fclose(fp);
}

void displayLeaderboard() {
    struct Player players [100];
    int count = 0;
    FILE *fp = fopen("leaderboard.txt", "r");

    if (fp == NULL) {
        printf("No records found.\n");
        return;
    }

    while (fscanf(fp, "%s %d", players[count].name, &players[count].score) != EOF) {
        count ++;
    }
    fclose(fp);

    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (players[j].score < players[j+1].score) {
            struct Player temp = players[j];
                players[j] = players[j+1];
                players[j+1] = temp;    
            }
        }
    }
printf("\n--- LEADERBOARD ---\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s - %d points\n", i + 1, players[i].name,players[i].score);
    }
}

void searchPlayer(char searchName[]) {
    struct Player p;
    FILE *fp = fopen("leaderboard.txt", "r");
    int found = 0;

    if (fp == NULL) return;

    while (fscanf(fp, "%s %d", p.name, &p.score) != EOF) {
        if (strcmp(p.name, searchName) == 0) {
            printf("Match found: %s has a score of %d\n", p.name, p.score);
            found = 1;
        }
    }
    if (!found) printf("Player not found\n");
    fclose(fp);
}
