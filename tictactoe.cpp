//Brenna Reed  10/3/17 Two player TicTacToe
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <cstring>
using namespace std;
bool checkO(char[][4]);
bool checkX(char[][4]);
bool checktie(char[][4]);
int main()
{
  char board [4][4];
  int turn = 1;
  char a;
  int b;
  bool playing = true;
  bool running = true;
  int oCount = 0;
  int xCount = 0;
  int tieCount = 0;
  bool oWin = false;
  bool xWin = false;
  bool tie = false;
  //while running
  while(running == true){
    //set array blank
    for(int i = 0; i<4; i++){
      for(int j = 0; j<4; j++){
	board[i][j] = '\0';
      }
    }
    //put in labels
      board[1][0] = 'a';
      board[2][0] = 'b';
      board[3][0] = 'c';
      board[0][1] = '1';
      board[0][2] = '2';
      board[0][3] = '3';
      //print board
      for(int i = 0; i<4; i++){
	for(int j = 0; j<4; j++){
	  cout << board[i][j] << " ";
	}
	cout << endl;
      }
      playing = true;
    while(playing == true){
      //prompt user for move and put in array, switch who's turn it is
      cout << "Enter move!" << endl;
      cin >> a;
      cin >> b;
      if (board [int(a) - 96] [b] == '\0'){
      
	if(turn == 1){
	  board [int(a) - 96] [b] = 'X';
	  turn = 0;
	}
	
	else{
	  board[int(a)-96][b] = 'O';
	  turn = 1;
	}
	//Print board
	for(int i = 0; i<4; i++){
	  for(int j = 0; j<4; j++){
	    cout << board[i][j] << " ";
	  }
	  cout << endl;
	}
	//Check for wins and ties
	oWin = checkO(board);
	xWin  = checkX(board);
	tie = checktie(board);
        //If there are wins or ties, tell them, change values, tell wins and ties, restart from beginning 
	if (oWin == true){
	  oCount++;
	  cout << "O won!" << endl;
	  cout << "X:" << xCount << " O:" << oCount << " Ties:" << tieCount << endl;
	  playing = false;
	}
	if (xWin == true){
	  xCount++;
	  cout << "X won!" << endl;
	  cout << "X:" << xCount << " O:" << oCount << " Ties:" << tieCount << endl;
	  playing = false;
	}
	if (tie == true){
	  tieCount++;
	  cout << "You tied!" << endl;
	  cout << "X:" << xCount << " O:" << oCount << " Ties:" << tieCount << endl;
	  playing = false;
	}
	
      }
      
      else{
	cout << "That is not a legal move!" << endl;
      }
    }
  }
}
  
bool checkO(char board[][4]){
  //check for a win
    if ((board[1][1] == 'O' &&  board [1][2] == 'O' && board[1][3] == 'O')||
	(board[2][1] == 'O' &&  board [2][2] == 'O' && board[2][3] == 'O')||
	(board[3][1] == 'O' &&  board [3][2] == 'O' && board[3][3] == 'O')||
	(board[1][1] == 'O' &&  board [2][1] == 'O' && board[3][1] == 'O')||
	(board[1][2] == 'O' &&  board [2][2] == 'O' && board[3][2] == 'O')||
	(board[1][3] == 'O' &&  board [2][3] == 'O' && board[3][3] == 'O')||
	(board[1][1] == 'O' &&  board [2][2] == 'O' && board[3][3] == 'O')||
	(board[3][1] == 'O' &&  board [2][2] == 'O' && board[1][3] == 'O')){
      return true;
    }
    return false;
}

bool checkX(char board[][4]){
  //return true if x win
  if ((board[1][1] == 'X' &&  board[1][2]  == 'X' && board[1][3] == 'X')||
      (board[2][1] == 'X' &&  board [2][2] == 'X' && board[2][3] == 'X')||
      (board[3][1] == 'X' &&  board [3][2] == 'X' && board[3][3] == 'X')||
      (board[1][1] == 'X' &&  board [2][1] == 'X' && board[3][1] == 'X')||
      (board[1][2] == 'X' &&  board [2][2] == 'X' && board[3][2] == 'X')||
      (board[1][3] == 'X' &&  board [2][3] == 'X' && board[3][3] == 'X')||
      (board[1][1] == 'X' &&  board [2][2] == 'X' && board[3][3] == 'X')||
      (board[3][1] == 'X' &&  board [2][2] == 'X' && board[1][3] == 'X')){
    return true;
  }
  return false;
}

bool checktie(char board[][4]){
  //return true if tie
    if (board [1][1] != '\0' &&
	board [1][2] != '\0' &&
	board [1][3] != '\0' &&
	board [2][1] != '\0' &&
	board [2][2] != '\0' &&
	board [2][3] != '\0' &&
	board [3][1] != '\0' &&
	board [3][2] != '\0' &&
	board [3][3] != '\0') {
      return true;
    }
    return false;
  }
