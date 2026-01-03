#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// to define a structure to hold the player's data
struct Player {
	char name[50];
	int score;
};

void saveScore(char name[], int score);
void displayLeaderboard();
void searchPlayer(char searchName[]);


int main() {
    int mainMenu, mode, answer, correctResult;
	int num1, num2, min, max, currentScore = 0;
	char playerName[50], yesNo;
    int keepPlaying = 1;

	srand(time(NULL)); // Seed randomizer once at the start

    printf("Enter your name to start: ");
    scanf("%s", playerName);

	//Main Menu
 while (keepPlaying) {
        printf("\n=== Welcome to the Math Quiz ===\n");
        printf("1. Start the quiz\n");
        printf("2. View the Leaderboard\n");
        printf("3. Search for a Player\n");
        printf("4. Exit\n");
        printf("Choice: ");
        scanf("%d", &mainMenu);
       
    // Mode selection menu
	if (mainMenu == 1) {
        printf("\nSelect Mode: \n");
        printf("1. Easy (10 Points)\n");
        printf("2. Medium (20 Points)\n");
        printf("3. Hard (30 Points)\n");
        printf("Choice:\n");
        scanf("%d", &mode);


		//Ranges setting based on difficulty
                   // Set ranges based on mode
            if (mode == 1) {min = 1; max = 20; } 
            else if (mode == 2) {min = 21; max = 50; } 
            else if (mode == 3) {min = 51; max = 100; }
            else {printf("Invalid mode!\n"); continue; }

            // Generate Numbers
            num1 = (rand() % (max - min + 1)) + min;
            num2 = (rand() % (max - min + 1)) + min;
            correctResult = (mode == 1) ? (num1 + num2) : (num1 * num2);

            // Quiz Loop (stays on this question until correct)
            while (1) {
                printf("What is %d %s %d? ", num1, (mode == 1 ? "+" : "x"), num2);
                scanf("%d", &answer);
                if (answer == correctResult) {
                    int points = (mode == 1) ? 10 : (mode == 2 ? 20: 30);
                    currentScore += points;
                    printf("Correct! +%d points. Current Total: %d\n", points, currentScore);
                    break; // Exit the question loop
                } else {
                    printf("Incorrect. Try Again!\n");
                }
            }
        }
	else if (mainMenu == 2) {
            displayLeaderboard();
        }
        else if (mainMenu == 3) {
            char sName[50];
            printf("Enter name to search: ");
            scanf("%s", sName);
            searchPlayer(sName);
        }
        else if (mainMenu == 4) {
            saveScore(playerName, currentScore);
            printf("Score saved. Goodbye %s!\n", playerName);
            keepPlaying = 0;
        }
    }

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
