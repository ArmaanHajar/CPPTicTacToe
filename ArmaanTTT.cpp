#include <iostream>

using namespace std;

void printBoard(char board[3][3]);
void clearBoard(char board[3][3]);

int main() {
  char board[3][3];

  int X_MOVE = 1;
  int O_MOVE = 2;
  int X_TURN = 0;
  int O_TURN = 1;
  int turn = X_TURN;
  int X_WINS = 0;
  int O_WINS = 0;
  bool newgame = true;

  clearBoard(board);

// hi hello

  board[0][0] = 'a';
  board[1][1] = 'a';
  board[2][2] = 'a';
  
  printBoard(board);

  cout << "Hello" << endl;
  cout << "Hi" << endl;
  cout << "Hey" << endl;

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
      board[a][b] = ' ';
    }
  }
}


// hello jeff, you are the best
// test again