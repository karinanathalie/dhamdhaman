#ifndef HISTORYNOTES_H
#define HISTORYNOTES_H
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;
void appendhistory(string player, string move, string piece);
void historywin(string player);
void write_history();
void output_history();
#endif