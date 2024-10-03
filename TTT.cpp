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
  cout << "Welcome to Tic Tac Toe!" << endl;
  printBoard(board);

  while (checkWin(player, board) == false && checkTie(board) == false && game == true) { //while game is active
    takeTurn(player, board); //take turn
    if (player == 'X' && checkWin(player, board) == false) { //switch player
      player = 'O';
    }
    else if (checkWin(player, board) == false) { //switch player
      player = 'X';
    }
    if (checkWin(player, board) == true) { //if win
      cout << player << " wins!" << endl;
      //add to wincount
      if (player == 'X') {
	xWins++;
      }
      else {
	oWins++;
      }
      cout << "X has won " << xWins << " times." << endl;
      cout << "O has won " << oWins << " times." << endl;
      playAgain(game, player, board);
      player = 'X';
    }
    if (checkTie(board) == true) {
      cout << "Tie!" << endl;
      playAgain(game, player, board);
      player = 'X';
    }
  }
}

void printBoard(char board[3][3]) { //print out board
  cout << "\t0\t1\t2" << endl;
  cout << "\n" << endl;
  cout << "0\t" << board[0][0] << "\t" << board[0][1] << "\t" << board[0][2] << endl; //first row
  cout << "\n" << endl;
  cout << "1\t" << board[1][0] << "\t" << board[1][1] << "\t" << board[1][2] << endl; //second row
  cout << "\n" << endl;
  cout << "2\t" << board[2][0] << "\t" << board[2][1] << "\t" << board[2][2] << endl; //third row
}

bool isValid(int row, int col, char board[3][3]) {
  if (board[row][col] == '-') { //if empty (valid)
    return true;
  }
  else {
    return false;
  }
}

void placePlayer(char player, int row, int col, char board[3][3]) {
  board[row][col] = player; //change - to player
  printBoard(board); //reprint
}

void takeTurn(char player, char board[3][3]) {
  int row;
  int col;
  cout << player << "'s Turn!" << endl;
  cout << "Enter a row!" << endl;
  cin >> row;
  cout << "Enter a column!" << endl;
  cin >> col;
  if (isValid(row, col, board) == true) { //if valid
    placePlayer(player, row, col, board); //go place
  }
  else {
    cout << "Please enter a valid move." << endl;
    takeTurn(player, board); //retry
  }
}

bool checkRowWin(char player, char board[3][3]) {
  int win = 0;
  for (int a = 0; a < 3; a++) { //go through every row and check if it's all equal to player
    win = 0;
    for (int b = 0; b < 3; b++) {
      if (board[b][a] != player) {
	win++;
      }
    }
    if (win == 0) { //if everything's the same, you won!
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
  for (int a = 0; a < 3; a++) { //same thing, but we'll manually change b to make it diagonal
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
  for (int a = 3; a > 0; a--) { //same thing reversed
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
  for (int a = 0; a < 3; a++) { //go through every spot and see if they're all taken
    for (int b = 0; b < 3; b++) {
      if (board[a][b] != '-') {
	tie++;
      }
    }
    if (tie == 9) { //tie!
      return true;
    }
  }
  return false;
}

bool checkWin(char player, char board[3][3]) { //check possible wins and return
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
      //reset board
      for (int a = 0; a < 3; a++) {
	 for (int b = 0; b < 3; b++) {
	   board[a][b] = '-';
	 }
       }
       game = true;
       printBoard(board);
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
