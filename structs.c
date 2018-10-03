#include <stdio.h>
#include <string.h>
#include <time.h>
#include "footballplayer.h"

struct footballPlayer {
  char name[20];
  int weight;
  int height;
};

int main () {
    srand(time(NULL));

    // TEST #1
    formatPrint("RANDOM FOOTBALL PLAYER");
    struct footballPlayer randomPlayer = getRandomFootBallPlayer();
    printPlayer(randomPlayer);
    formatPrint("MODIFIED FOOTBALL PLAYER");
    randomPlayer = changePlayerAttributes(randomPlayer, "Tom Brady", 225, 76);
    printPlayer(randomPlayer);

    // TEST #2
    formatPrint("RANDOM FOOTBALL PLAYER");
    struct footballPlayer randomPlayer1 = getRandomFootBallPlayer();
    printPlayer(randomPlayer1);
    formatPrint("MODIFIED FOOTBALL PLAYER");
    randomPlayer1 = changePlayerAttributes(randomPlayer1, "Odell Beckham Jr", 198, 71);
    printPlayer(randomPlayer1);

    // TEST #3
    formatPrint("RANDOM FOOTBALL PLAYER");
    struct footballPlayer randomPlayer2 = getRandomFootBallPlayer();
    printPlayer(randomPlayer2);
    formatPrint("MODIFIED FOOTBALL PLAYER");
    randomPlayer2 = changePlayerAttributes(randomPlayer2, "Eli Manning", 218, 76);
    printPlayer(randomPlayer2);
}

struct footballPlayer getRandomFootBallPlayer () {
    struct footballPlayer randomPlayer;
    strcpy(randomPlayer.name, "John Doe");
    randomPlayer.weight = rand() % (280 + 1 - 120) + 120; 
    randomPlayer.height = rand() % (84 + 1 - 60) + 60;
    return randomPlayer;
}

void printPlayer (struct footballPlayer player) {
	printf("%s: %d pounds, %d inches\n", player.name, player.weight, player.height);
}

struct footballPlayer changePlayerAttributes (struct footballPlayer player, char newName[], int newWeight, int newHeight) {
	strcpy(player.name, newName);
	player.weight = newWeight;
	player.height = newHeight;
	return player;
} 

void formatPrint (char toPrint[]) {
	printf("--------------------\n");
	printf("%s\n", toPrint);
}
