/*
 * C++ Tic Tac Toe
 * This is a two player game! X will always start.
 * 9/23/2024
 * Santiago Gaete
 */

#include <iostream>
#include <cstring>

using namespace std;

void printBoard();
bool isValid(char row, char col);
void placePlayer(char player, char row, char col);
void takeTurn(char player);

char row;
char col;
char player;
char board[3][3] = {
    { '-', '-', '-', },
    { '-', '-', '-', },
    { '-', '-', '-', }
};

int main() {
  char player = 'X';
  printBoard();
  takeTurn(player);
}

void printBoard() {
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

bool isValid(char row, char col) {
  cout << row << col << endl;
  if (board[row][col] == '-') { //heeeeeeeeeeeeeeeeerrrrrrrreeeeee
    return true;
    cout << "erm valid" << endl;
  }
  else {
    return false;
  }
}

void placePlayer(char player, char row, char col) {
  board[int(row)][int(col)] = player;
  printBoard();
}

void takeTurn(char player) {
  cout << player << "'s Turn!" << endl;
  cout << "Enter a row!" << endl;
  cin >> row;
  cout << "Enter a column!" << endl;
  cin >> col;
  if (isValid(row, col) == true) {
    placePlayer(player, row, col);
  }
  else {
    cout << "Please enter a valid move." << endl;
    takeTurn(player);
  }
}


