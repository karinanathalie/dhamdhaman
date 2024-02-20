#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include "Posmove.h" // for Posmove()
#include "vsComp.h"
using namespace std;

/*
randomMove() function will randomise the possible moves of the Comp player but it will prioritise 
moves that kill/eat opponent by returning that move directly
*/

string randomMove(string moves) { 
    int length = 0, index = 0, j=0;
    string move;

    while (j<moves.length()){
        if(moves[j]=='U'||moves[j]=='E'||moves[j]=='D'){
            if (moves[j]=='E'){   // prioritise moves that kill/eat opponent for "smarter" playing
                return (moves.substr(j,3));
            }
            length++;
        }
        j++;
    }
    
    istringstream allMoves(moves);
    string *ptrmove = new string[length];
    while (allMoves >> move)
    {
        ptrmove[index] = move;
        index++;   
    }
    srand(time(0));        // use current time as the seed for random generation of numbers
    int N = length, random;    
    random = rand() % N;   // generate random numbers from 0 to (N-1) for the index of the possible moves
    move = ptrmove[random];
    delete [] ptrmove;     // release memory used for array of possible moves
    ptrmove = NULL;
    return move;

}

/*
randomPiece() function is to get the pieces that can move within the Comp's turn and it will prioritise 
the piece that can kill/eat the opponent so it will be harder for the player to win by returning that piece
otherwise a random piece will be returned
*/
string randomPiece(string board[][8]) {   
    // check all the o and O pieces in the board as Comp player has "O" pieces
    int x, i, j, random;
    string indexZero[8] = {"A", "B", "C", "D", "E", "F", "G", "H"};
    string temp = "", word, piece;
    for (i=0; i<8; i++) {
        for (j=0; j<8; j++) {
            string moves= Posmove(board,i,j);
            if ((board[i][j] == "o" || board[i][j] == "O") && (moves.length()!= 0)) {
                if (moves.find("E")!=-1){
                    return (indexZero[j] + to_string(8-i));
                }
                // if the piece can move, input into string
                temp += (indexZero[j] + to_string(8-i))+" ";
                x += 1;   // for the initialisation of array
            }
        }    
    }
    i = 0;
    string *pieces = new string[x];  // allocating memory from heap memory
    istringstream words(temp);
    while (words >> word) {        // insert the possible indexes to an array
        pieces[i] = word;
        i++;
    }

    // randomise the pieces
    srand(time(0));        // use current time as seed for random generation
    random = rand() % x;   // generate random numbers from 0 to (x-1) for the index of the possible pieces
    piece = pieces[random];
    delete [] pieces;      // release the memory allocated to pieces array
    pieces = NULL;
    return piece;
}