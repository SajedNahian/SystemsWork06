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
    //Assign random name
    int numberOfFirstNames = 6;
    int numberOfLastNames = 7;
    char * firstNames[] = {"James", "Mark", "Steven", "John", "Jack", "James"};
    char * lastNames[] = {"Smith", "Johnson", "Brown", "Miller", "Williams", "Davis", "Wilson"};
    char randomName[20];
    strcpy(randomName, firstNames[rand() % (numberOfFirstNames)]);
    strcat(randomName, " ");
    strcat(randomName, lastNames[rand() % (numberOfLastNames)]);
    strcpy(randomPlayer.name, randomName);

    //Assign random weight
    int minWeight = 120;
    int maxWeight = 280;
    randomPlayer.weight = rand() % (maxWeight + 1 - minWeight) + minWeight;

    //Assign random height
    int minHeight = 60;
    int maxHeight = 84; 
    randomPlayer.height = rand() % (maxHeight + 1 - minHeight) + minHeight;

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