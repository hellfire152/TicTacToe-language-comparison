import java.util.InputMismatchException;
import java.util.Scanner;

public class TicTacToe_java {

	//numbers to present the 9 boxes in the tic tac toe grid
	static char[] values = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
	
	static boolean player1Turn = true;
	
	static void displayBoard(char[] values) {
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < 9; i++) {
			sb.append(values[i]);
			if (i % 3 == 2) {
				sb.append('\n');
			} else {
				sb.append('|');
			}
		}
		System.out.println(sb.toString());
	}
	
	static boolean hasWinner(char[] values) {
		char winningChar;
		String winMessage;
		if(player1Turn) {
			winningChar = 'X';
			winMessage = "Player 1 wins!";
		} else {
			winningChar = 'O';
			winMessage = "Player 2 wins!";
		}
		
		//checking horizontals
		for (int i = 0; i < 9; i += 3) {
			for (int j = 0; j < 3; j++) {
				if (values[i + j] == winningChar) {
					if (j == 2) {
						System.out.println(winMessage);
						return true;
					} else continue;
				} else break;
			}
		}
		
		//checking verticals
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 9; j++) {
				if (values[i + j] == winningChar) {
					if (j == 6) {
						System.out.println(winMessage);
						return true;
					} else continue;
				} else break;
			}
		}
		
		
		//checking diagonals
			//;eft leaning
			for (int i = 0; i < 9; i += 4) {
				if (values[i] == winningChar) {
					if (i == 8) {
						System.out.println(winMessage);
						return true;
					} else continue;
				} else break;
			}
			//right leaning
			for (int i = 3; i < 8; i += 2) {
				if (values[i] == winningChar) {
					if (i == 6) {
						System.out.println(winMessage);
						return true;
					}
				}
			}
			
		return false;
	}
	
	public static void main(String[] args) {
		int turnCount = 0;
		while (true) {	//for play again?
			displayBoard(values);
			boolean noWinner = true;
			
			do {	//keeps going to the next turn
				int input;
				do {	//to make sure the input is valid
					
					//prompt for player input
					if (player1Turn) {
						System.out.print("Player 1's Turn: ");
					} else {
						System.out.println("Player 2's Turn: ");
					}
					
					try {
						input = new Scanner(System.in).nextInt();
						if (input < 1 || input > 9) throw new InputMismatchException();
						if (values[input - 1] == 'X' || values[input - 1] == 'O') {
							System.out.println("Cell already taken!");
							continue;
						}
						
						
						if (player1Turn) {
							values[input - 1] = 'X';
						} else {
							values[input - 1] = 'O';
						}
						
						System.out.println();
						turnCount++;
						break;
					} catch (InputMismatchException e) {
						System.out.println("Enter an integer between 1 and 9!");
						continue;
					}
					
				} while (true);
				
				displayBoard(values);
				if (hasWinner(values)) {
					break;
				} else if (turnCount == 9) {
					System.out.println("It's a draw!");
					break;
				}
				player1Turn = !player1Turn;
			} while (true);
			
			System.out.print("Play again? (y/n): ");
			if (new Scanner(System.in).next().charAt(0) == 'y') {
				values.equals(new char[]{'1', '2', '3', '4', '5', '6', '7', '8', '9'});
				turnCount = 0;
				continue;
			} else {
				break;
			}
		}
	}
}
