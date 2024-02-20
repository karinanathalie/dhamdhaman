#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <cstdlib>
#include "Posmove.h"
#include "CheckWin.h"
#include "printboard.h"
#include "checkmate.h"
#include "play.h"
#include "historynotes.h"
#include "vsComp.h"
#include "playvscomp.h"
using namespace std;

/* this function works like play function from play.cpp
The only difference is PLAYER2 is replaced by COMP
for more decription regarding how COMP works, check line 170-186 
This will return the winning player
*/

string playvscomp()
{   
    string move, moves, piece, player; // move is userinput, moves = Posmove, piece is biji userinput
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

        if (turn == true)                     // player's turn
        {
            player = "PLAYER";
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
            if ((CheckWin(turn, board)==true) || (checkMate(board,"o") == true)){
                printboard(board);
                return (player);
            }

            if (check_stack(board,"x"))
            {
                turn = false;
            }
            cout << endl;
            if (move[0] == 'E' && turn == true)
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
                    if ((CheckWin(turn, board)==true) || (checkMate(board,"o") == true)){
                        printboard(board);
                        return (player);
                    }
                    appendhistory(player, move, piece);
                    if (check_stack(board,"x"))
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
            turn = false;
        }

        else if (turn == false) // change to COMP's turn
        {
            player = "COMP";
            piece = randomPiece(board); //generate a random and valid piece
            cout << player << "'s turn. "<< player << " chose "<< piece <<endl; //stating COMP's piece choice
            char arr[piece.length()];           
            for (int i = 0; i<piece.length();i++)
            {
                arr[i] = piece[i];    
            }
            column = arr[0] - 'A';
            row = arr[1] - '0';
            row = 8-row;
            moves = Posmove(board, row, column); //generating possible moves for the piece of choice
            move = randomMove(moves); //generate a random move from moves, will choose to terminate the opponent, if there's a possibilities
            cout << player << " made a "<< move << " move."<<endl; //stating COMP's move choice
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
                    moves = Posmove(board, row, column);
                    move = randomMove(moves);
                    cout << player << " made a "<< move << " move."<<endl;
                    movement(board,move,row,column);
                    if ((CheckWin(turn, board)==true) || checkMate(board,"x") == true){
                        printboard(board);
                        return (player);
                    }
                    printboard(board);
                    appendhistory(player, move, piece);
                    if (check_stack(board,"o"))
                    {
                        break;
                    }
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
            turn = true;        
        }
    }
}