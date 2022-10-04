/*
 * Author: Armaan Hajar
 * Description: A simple TicTacToe game in the console
 * Date: 10/3/2022
 */


#include <iostream>
#include <string>
#include <cstring>

using namespace std;

// calling all the functions
void printBoard(char board[3][3]);
void clearBoard(char board[3][3]);
bool checkWin(char board[3][3], int player);
bool checkTie(char board[3][3], int player);
void restartMessage(char board[3][3], bool& newgame);

int main() {
  // initializing variables
  char board[3][3];
  char str[3];

  char X_MOVE = 'X';
  char O_MOVE = 'O';
  int X_TURN = 0;
  int O_TURN = 1;
  int turn = X_TURN;
  int X_WINS = 0;
  int O_WINS = 0;
  bool newgame = true;

  clearBoard(board);

  // main game code, when user is done playing, newgame becomes false
  while (newgame == true) {

    turn = X_TURN;

    // when a win or tie hasnt been detected, run the game code
    while (checkWin(board, X_MOVE) == false && checkWin(board, O_MOVE) == false &&
	   checkTie(board, X_MOVE) == false && checkTie(board, O_MOVE) == false) {
      if (turn == X_TURN) {
	cout << "It's X's Turn!" << endl;
      }
      else {
	cout << "It's O's Turn!" << endl;
      }
      
      printBoard(board);
      
      cin.get(str, 3);
      cin.get();

      cout << "-----------------" << endl;

      // input validation
      if (strlen(str) != 2) {
	cout << "Please Enter A Valid Position!" << endl;
      }
      else if (str[0] != 'a' && str[0] != 'b' && str[0] != 'c') {
	cout << "Please Enter A Valid Position!" << endl;
      }
      else if (str[1] != '1' && str[1] != '2' && str[1] != '3') {
	cout << "Please Enter A Valid Position!" << endl;
      }
      // if input is valid, add it to the board
      else {
	int column = str[0] - 'a';
	int row = str[1] - '1';
	if (board[row][column] == '_') {
	  if (turn == X_TURN) { // x move
	    board[row][column] = X_MOVE;
	    turn = O_TURN;
	  }
	  else { // o move
	    board[row][column] = O_MOVE;
	    turn = X_TURN;
	  }
	}
	else { // when the board position is already taken
	  cout << "You Cannot Select This Location!" << endl;
	}
      }
    }
    // when x win is detected
    if (checkWin(board, X_MOVE) == true) {
      X_WINS++;
      printBoard(board);
      cout << "-----------------" << endl;
      cout << "X Wins!" << endl;
      cout << "X: " << X_WINS << endl;
      cout << "O: " << O_WINS << endl;
      restartMessage(board, newgame);
    }
    // when o win is detected
    else if (checkWin(board, O_MOVE) == true) {
      O_WINS++;
      printBoard(board);
      cout << "-----------------" << endl;
      cout << "O Wins!" << endl;
      cout << "X: " << X_WINS << endl;
      cout << "O: " << O_WINS << endl;
      restartMessage(board, newgame);
    }
    // when tie is detected
    else if (checkTie(board, O_MOVE) == true) {
      printBoard(board);
      cout << "-----------------" << endl;
      cout << "It's A Tie" << endl;
      cout << "X: " << X_WINS << endl;
      cout << "O: " << O_WINS << endl;
      restartMessage(board, newgame);
    }
    // when tie is detected 
    else if (checkTie(board, X_MOVE) == true) {
      printBoard(board);
      cout << "-----------------" << endl;
      cout << "It's A Tie" << endl;
      cout << "X: " << X_WINS << endl;
      cout << "O: " << O_WINS << endl;
      restartMessage(board, newgame);
    }
  }
  
  return 0;
}

// prints board
void printBoard(char board[3][3]) {
  cout << "  1 2 3" << endl;
  cout << "a " << board[0][0] << ' ' << board[1][0] << ' ' << board[2][0] << endl;
  cout << "b " << board[0][1] << ' ' << board[1][1] << ' ' << board[2][1] << endl;
  cout << "c " << board[0][2] << ' ' << board[1][2] << ' ' << board[2][2] << endl;
}

// sets every board position to an underscore
void clearBoard(char board[3][3]) {
  for (int a = 0; a < 3; a++) {
    for (int b = 0; b < 3; b++) {
      board[a][b] = '_';
    }
  }
}

// win detection
bool checkWin(char board[3][3], int player) {
  if (board[0][0] == player && board[0][1] == player && board[0][2] == player) {
    return true;
  }
  if (board[1][0] == player && board[1][1] == player && board[1][2] == player) {
    return true;
  }
  if (board[2][0] == player && board[2][1] == player && board[2][2] == player) {
    return true;
  }
  if (board[0][0] == player && board[1][0] == player && board[2][0] == player) {
    return true;
  }
  if (board[0][1] == player && board[1][1] == player && board[2][1] == player) {
    return true;
  }
  if (board[0][2] == player && board[1][2] == player && board[2][2] == player) {
    return true;
  }
  if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
    return true;
  }
  if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
    return true;
  }
  return false;
}

// if there are no empty spaces on the board and no win has been detected, a tie has happened
bool checkTie(char board[3][3], int player) {
  for (int a = 0; a < 3; a++) {
    for (int b = 0; b < 3; b++) {
      if (board[a][b] == '_') {
	return false;
      }
    }
  }
  return true;
}

// after every win or tie, this function is called to see if the user wants to play again
void restartMessage(char board[3][3], bool& newgame) {
  char yorn;

  cout << "-----------------" << endl;
  cout << "Do You Want To Play Again? (Y/N)" << endl;
  cin.get(yorn);
  cin.get();

  if (yorn == 'Y' || yorn == 'y') {
    cout << "Restarting!" << endl;
    clearBoard(board);
    cout << endl;
  }
  else {
    cout << "Thank You For Playing" << endl;
    newgame = false;
  }
}

// hello jeff, you are the best
// you too rahul
