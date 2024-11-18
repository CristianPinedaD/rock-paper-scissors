#include <stdio.h>
#include <stdlib.h>

int computerLogic();
void game();
int checkWin(int, int);

void game() {
	int playAgain = 1;
	int games = 1;

	int scores[2] = {0};

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

		int computerChoice = computerLogic();

		int winner = checkWin(playerChoice, computerChoice);

        switch (winner) {
            case 0:
				puts("It's a tie!");
				break;
            case 1:
				puts("You win!");
				scores[0]++;
				break;
            case 2:
				puts("You lose");
				scores[1]++;
				break;
		}

		printf("Go again? Yes = 1, No = 2");
		scanf("%d", &playAgain);
		games++; 
	}

	printf("You have played %d games\n", games);
	printf("The total score was:\n");
	printf("Player: %d, Computer: %d", scores[0], scores[1]); 

    if (scores[0] > scores[1]) {
		printf("You won %d%% of the games, making you the overall winner!\n",
			   (scores[0] / games) * 100);
	}
    if (scores[1] > scores[0]) {
		printf("The computer won %d%% of the games, making it the overall "
			   "winner. You lost\n",
			   (scores[1] / games) * 100);
	}
    else {
		printf("The game ends with an overall tie.\n");
	}
}

int computerLogic() {
	int upperbound = 3;
	int lowerbound = 1;

	int value = rand() % (upperbound - lowerbound + 1) + lowerbound;

	return value; 
}

int checkWin(int playerChoice, int computerChoice) {

    if (playerChoice > computerChoice) {
			return 1;
	}
    
    if (playerChoice < computerChoice) {
		return 2;
	}

    else {
		return 0; 
	}
}
