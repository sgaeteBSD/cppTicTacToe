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
bool playAgain(bool game, char player, char board[3][3]);

int main() {
  char player = 'X';
  bool game = true;
  int xWins = 0;
  int oWins = 0;
  char board[3][3] = {
    { '-', '-', '-', },
    { '-', '-', '-', },
    { '-', '-', '-', }
  };
  printBoard(board);

  while (checkWin(player, board) == false && checkTie(board) == false && game == true) {
    takeTurn(player, board);
    if (player == 'X' && checkWin(player, board) == false) {
      player = 'O';
    }
    else if (checkWin(player, board) == false) {
      player = 'X';
    }
    if (checkWin(player, board) == true) {
      cout << player << " wins!" << endl;
      if (player == 'X') {
	xWins++;
      }
      else {
	oWins++;
      }
      cout << "X has won " << xWins << " times." << endl;
      cout << "O has won " << oWins << " times." << endl;
      playAgain(game, player, board);
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
  if (board[row][col] == '-') { //heeeeeeeeeeeeeeeeerrrrrrrreeeeee
    return true;
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
    return true;
  }
  return false;
}

bool playAgain(bool game, char player, char board[3][3]) {
  bool gameCheck = true;
  while (gameCheck == true) { //just so we can keep looping if invalid
    char input = 'a';
    cout << "Would you like to play again? (y/n)" << endl;
    cin >> input;
    if (input == 'y') { //play again
      //reset
      for (int a = 0; a < 3; a++) {
	 for (int b = 0; b < 3; b++) {
	   board[a][b] = '-';
	 }
       }
       game = true;
       printBoard(board);
       player = 'X';
       return true;
     }
     else if (input == 'n') { //end program
       cout << "Bye!" << endl;
       gameCheck = false; //end loop
       return false;
     }
     else { //if not y/n
       cout << "Invalid input! Try again!" << endl;
       cin.clear(); //clear fail flag
       cin.ignore(10000,'\n'); //go to next line
     }	 
  }
  return 0;
}
