/*	Bryan Friestad
        bryanf@iastate.edu
        CPRE 185 Section Z

Programming Practice 2

	<Reflection 1 What were you trying to learn or achieve?>
		I was trying to make a tic tac toe game that you could
		play against a computer that simply selected moves based
		upon the random function.

    <Reflection 2 Were you successful? Why or Why not?>
        Yes, you can play against a computer and usually beat it.
		The program also checks for invalid input from the user to
		make sure that the game works properly. I made multiple 
		edits to the program along the way to make it more 
		intuitive. For example, I seeded the random function with
		the time so that. 
		
	<Reflection 3 Would you do anything differently if starting this program over?  If so, explain what.>
		I would figure out a more intuitive method of determining if
		someone has won the game. I would make it so that it works for
		any size board and it would also output who the winner of the
		game was. If I had an extra day or two for research and design,
		I would also create AI that is not perfect, but puts up a
		challenge for the player.

	<Reflection 4 Think about the most important thing you learned when writing this piece of code.  What was it and explain why it was significant.>
		I had a chance to practice 2 dimensional arrays as well
		as practice pointers in simple methods. This was also a
		great experience in the way that I got to create an
		interesting program from start to finish that I might
		actually use from time to time, which is actually what
		I've been trying to do with each one of these. I don't yet
		understand all of the uses and applications for pointers,
		but I do believe that they are incredibly important when
		creating large integrated programs.

	<Other questions/comments for Instructors>
        How exactly do AI neural networks work? Any good pages
		or videos that I should check out? Is it possible to
		talk about AI in lecture? Also who exactly grades and
		responds to these? I'm curious if it's the professor 
		or a TA.
*/

#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

//function prototypes here
void printBoard(char board[3][3]);
void userTurn(char board[3][3], int *lastX, int *lastY);
void compMove(char board[3][3], int *lastX, int *lastY);
bool checkIfWon(char board[3][3], char playerChar, int x, int y);


int main(void){
	
	char board[3][3] = {{'_', '_', '_'},
						{'_', '_', '_'},
						{'_', '_', '_'}};
	
	bool gameOver = false;
	int lastX, lastY;
	int numMoves = 0;
	
	//seed the random function
	srand((unsigned int) time(NULL));
	
	while(!gameOver){
		
		//computers turn
		compMove(board, &lastX, &lastY);
		//check if won
		gameOver = checkIfWon(board, 'O', lastX, lastY);
		//output to screen
		printBoard(board);
		++numMoves;
		
		if(!gameOver){
			//users turn
			userTurn(board, &lastX, &lastY);
			//check if won
			gameOver = checkIfWon(board, 'X', lastX, lastY);
			//output to screen
			printBoard(board);
			++numMoves;
		}
		
		fflush(stdout);
	}
	
	printf("Game over!\n");
	
	return 0;
}

//define functions here
void printBoard(char board[3][3]){
	
	int i, j;
	
	for(i = 0; i < 3; ++i){
		for(j = 0; j < 3; ++j){
			printf("%c ", board[i][j]);
		}
		printf("\n\n");
	}
}

void userTurn(char board[3][3], int *lastX, int *lastY){
	
	int run = 1;
	int x, y;

	while(run){
		//printf 'input position'
		printf("Please input the place you want to place your piece in the format 'Row Column'\n");
		printf("Example: '3 2'\n");
		//scanf
		scanf("%d %d", &x, &y);
		--x;
		--y;
		
		//if out of bounds
		if(x > 2 || x < 0 || y > 2 || y < 0){
			printf("Input out of bounds, please try again.\n");
		}
		
		else if(board[x][y] == '_'){
			board[x][y] = 'X';
			run = false;
			*lastX = x;
			*lastY = y;
		}
		else{
			//printf invalid
			printf("Space already filled, please select again.\n");
		}
	}
	return;
	
}

void compMove(char board[3][3], int *lastX, int *lastY){

	int run = 1;

	while(run){
		int x = rand() % 3;
		int y = rand() % 3;
		
		if(board[x][y] == '_'){
			board[x][y] = 'O';
			run = false;
			*lastX = x;
			*lastY = y;
		}
	}
	return;
}

bool checkIfWon(char board[3][3], char playerChar, int x, int y){
	
	int i;
	
	//check col
	for(i = 0; i < 3; ++i){
		if(board[x][i] != playerChar){
			break;
		}
		if(i == 2){
			return true;
		}
	}
	
	//check row
	for(i = 0; i < 3; ++i){
		if(board[i][y] != playerChar){
			break;
		}
		if(i == 2){
			return true;
		}
	}
	
	//check diag
	if(x == y){
		for(i = 0; i < 3; ++i){
			if(board[i][i] != playerChar){
				break;
			}
			if(i == 2){
				return true;
			}
		}
	}
	
	//check opposite diag
	for(i = 0; i < 3; ++i){
		if(board[i][2-i] != playerChar){
			break;
		}
		if(i == 2){
			return true;
		}
	}
	
	return false;
	
}

