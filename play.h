#ifndef PLAY_H
#define PLAY_H
#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include "Posmove.h"
#include "CheckWin.h"
#include "printboard.h"
#include "historynotes.h"
#include "checkmate.h" 
using namespace std;

void invalidInput(bool &pieceValidity, string piece);
bool check_stack(string board[][8], string player);
void movement(string board[][8], string move, int row, int column);
string kill_moves(string board[][8], int row, int column);
bool invalidMove(string moves, string move);
string play();

#endif