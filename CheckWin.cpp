#include <iostream>
#include "CheckWin.h"
using namespace std;

/* To check whether the total number of piece is 0 or not and 
determine whether the current player has won the game
uses 2 parameters, bool player to determine whose turn is it and the string array from board to check the game condition
it'll return true if someone has won the game and false if no one has won.
*/
bool CheckWin(bool player, string board[8][8]){
    string piece = "o", ultrapiece="O"; //if it is 0 then one of the player wins.
    if (player == false){
        piece = "x";
        ultrapiece = "X";
    }
    int row = 8, collumn = 8;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < collumn; j++){
            if (board[i][j]==piece || board[i][j]==ultrapiece){
                return false;
            }
        }
    }
    return true;
}