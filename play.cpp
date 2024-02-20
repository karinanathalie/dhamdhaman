#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include "Posmove.h"
#include "CheckWin.h"
#include "printboard.h"
#include "checkmate.h"
#include "play.h"
#include "historynotes.h"

using namespace std;

void invalidInput(bool &pieceValidity, string piece) //This function checks if the piece inputted by player is invalid
{                                                     
    int number=0;
    if (piece.length() == 2) 
    {
    	if (isdigit(piece[1]) && isupper(piece[0])) 
	{
	    number = piece[1] - '0';
            if (piece[0] >= 'A' && piece[0] <= 'H' && number>=1 && number<=8) 	
	    {
	        pieceValidity = true;
	        return;
	    }
	}
    }
    pieceValidity = false;
    return;
}
//The parameter of this function is string player, which can only contain either x or o
bool check_stack(string board[][8], string player) //This function checks whether a piece lands on the other side,if it does the piece stacks
                                                  
{

    if (player == "x")
    {
        for (int i=0; i<8 ;i++)
        {
            if (board[0][i] == "x")
            {
                board[0][i] = "X";
                return true;
                
            }
        }   
    }
    else if (player == "o")
    {
        for (int i=0; i<8 ;i++)
        {
            if (board[7][i] == "o")
            {
                board[7][i] = "O";
                return true;
                
            }
        }  
    }
    return false;
}
void movement(string board[][8], string move, int row, int column) //Update the contents of the board array when a movement(input) has been made such as DR DL
                                                                  
{ 
    
    if (move == "UR") 
    {
        board[row-1][column+1] = board[row][column];
        board[row][column] = ".";
    }

    else if(move == "UL") 
    {
        board[row-1][column-1] = board[row][column];
        board[row][column] = ".";
    }
    else if (move == "DR")
    {
        board[row+1][column+1] = board[row][column];
        board[row][column] = ".";  
    }
    else if (move == "DL")
    {
        board[row+1][column-1] = board[row][column];
        board[row][column] = ".";
    }
    else if (move == "EUR")
    {
        board[row-2][column+2] = board[row][column];
        board[row-1][column+1] = ".";
        board[row][column] = ".";
    
    }
    else if (move == "EUL")
    {
        board[row-2][column-2] = board[row][column];
        board[row-1][column-1] = ".";
        board[row][column] = ".";
        
    }
    else if (move == "EDR")
    {
        board[row+2][column+2] = board[row][column];
        board[row+1][column+1] = ".";
        board[row][column] = ".";
        
    }
    else if(move == "EDL")
    {
        board[row+2][column-2] = board[row][column];
        board[row+1][column-1] = ".";
        board[row][column] = ".";
    }

}
// kill_moves(...) function returns a string of all available eat moves.
// The parameters are the row and column, which are the indexes of the array
string kill_moves(string board[][8], int row, int column)// This function returns string of Possible kill moves.
                                                         // It is essentially the same as Posmove function but this is used
                                                         // special cases.
{
    string E_moves = "";// E_moves is short for "Eat Moves"

    if (board[row][column] == "x")
    {    
                
        if((row-2>=0)&&(column+2<=7) && (board[row-1][column+1] == "o" || board[row-1][column+1] == "O" ) && board[row-2][column+2] == ".")
        {
            E_moves = E_moves + "EUR ";
        }
        if(((row-2>=0)&&(column-2>=0) && board[row-1][column-1] == "o" || board[row-1][column-1] == "O") && board[row-2][column-2] == ".")
        {
            E_moves = E_moves + "EUL ";
        }     
        
    }
    else if (board[row][column] == "o")
    {
          
        if(((row+2<=7)&&(column+2<=7) && board[row+1][column+1] == "x" || board[row+1][column+1] == "X") && board[row+2][column+2] == ".")
        {
            //down+right makan
            E_moves = E_moves + "EDR ";
        }
            
        if((row+2<=7)&&(column-2>=0) && (board[row+1][column-1] == "x" || board[row+1][column-1] == "X") && board[row+2][column-2] == ".")
        {
            // down+left makan 
            E_moves = E_moves + "EDL ";
        }
    }
    else if (board[row][column] == "X")
    {

        if ((row-2 >= 0 ) && (column+2<=7) && (board[row-1][column+1] == "o" || board[row-1][column+1] == "O") && (board[row-2][column+2] == "."))
        {
            E_moves = E_moves + "EUR ";
        }
      
        if ((row+2 <= 7) && (column+2<=7) && (board[row+1][column+1] == "o" || board[row+1][column+1] == "O") && (board[row+2][column+2] == "."))
        {
            E_moves = E_moves + "EDR ";
        }
            
        if ((row-2 >= 0) && (column-2>=0) && (board[row-1][column-1] == "o" || board[row-1][column-1] == "O") && (board[row-2][column-2] == "."))
        {
            E_moves = E_moves + "EUL ";
        }
    

        if ((row+2 <= 7) && (column-2>=0) && (board[row+1][column-1] == "o" || board[row+1][column-1] == "O") && (board[row+2][column-2] == "."))
        {
            E_moves = E_moves + "EDL ";
        }
    }
    else if (board[row][column] == "O")
    {
    
        if ((row-2 >= 0 ) && (column+2<=7) && (board[row-1][column+1] == "x" || board[row-1][column+1] == "X") && (board[row-2][column+2] == "."))
        {
            E_moves = E_moves + "EUR ";
        }
      

        if ((row+2 <= 7) && (column+2<=7) && (board[row+1][column+1] == "x" || board[row+1][column+1] == "X") && (board[row+2][column+2] == "."))
        {
            E_moves = E_moves + "EDR ";
        }
            
        if ((row-2 >= 0) && (column-2>=0) && (board[row-1][column-1] == "x" || board[row-1][column-1] == "X") && (board[row-2][column-2] == "."))
        {
            E_moves = E_moves + "EUL ";
        }
    

        if ((row+2 <= 7) && (column-2>=0) && (board[row+1][column-1] == "x" || board[row+1][column-1] == "X") && (board[row+2][column-2] == "."))
        {
            E_moves = E_moves + "EDL ";
        }
    
    }
    return E_moves;// return all available Eat moves
}

bool invalidMove(string moves, string move){//This function validate the user input until the 
                                            //user inputs correctly
    stringstream ss(moves);
    string word;
    while(ss >> word){
        if(word == move){
            return false;
        }
    }
    return true;
}

string play()
{   
    string move, moves, piece, player = "PLAYER 1"; // move is userinput, moves = Posmove, piece is biji userinput
    bool turn = true; // true for player x, false for player o
    int row, column;  // to store indexes of userinput
    bool rvalue;
    string board[8][8]{
        {"o", " ", "o", " ","o", " ","o", " "},
        {" ","o", " ","o", " ","o", " ","o"},
        {"o", " ", "o", " ","o", " ","o", " "},
        {" ", ".", " ", "."," ", "."," ", "."},
        {".", " ", "."," ", "."," ", "."," "},
        {" ", "x", " ","x", " ","x", " ","x"},
        {"x", " ", "x", " ","x", " ","x", " "},
        {" ", "x", " ","x", " ","x", " ","x"}
    };

    while (true)
    {   
        printboard(board);

        if (turn == true)                     // player x's turn
        {
            player = "PLAYER 1";
            bool pieceValidity = true;
            cout << player << "'s turn. Enter the piece (e.g. 'A1', 'B3', etc.): ";
            cin >> piece;
            invalidInput(pieceValidity, piece);
            while (pieceValidity != true) 
	        {
		        cout << "Invalid input! Please select another piece: ";
		        cin >> piece;
		        invalidInput(pieceValidity, piece);
	        }
            char arr[piece.length()];//From line 231-239, its purpose is to get the indexes of the piece that is selected by the user
            
            for (int i = 0; i<piece.length();i++)
            {
                arr[i] = piece[i];    
            }
            column = arr[0] - 'A';//column stores the index of the "column" of board array
            row = arr[1] - '0';
            row = 8-row;          //row stores the index of the "row" of board array

            moves = Posmove(board,row,column);
            while (moves.length() == 0|| (board[row][column]!="x" && board[row][column]!="X"))
            {
                cout << "Invalid input! Please select another piece: ";
                cin >> piece;
                invalidInput(pieceValidity, piece);
                while (pieceValidity != true) 
	            {
		            cout << "Invalid input! Please select another piece: ";
		            cin >> piece;
		            invalidInput(pieceValidity, piece);
	            }
                char arr[piece.length()];//From line 247-254, its purpose is to get the indexes of the piece that is selected by the user
                for (int i = 0; i<piece.length();i++)
                {
                    arr[i] = piece[i];    
                }
                column = arr[0] - 'A'; //column stores the index of the "column" of board array
                row = arr[1] - '0';
                row = 8-row;           //row stores the index of the "row" of board array
                moves = Posmove(board, row, column);
                // cout << endl;
            }
            cout << "Available Moves: " << moves << endl;
            cout << "Select your move: ";
            cin >> move;
            while(invalidMove(moves, move)){
                cout << "Invalid input! Please select another move: ";
                cin >> move;
            }
            
            movement(board,move,row,column);
            appendhistory(player, move, piece);
            if ((CheckWin(turn, board)==true) || (checkMate(board,"o") == true)){//If one of the conditions is true then
                                                                                 //one of the player wins the game
                printboard(board);
                return (player);
            }
            

            if (check_stack(board,"x"))//It checks if one of the pieces has reached to the other side of the board
            {
                turn = false;
            }
            cout << endl;
            if (move[0] == 'E' && turn == true)
            {
                if (move == "EUL")     //Updates the value of row&column according to the move
                {
                    row = row - 2;
                    column = column - 2;
                }
                else if(move == "EUR")
                {
                    row = row - 2;
                    column = column +2;
                }
                else if(move == "EDR")
                {
                    row = row + 2;
                    column = column + 2;
                }
                else if(move == "EDL")
                {
                    row = row + 2;
                    column = column - 2;
                }

                // column and rows are updated ^^
                string killmove = kill_moves(board, row, column);
                while (killmove.length() !=0) //If the player can kill another piece again
                {
                    printboard(board);
                    cout << player << " may move again!" << endl;
                    cout << "Available Moves: " << killmove << endl;
                    cout << "Select Your move: ";
                    cin >> move;
                    while(invalidMove(killmove, move)){ //Validate the move of user input
                        cout << "Invalid input! Please select another move: ";
                        cin >> move;
                    }
                    movement(board,move,row,column);//If a move has been made, movement function updates the board
                    if ((CheckWin(turn, board)==true) || (checkMate(board,"o") == true)){
                        printboard(board);
                        return (player);
                    }
                    appendhistory(player, move, piece);

                    if (check_stack(board,"x"))//If the piece has reached to the other side
                    {
                        break;
                    }
                    cout << endl;
                    if (move == "EUL") //Updates value of row and column again for further checking
                    {
                        row = row - 2;
                        column = column - 2;
                    }
                    else if(move == "EUR")
                    {
                        row = row - 2;
                        column = column +2;
                    }
                    else if(move == "EDR")
                    {
                        row = row + 2;
                        column = column + 2;
                    }
                    else if(move == "EDL")
                    {
                        row = row + 2;
                        column = column - 2;
                    }
                    killmove = kill_moves(board, row, column);

                    if (killmove.length() == 0)//if the length of killmove is 0, that means the piece
                                               //cannot kill again
                    {
                        break;
                    }
                }
            }
            turn = false;//Player 2's turn
        }

        else if (turn == false)//Same mechanism as Player 1
        {
            player = "PLAYER 2";
            bool pieceValidity = true;
            cout << player << "'s turn. Enter the piece (e.g. 'A1', 'B3', etc.): ";
            cin >> piece;
            invalidInput(pieceValidity, piece);
            while (pieceValidity != true) 
	        {
	            cout << "Invalid input! Please select another piece: ";
	            cin >> piece;
	            invalidInput(pieceValidity, piece);
            }
            char arr[piece.length()];
            
            for (int i = 0; i<piece.length();i++)
            {
                arr[i] = piece[i];    
            }
            column = arr[0] - 'A';
            row = arr[1] - '0';
            row = 8-row;

            moves = Posmove(board,row,column);
            while (moves.length() == 0|| (board[row][column]!="o" && board[row][column]!="O"))
            {
                cout << "Invalid input! Please select another piece: ";
                cin >> piece;
                invalidInput(pieceValidity, piece);
                while (pieceValidity != true) 
	            {
	                cout << "Invalid input! Please select another piece: ";
	                cin >> piece;
	                invalidInput(pieceValidity, piece);
                }
                char arr[piece.length()];           
                for (int i = 0; i<piece.length();i++)
                {
                    arr[i] = piece[i];    
                }
                column = arr[0] - 'A';
                row = arr[1] - '0';
                row = 8-row;
                moves = Posmove(board, row, column);
            }
            cout << "Available Moves: " << moves << endl;
            cout << "Select your move: ";
            cin >> move;
            while(invalidMove(moves, move)){
                cout << "Invalid input! Please select another move: ";
                cin >> move;
            }
        
            movement(board,move,row,column);
            appendhistory(player, move, piece);
            if ((CheckWin(turn, board)==true) || checkMate(board,"x") == true){
                printboard(board);
                return (player);
            }

            if (check_stack(board,"o"))
            {
                turn = false;
            }
            // printboard(board);
            cout << endl;
            if (move[0] == 'E' && turn == false)
            {
                if (move == "EUL")
                {
                    row = row - 2;
                    column = column - 2;
                }
                else if(move == "EUR")
                {
                    row = row - 2;
                    column = column +2;
                }
                else if(move == "EDR")
                {
                    row = row + 2;
                    column = column + 2;
                }
                else if(move == "EDL")
                {
                    row = row + 2;
                    column = column - 2;
                }

                // column and rows are updated ^^
                string killmove = kill_moves(board, row, column);
                while (killmove.length() !=0)
                {
                    printboard(board);
                    cout << player << " may move again!" << endl;
                    cout << "Available Moves: " << killmove << endl;
                    cout << "Select Your move: ";
                    cin >> move;
                    while(invalidMove(killmove, move)){
                        cout << "Invalid input! Please select another move: ";
                        cin >> move;
                    }
                    movement(board,move,row,column);
                    if ((CheckWin(turn, board)==true) || checkMate(board,"x") == true){
                        printboard(board);
                        return (player);
                    }
                    appendhistory(player, move, piece);
                    if (check_stack(board,"o"))
                    {
                        break;
                    }
                    // printboard(board);
                    cout << endl;
                    if (move == "EUL")
                    {
                        row = row - 2;
                        column = column - 2;
                    }
                    else if(move == "EUR")
                    {
                        row = row - 2;
                        column = column +2;
                    }
                    else if(move == "EDR")
                    {
                        row = row + 2;
                        column = column + 2;
                    }
                    else if(move == "EDL")
                    {
                        row = row + 2;
                        column = column - 2;
                    }
                    killmove = kill_moves(board, row, column);

                    if (killmove.length() == 0)
                    {
                        break;
                    }
                }
            }
            turn = true;//Player 1's turn      
        }
    }
}