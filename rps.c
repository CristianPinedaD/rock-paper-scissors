#include <stdio.h>
#include <stdlib.h>

int computerLogic();
void game();
int checkWin(int, int);
void pressAnyKeyToContinue();
void clearScreen();

void main() {

	srand(time(0)); // Generates a random seed every time you run.
    
	int playAgain = 1;
	int games = 0; 

	int scores[2] = {0}; // Score array (scores[0] is player score, scores[1] is computer score)

	// Game loop
	while (playAgain == 1) {
		int playerChoice;

		printf("Choose rock (1), paper (2), or scissors (3): ");
		scanf("%d", &playerChoice);

        switch (playerChoice) {
            case 1:
				puts("You chose rock");
				break;
            case 2:
				puts("You chose paper");
				break;
            case 3:
				puts("You chose scissors");
				break;
            default:
				puts("Invalid choice");
				exit(0); 
		}

		puts ("Computer is making a choice...");
		pressAnyKeyToContinue(); // Waits for the player to press any key to continue.

		int computerChoice = computerLogic(); // Calculates computer's choice for this round.

		switch (computerChoice) {
			case 1:
				puts("Computer chose rock");
				break;
			case 2: 
				puts("Computer chose paper");
				break;
			case 3:
				puts("Computer chose scissors");
				break;
		}

		puts("Calculating winner...");

		pressAnyKeyToContinue(); // Waits for the player to press any key to continue.

		int winner = checkWin(playerChoice, computerChoice); // Determines the winner for the round.

        switch (winner) {
            case 0:
				puts("It's a tie!");
				break;
            case 1:
				puts("You win!");
				scores[0]++; // Updates global player score.
				break;
            case 2:
				puts("You lose.");
				scores[1]++; // Updates global computer score.
				break;
		}

		pressAnyKeyToContinue(); // Waits for the player to press any key to continue.

		printf("Go again? Yes = 1, No = 2: "); // Gives the player an option to try again.
		scanf("%d", &playAgain);
		games++;  // Updates total games.'
		pressAnyKeyToContinue(); // Waits for the player to press any key to continue.
		clearScreen(); // Clears the screen for the next round.
	}


	// End state.
	printf("You have played %d games\n", games);
	printf("The total score was:\n");
	printf("Player: %d, Computer: %d\n", scores[0], scores[1]); 

    int player_percentage = (scores[0] * 100) / games ; // Just for the player to know.
	int computer_percentage = (scores[1] * 100) / games; // In case the computer won more times than the player.

	if (scores[0] > scores[1]) {
		printf("You won %d%% of the games, making you the overall winner!\n",
			   player_percentage);
	}
    else if (scores[1] > scores[0]) {
		printf("The computer won %d%% of the games, making it the overall "
			   "winner. You lost\n",
			   computer_percentage);
	}
    else {
		printf("The game ends with an overall tie.\n");
	}
}

int computerLogic() {
	int upperbound = 3; // Upper bound for random number calculation.
	int lowerbound = 1; // Lower bound for random number calculation.

	int value = rand() % (upperbound - lowerbound + 1) + lowerbound; // Calculates a random number between 1 and 3 (inclusive).

	return value; 
}

int checkWin(int playerChoice, int computerChoice) {
	if (playerChoice == computerChoice) {
		return 0; // It's a tie
	}
	if ((playerChoice == 1 && computerChoice == 3) || // Rock beats Scissors
		(playerChoice == 2 && computerChoice == 1) || // Paper beats Rock
		(playerChoice == 3 && computerChoice == 2)) { // Scissors beats Paper
		return 1;									  // Player wins
	}
	return 2; // Computer wins
}


void pressAnyKeyToContinue() {
	printf("Press any key to continue\n");
	getchar();
	getchar();
}

void clearScreen() {
	system("clear");
}