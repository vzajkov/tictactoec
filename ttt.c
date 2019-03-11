#include "stdio.h"
#include <stdlib.h>
#include <time.h>

const int NOUGHTS = 1;
const int CROSSES = 2;
const int EMPTY = 0;
const int BORDER = 3;

const int convertToTwentyFive[9] = {
  6,7,8,11,12,13,16,17,18
};

void initializeBoard(int *board) {

  for (int i = 0; i < 25 ; i++ ) {
    board[i] = BORDER;
  }

  for (int j = 0; j < sizeof(convertToTwentyFive) / sizeof(convertToTwentyFive[0]); j++) {
    board[convertToTwentyFive[j]] = EMPTY;
  }

}

void computerMove(int *board) {
  int moveFound = 0;
  int move;
  time_t t;

  srand((unsigned) time(&t));
  
  while (!moveFound) {
    move = rand() % 9;
    if (board[convertToTwentyFive[move]] == 0) {
      board[convertToTwentyFive[move]] = 2;
      moveFound = 1;
    }
  }
}

void printBoard(int *board) {
  printf("\nBoard:\n");

  for (int i = 0; i < 25; i++ ) {
    if (i > 0 && i % 5 == 0) {
      printf("\n");
    }
    printf("%3d",board[i]);
  }

  printf("\n");

}

void runGame(int *board) {
  char move[4];
  int movePos;
  int gameWon = 0;
  int moves = 0;
  int moveValid = 0;
  
  while (!gameWon) {
    while (!moveValid) {
      printf("\nMake a Move: 0 - 9 only\n");
      fgets(move, 3, stdin);
      fflush(stdin);

      if ( sscanf(move, "%d", &movePos) != 1) {
        printf("Invalid sscanf\n");
        continue;
      }
      
      if (movePos > 9 || movePos < 0) {
        printf("\nInvalid Move\n");
        continue;
      } 
      
      if (board[convertToTwentyFive[movePos]] != 0) {
        printf("\nInvalid Move\n");
        continue;
      } 
    
      board[convertToTwentyFive[movePos]] = 1;
      moveValid = 1;
    }
    computerMove(&board[0]);
    moveValid = 0;
    printBoard(&board[0]);
  }
  
   
}



int main() {
  int board[25];
  int *boardPointer = &board[0];
  
  initializeBoard(boardPointer);
  runGame(boardPointer);
  //printBoard(boardPointer);
  return 0;

}
