#include <iostream>
#include <string>
#include <cstring>

using namespace std;

void printBoard(char board[3][3]);
void clearBoard(char board[3][3]);
bool checkWin(char board[3][3], int player);
bool checkTie(char board[3][3], int player);
void restartMessage(char board[3][3], bool newgame);

int main() {
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

  while (newgame == true) {

    if (checkWin(board, X_MOVE) == true) {
      cout << "win x" << endl;
    }
    if (checkWin(board, O_MOVE) == true) {
      cout << "win o" << endl;
    }
    if (checkTie(board, X_MOVE) == true) {
      cout << "tie x" << endl;
    }
    if (checkTie(board, O_MOVE) == true) {
      cout << "tie o" << endl;
    }

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
      
      if (strlen(str) != 2) {
	cout << "Please Enter A Valid Position 1!" << endl;
      }
      else if (str[0] != 'a' && str[0] != 'b' && str[0] != 'c') {
	cout << "Please Enter A Valid Position 2!" << endl;
      }
      else if (str[1] != '1' && str[1] != '2' && str[1] != '3') {
	cout << "Please Enter A Valid Position 3!" << endl;
      }
      else {
	int column = str[0] - 'a';
	int row = str[1] - '1';
	if (board[row][column] == '_') {
	  if (turn == X_TURN) {
	    board[row][column] = X_MOVE;
	    turn = O_TURN;
	  }
	  else {
	    board[row][column] = O_MOVE;
	    turn = X_TURN;
	  }
	}
	else {
	  cout << "You Cannot Select This Location!" << endl;
	}
      }
    }
    if (checkWin(board, X_MOVE) == true) {
      X_WINS++;
      printBoard(board);
      cout << "X Wins!" << endl;
      cout << "X: " << X_WINS << endl;
      cout << "O: " << O_WINS << endl;
      restartMessage(board, newgame);
    }
    else if (checkWin(board, O_MOVE) == true) {
      O_WINS++;
      printBoard(board);
      cout << "O Wins!" << endl;
      cout << "X: " << X_WINS << endl;
      cout << "O: " << O_WINS << endl;
      restartMessage(board, newgame);
    }
    else if (checkTie(board, O_MOVE) == true) {
      printBoard(board);
      cout << "It's A Tie" << endl;
      cout << "X: " << X_WINS << endl;
      cout << "O: " << O_WINS << endl;
      restartMessage(board, newgame);
    }
    else if (checkTie(board, X_MOVE) == true) {
      printBoard(board);
      cout << "It's A Tie" << endl;
      cout << "X: " << X_WINS << endl;
      cout << "O: " << O_WINS << endl;
      restartMessage(board, newgame);
    }
  }
  
  return 0;
}

void printBoard(char board[3][3]) {
  cout << "  1 2 3" << endl;
  cout << "a " << board[0][0] << ' ' << board[1][0] << ' ' << board[2][0] << endl;
  cout << "b " << board[0][1] << ' ' << board[1][1] << ' ' << board[2][1] << endl;
  cout << "c " << board[0][2] << ' ' << board[1][2] << ' ' << board[2][2] << endl;
}

void clearBoard(char board[3][3]) {
  for (int a = 0; a < 3; a++) {
    for (int b = 0; b < 3; b++) {
      board[a][b] = '_';
    }
  }
}

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
  if (board[0][1] == player && board[1][1] == player && board[2][0] == player) {
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

void restartMessage(char board[3][3], bool newgame) {
  char yorn;
  
  cout << "Do You Want To Play Again? (Y/N)" << endl;
  cin.get(yorn);

  if (yorn == 'Y' || yorn == 'y') {
    cout << "Restarting!" << endl;
    clearBoard(board);
  }
  else {
    cout << "Thank You For Playing" << endl;
    newgame = false;
  }
  return newgame;
}

// hello jeff, you are the best
// test again
