#include <iostream>
#include <vector>
#include <string>
#include <cctype>

//numbers to represent the 9 boxes in the tic tac toe grid
//this will only work with later versions of the c compiler
std::vector<char> values = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };

//boolean representing the two players
bool player1Turn = true;

void displayBoard(std::vector<char> values) {
	std::string board = "";
	
	int i;
	for (i = 0; i < 9; i++) {
		board += values[i];
		if (i % 3 == 2) {
			board += '\n';
		}
		else {
			board += '|';
		}
	}

	std::cout << board << std::endl;
}

bool hasWinner(std::vector<char> values) {
	char winningChar; std::string winMessage;
	if (player1Turn) {
		winningChar = 'X';
		winMessage = "Player 1 wins!";
	}
	else {
		winningChar = 'O';
		winMessage = "Player 2 wins!";
	}

	int i; int j;
	//checking horizontals
	for (i = 0; i < 9; i += 3) {
		for (j = 0; j < 3; j++) {
			if (values[i + j] == winningChar) {
				if (j == 2) {
					std::cout << winMessage << std::endl;
					return true;
				}
				else continue;
			}
			else break;
		}
	}

	//checking verticals
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 9; j += 3) {
			if (values[i + j] == winningChar) {
				if (j == 6) {
					std::cout << winMessage << std::endl;
					return true;
				}
				else continue;
			}
			else break;
		}
	}

	//checking diagonals
		//left leaning
		for (i = 0; i < 9; i += 4) {
			if (values[i] == winningChar) {
				if (i == 8) {
					std::cout << winMessage << std::endl;
					return true;
				}
				else continue;
			}
			else break;
		}
		//right leaning
		for (i = 3; i < 8; i += 2) {
			if (values[i] == winningChar) {
				if (i == 6) {
					std::cout << winMessage << std::endl;
					return true;
				}
				else continue;
			}
			else break;
		}

		return false;
}

int main() {
	int turnCount = 0;
	while (true) { //for play again?
		displayBoard(values);
		bool noWinner = true;
		do { //keeps going to next turn
			int input;
			do { //making sure input is valid

				if (player1Turn) {
					std::cout << "Player 1's Turn: ";
				}
				else std::cout << "Player 2's Turn: ";
				
				std::string rawInput;
				std::cin >> rawInput; //taking user input
				try {
					input = std::stoi(rawInput);
					if (input < 1 || input > 9) {
						std::cout << "Please enter an integer from 1 to 9!" << std::endl;
						continue;
					}
					if (values[input - 1] == 'X' || values[input - 1] == 'O') {
						std::cout << "Cell already taken!" << std::endl;
						continue;
					}
					if (player1Turn) {
						values[input - 1] = 'X';
					}
					else {
						values[input - 1] = 'O';
					}

					turnCount++;
					break;
				}
				catch (std::out_of_range) {
					std::cout << "Please enter an integer from 1 to 9!" << std::endl;
					continue;
				}
				catch (std::invalid_argument) {
					std::cout << "Please enter an integer from 1 to 9!" << std::endl;
					continue;
				}
			} while (true);

			displayBoard(values);
			
			if (hasWinner(values)) {
				break;
			}
			if (turnCount == 9) {
				std::cout << "It's a draw!" << std::endl;
				break;
			}
			player1Turn = !player1Turn;
		} while (true);

		std::cout << "Play again? (y/n): ";
		std::string rawInput;
		std::cin >> rawInput;
		if (rawInput.at(0) == 'y') {
			values = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
			std::cout << std::endl;
			continue;
		}
		else break;
	}
}