#include <iostream>
#include <string>
#include "Posmove.h"
using namespace std;

//The parameter of the function are the row and column, the indexes of the board array
//The function returns a string of all possible moves
string Posmove(string board[][8], int row, int column)//This function returns all the possible/available moves of the selected piece
{
    string posmove = "";
    
   
    
    if (board[row][column] == "x")
    {    
        if ((row-1>=0)&&(column+1<=7) && board[row-1][column+1] == ".")//If the piece can move up-right
        {
            posmove = posmove + "UR ";  
            
        }
                
        else if(((row-2>=0)&&(column+2<=7) && board[row-1][column+1] == "o" || board[row-1][column+1] == "O" )&& board[row-2][column+2] == ".")
        {
            posmove = posmove + "EUR ";  //If the piece can kill the opponent on its up-right
            
        }
            

        if ((row-1>=0)&&(column-1>=0) && board[row-1][column-1] == ".")//If the piece can move up-left
        {
            posmove = posmove + "UL ";   
        }
        else if((row-2>=0)&&(column-2>=0) && (board[row-1][column-1] == "o" || board[row-1][column-1] == "O") && board[row-2][column-2] == ".")
        {
            posmove = posmove + "EUL ";  //If the piece can eat the opponent on its up-left 
        }
    }


    else if (board[row][column] == "o")
    {
        if ((row+1<=7)&&(column+1<=7) && board[row+1][column+1] == ".")
        {
            posmove = posmove + "DR ";  //If the piece can move down-right
          
        }
        else if((row+2<=7)&&(column+2<=7) && (board[row+1][column+1] == "x" || board[row+1][column+1] == "X") && board[row+2][column+2] == ".")
        {
            posmove = posmove + "EDR "; //If the piece can eat the oppoment on its down-right
            
        }
            

        if ((row+1<=7)&&(column-1>=0) && board[row+1][column-1] == ".")
        {
            posmove = posmove + "DL ";   //If the piece can move down-left
        }
        else if((row+2<=7)&&(column-2>=0) && (board[row+1][column-1] == "x" || board[row+1][column-1] == "X") && board[row+2][column-2] == ".")
        {
            posmove = posmove + "EDL "; //If the piece can eat the opponent on its down-left
            
        }
    }
    else if (board[row][column] == "X")
    {
        
        if ((row-1 >=0) && (column+1)<=7 && (board[row-1][column+1] == "."))// If the piece can move up-right
        {
            
            posmove = posmove + "UR "; 
        }
        else if ( (row-2 >= 0 ) && (column+2<=7) && (board[row-1][column+1] == "o" || board[row-1][column+1] == "O") && (board[row-2][column+2] == "."))
        {
           
            posmove = posmove + "EUR "; //If the piece can eat its opponent on its up-right
        }
      
        if ((row+1<=7) && (column+1 <=7) && board[row+1][column+1] == ".")
        {
            
            posmove = posmove + "DR "; //If the piece can move down-right
        }
        else if ((row+2 <= 7) && (column+2<=7) && (board[row+1][column+1] == "o" || board[row+1][column+1] == "O")&& (board[row+2][column+2] == "."))
        {
           
            posmove = posmove + "EDR "; //If the piece can eat its opponent on its down-right
        }
            
            
        if ((row-1>=0) && (column-1 >=0) && board[row-1][column-1] == ".")
        {
            
            posmove = posmove + "UL "; //If the piece can move up-left
        }
        else if ((row-2 >= 0)&&(column-2>=0) && (board[row-1][column-1] == "o" || board[row-1][column-1] == "O")&& (board[row-2][column-2] == "."))
        {
            
            posmove = posmove + "EUL "; //If the piece can eat its opponent on its up-left
        }
    
        if ((row+1 <=7) && (column-1 >=0) && board[row+1][column-1] == ".")
        {
           
            posmove = posmove + "DL "; //If the piece can move down-left
        }
        else if ((row+2 <= 7)&&(column-2>=0) && (board[row+1][column-1] == "o" || board[row+1][column-1] == "O")&& (board[row+2][column-2] == "."))
        {
      
            posmove = posmove + "EDL "; //If the piece can eat its opponent on its down-left
        }
    }
    else if (board[row][column] == "O")
    {
    
        if ((row-1 >=0) && (column+1)<=7 && (board[row-1][column+1] == "."))//If the piece can move up-right
        {
            posmove = posmove + "UR "; 
        }
        else if ((row-2 >= 0 ) && (column+2<=7) && (board[row-1][column+1] == "x" || board[row-1][column+1] == "X")&& (board[row-2][column+2] == "."))
        {
            posmove = posmove + "EUR "; //If the piece can eat its opponent on its up-right
        }
      
        if ((row+1<=7) && (column+1 <=7) && board[row+1][column+1] == ".")//If the piece can move down-right
        {
            posmove = posmove + "DR "; 
        }
        else if ((row+2 <= 7) && (column+2<=7) && (board[row+1][column+1] == "x" || board[row+1][column+1] == "X")&& (board[row+2][column+2] == "."))
        {
            posmove = posmove + "EDR "; //If the piece can eat its opponent on its down-right
        }
            
            
        if ((row-1>=0) && (column-1 >=0) && board[row-1][column-1] == ".")//If the piece can move up-left
        {
            posmove = posmove + "UL "; 
        }
        else if ((row-2 >= 0)&&(column-2>=0) && (board[row-1][column-1] == "x" || board[row-1][column-1] == "X")&& (board[row-2][column-2] == "."))
        {
            posmove = posmove + "EUL "; //If the piece can eat its opponent on its up-left
        }
    
        if ((row+1 <=7) && (column-1 >=0) && board[row+1][column-1] == ".")//If the piece can move down-left
        {
            posmove = posmove + "DL "; 
        }
        else if ((row+2 <= 7)&&(column-2>=0) && (board[row+1][column-1] == "x" || board[row+1][column-1] == "X")&& (board[row+2][column-2] == "."))
        {
            posmove = posmove + "EDL "; //If the piece can eat its opponent on its down-left
            
        }
    
    }
   
    return posmove;
}