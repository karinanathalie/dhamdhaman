#include <iostream>
#include <string>
#include "Posmove.h"
#include "checkmate.h"
#include <cctype>
using namespace std;
//The parameter of the function is player which can only hold the string of "o" or "x"
bool checkMate(string board[][8], string player)// This function checks whether 
                                                // one of the player gets a checkmate
{
    string temp = player;
    player[0] = player[0] -  32; //convert string player from lowercase to uppercase 
    //printboard(board);
    int countPiece =0;           //stores the number of pieces of either x or o
    int count = 0;               //If the piece cannot move, count gets incremented

    string moves;
    for(int row = 0; row < 8 ; row++)
    {
        for(int col = 0; col<8; col++)
        {
            if (board[row][col] == player || board[row][col] == temp)//if the piece is either (x or X)or(o or O) 
            {
                countPiece += 1;
            }
        }
    
    }
    for (int row = 0; row < 8; row++)
    {
        for (int col = 0; col < 8;col++)
        {
            if (board[row][col] == player || board[row][col] == temp)//To only match the string of parameter
            {
                //cout << board[row][col] << endl;
                //moves = Posmove(board,row,col);
                //cout << moves << endl;
                if (Posmove(board,row,col).length() == 0)
                {
    
                    count = count + 1;
                    //cout << count;
                }
            }
        }
    }
    //cout << count;

    if (count == countPiece)// if this condition is true checkmate occurs
    {
        return true;
    }
    return false;
}
