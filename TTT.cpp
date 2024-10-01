/*
 * C++ Tic Tac Toe
 * This is a two player game! X will always start.
 * 9/23/2024
 * Santiago Gaete
 */

#include <iostream>
#include <cstring>

using namespace std;

void printBoard(char board[3][3]);
bool isValid(int row, int col, char board[3][3]);
void placePlayer(char player, int row, int col, char board[3][3]);
void takeTurn(char player, char board[3][3]);

bool checkRowWin(char player, char board[3][3]);
bool checkColWin(char player, char board[3][3]);
bool checkDiagWin(char player, char board[3][3]);
bool checkWin(char player, char board[3][3]);
bool checkTie(char board[3][3]);


int main() {
  char player = 'X';
  char board[3][3] = {
    { '-', '-', '-', },
    { '-', '-', '-', },
    { '-', '-', '-', }
  };
  printBoard(board);

  while (checkWin(player, board) == false && checkTie(board) == false) {
    takeTurn(player, board);
    if (player == 'X' && checkWin(player, board) == false) {
      player = 'O';
    }
    else if (checkWin(player, board) == false) {
      player = 'X';
    }
    if (checkTie(board) == true) {
      cout << "Tie!" << endl;
    }
  }
}

void printBoard(char board[3][3]) {
  cout << "Welcome to Tic Tac Toe!" << endl;
  cout << "\n" << endl;
  cout << "\t0\t1\t2" << endl;
  cout << "\n" << endl;
  cout << "0\t" << board[0][0] << "\t" << board[0][1] << "\t" << board[0][2] << endl;
  cout << "\n" << endl;
  cout << "1\t" << board[1][0] << "\t" << board[1][1] << "\t" << board[1][2] << endl;
  cout << "\n" << endl;
  cout << "2\t" << board[2][0] << "\t" << board[2][1] << "\t" << board[2][2] << endl;
}

bool isValid(int row, int col, char board[3][3]) {
  cout << row << col << endl;
  if (board[row][col] == '-') { //heeeeeeeeeeeeeeeeerrrrrrrreeeeee
    return true;
    cout << "erm valid" << endl;
  }
  else {
    return false;
  }
}

void placePlayer(char player, int row, int col, char board[3][3]) {
  board[row][col] = player;
  printBoard(board);
}

void takeTurn(char player, char board[3][3]) {
  int row;
  int col;
  cout << player << "'s Turn!" << endl;
  cout << "Enter a row!" << endl;
  cin >> row;
  cout << "Enter a column!" << endl;
  cin >> col;
  if (isValid(row, col, board) == true) {
    placePlayer(player, row, col, board);
  }
  else {
    cout << "Please enter a valid move." << endl;
    takeTurn(player, board);
  }
}

bool checkRowWin(char player, char board[3][3]) {
  int win = 0;
  for (int a = 0; a < 3; a++) {
    win = 0;
    for (int b = 0; b < 3; b++) {
      if (board[b][a] != player) {
	win++;
      }
    }
    if (win == 0) {
      return true;
    }
  }
  return false;
}

bool checkColWin(char player, char board[3][3]) {
  int win = 0;
  for (int a = 0; a < 3; a++) {
    win = 0;
    for (int b = 0; b < 3; b++) {
      if (board[a][b] != player) {
	win++;
      }
    }
    if (win == 0) {
      return true;
    }
  }
  return false;
}

bool checkDiagWin(char player, char board[3][3]) {
  int win = 0;
  int b = 0;
  for (int a = 0; a < 3; a++) {
    if (board[a][b] != player) {
      win++;
    }
    b++;
  }
    if (win == 0) {
      return true;
    }
    
  win = 0;
  b = 0;
  for (int a = 3; a > 0; a--) {
    if (board[a][b] != player) {
      win++;
    }
    b++;
  }
    if (win == 0) {
      return true;
    }
    
  return false;
}

bool checkTie(char board[3][3]) {
  int tie = 0;
  for (int a = 0; a < 3; a++) {
    for (int b = 0; b < 3; b++) {
      if (board[a][b] != '-') {
	tie++;
      }
    }
    if (tie == 9) {
      return true;
    }
  }
  return false;
}

bool checkWin(char player, char board[3][3]) {
  if (checkColWin(player, board) == true || checkRowWin(player, board) == true || checkDiagWin(player, board) == true) {
    cout << player << " wins!" << endl;
    return true;
  }
  return false;
}
